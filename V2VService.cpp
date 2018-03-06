//
// Created by julian on 3/6/18.
//

#include <iomanip>
#include "V2VService.hpp"

V2VService::V2VService() {
    this->broadcast =
            std::make_shared<cluon::OD4Session>(BROADCAST_CHANNEL,
                                                          [](cluon::data::Envelope &&envelope) noexcept {
                                                              switch (envelope.dataType()) {
                                                                  case ANNOUNCE_PRESENCE:    /*...*/
                                                                  default: std::cout << "unknown message on the broadcastSession!" << std::endl; break;
                                                              }
                                                          });

    this->inbound =
            std::make_shared<cluon::UDPReceiver>("127.0.0.1", 1234,
                               [](std::string &&data, std::string &&sender, std::chrono::system_clock::time_point &&ts) noexcept {
                                   const auto timestamp(std::chrono::system_clock::to_time_t(ts));
                                   std::cout << "Received " << data.size() << " bytes"
                                             << " from " << sender
                                             << " at " << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %X")
                                             << ", containing '" << data << "'." << std::endl;
                               });

    cluon::UDPSender sender("127.0.0.1", 1234);
    std::pair<ssize_t, int32_t> retVal = sender.send(std::move("Hello World!"));
}

void V2VService::announcePresence() {

}

void V2VService::followRequest(std::string leader) {

}

void V2VService::followResponse() {

}

void V2VService::stopFollow() {

}

void V2VService::followerStatus(uint8_t speed, uint8_t steeringAngle, uint8_t distanceFront,
                                uint8_t distanceTraveled) {

}

void V2VService::leaderStatus(uint8_t speed, uint8_t steeringAngle, uint8_t distanceTraveled) {

}

int main() {
    V2VService *s = new V2VService();
    while (true) { /* meh. */ }
    return 0;
}