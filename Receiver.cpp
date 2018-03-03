#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "Messages.hpp"
#include "V2V.hpp"

class V2VReceiver {
private:
    cluon::OD4Session *platoonSession;

public:
    V2VReceiver() {
        new cluon::OD4Session(BROADCAST_CHANNEL,
          [](cluon::data::Envelope &&envelope) noexcept {
              switch (envelope.dataType()) {
                  case ANNOUNCE_PRESENCE:    /*...*/
                  default: std::cout << "unknown message on the broadcastSession!" << std::endl; break;
              }
          });
    }

    void joinPlatoon(uint8_t channel) {
        if (platoonSession != nullptr) platoonSession = nullptr;
        platoonSession = new cluon::OD4Session(channel,
           [](cluon::data::Envelope &&envelope) noexcept {
               switch (envelope.dataType()) {
                   case ANNOUNCE_PRESENCE:  /*...*/
                   case FOLLOW_REQUEST:     /*...*/
                   case FOLLOW_RESPONSE:    /*...*/
                   case STOP_FOLLOW:        /*...*/
                   case EMERGENCY_BRAKE:    /*...*/
                   case LEADER_STATUS:      /*...*/
                   case FOLLOWER_STATUS:    /*...*/
                   default: std::cout << "unknown message on the platoonSession!" << std::endl; break;
               }
           });
    }
};

int main(int /*argc*/, char ** /*argv*/) {
    V2VReceiver *receiver = new V2VReceiver();
    receiver->joinPlatoon(DEMO_PLATOON_CHANNEL);
    
    using namespace std::chrono_literals; 
    while (1) {
        std::this_thread::sleep_for(250ms);
    }
}
