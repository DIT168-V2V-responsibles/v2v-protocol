#include <cstdint>
#include <chrono>
#include <iostream>
#include <unistd.h>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "Messages.hpp"
#include "V2V.hpp"

class V2VSender {
private:
    cluon::OD4Session *broadcastSession;
    cluon::OD4Session *platoonSession;

public:
    V2VSender() {
        broadcastSession = new cluon::OD4Session(BROADCAST_CHANNEL,
                               [](cluon::data::Envelope /*&&envelope*/) noexcept {});
    }

    void announcePresence(uint8_t channel) {
        AnnouncePresence ap;
        ap.channel(channel);
        broadcastSession->send(ap);
    }

    void followRequest(uint8_t channel, uint8_t carId) {
        platoonSession = new cluon::OD4Session(channel,
                             [](cluon::data::Envelope /*&&envelope*/) noexcept {});
        FollowRequest fr;
        fr.carId(carId);
        platoonSession->send(fr);
    }

    void followResponse(uint8_t carToFollow) {
        if (platoonSession == nullptr) return;
        FollowResponse fr;
        fr.carToFollow(carToFollow);
        platoonSession->send(fr);
    }

    void stopFollow(uint8_t carInFront) {
        if (platoonSession == nullptr) return;
        StopFollow sf;
        sf.carInFront(carInFront);
        platoonSession->send(sf);
        platoonSession = nullptr;
    }

    void emergencyBrake(uint8_t speed) {
        if (platoonSession == nullptr) return;
        EmergencyBrake eb;
        eb.speed(speed);
        platoonSession->send(eb);
    }

    void leaderStatus(uint8_t speed, uint8_t steeringAngle) {
        if (platoonSession == nullptr) return;
        LeaderStatus ls;
        ls.speed(speed);
        ls.steeringAngle(steeringAngle);
        platoonSession->send(ls);
    }

    void followerStatus(uint8_t speed, uint8_t distanceFront) {
        if (platoonSession == nullptr) return;
        FollowerStatus fs;
        fs.speed(speed);
        fs.distanceFront(distanceFront);
        platoonSession->send(fs);
    }
};

int main(int /*argc*/, char ** /*argv*/) {
    V2VSender *sender = new V2VSender();
    while (1) {
        int choice;
        std::cout << "Which message would you like to send?" << std::endl;
        std::cout << "(1) AnnouncePresence" << std::endl;
        std::cout << "(2) FollowRequest" << std::endl;
        std::cout << "(3) FollowResponse" << std::endl;
        std::cout << "(4) StopFollow" << std::endl;
        std::cout << "(5) EmergencyBrake" << std::endl;
        std::cout << "(6) LeaderStatus" << std::endl;
        std::cout << "(7) FollowerStatus" << std::endl;
        std::cout << "(8) Nothing, just quit." << std::endl;
        std::cout << ">> ";
        std::cin >> choice;

        switch (choice) {
            case 1: sender->announcePresence(DEMO_PLATOON_CHANNEL); break;
            case 2: sender->followRequest(DEMO_PLATOON_CHANNEL, DEMO_CAR_ID); break;
            case 3: sender->followResponse(DEMO_CAR_ID); break;
            case 4: sender->stopFollow(DEMO_CAR_ID); break;
            case 5: sender->emergencyBrake(0); break;
            case 6: sender->leaderStatus(50, 0); break;
            case 7: sender->followerStatus(50, 10); break;
            default: exit(0);
        }
    }

}
