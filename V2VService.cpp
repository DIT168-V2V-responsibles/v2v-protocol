#include <iomanip>
#include "V2VService.hpp"
#include "cluon/ToJSONVisitor.hpp"
#include "cluon/MessageParser.hpp"
#include "cluon/GenericMessage.hpp"

int main() {
    new V2VService();
    while (true) { /* meh. */ }
}

V2VService::V2VService() {
    broadcast =
        std::make_shared<cluon::OD4Session>(BROADCAST_CHANNEL,
          [](cluon::data::Envelope &&envelope) noexcept {
              std::cout << "[OD4] ";
              switch (envelope.dataType()) {
                  case ANNOUNCE_PRESENCE: {
                      AnnouncePresence ap = cluon::extractMessage<AnnouncePresence>(std::move(envelope));
                      std::cout << "received 'AnnouncePresence' from '"
                                << ap.vehicleIp() << ":" << ap.activePort()
                                << "'!" << std::endl;
                      break;
                  }
                  default: std::cout << "¯\\_(ツ)_/¯" << std::endl;
              }
          });

    incoming =
        std::make_shared<cluon::UDPReceiver>("0.0.0.0", DEFAULT_PORT,
           [](std::string &&data, std::string &&sender, std::chrono::system_clock::time_point &&ts) noexcept {
               std::cout << "[UDP] ";
               std::pair<int16_t, std::string> msg = V2VService::extract(data);
               switch (msg.first) {
                   case FOLLOW_REQUEST: {
                       FollowRequest followRequest = decode<FollowRequest>(msg.second);
                       std::cout << "received '" << followRequest.LongName()
                                 << "' from '" << sender << "'!" << std::endl;
                       break;
                   }
                   case FOLLOW_RESPONSE: {
                       FollowResponse followResponse = decode<FollowResponse>(msg.second);
                       std::cout << "received '" << followResponse.LongName()
                                 << "' with NTPServerIP '" << followResponse.ntpServerIp()
                                 << "' from '" << sender << "'!" << std::endl;
                       break;
                   }
                   case STOP_FOLLOW: {
                       StopFollow stopFollow = decode<StopFollow>(msg.second);
                       std::cout << "received '" << stopFollow.LongName()
                                 << "' from '" << sender << "'!" << std::endl;
                       break;
                   }
                   case FOLLOWER_STATUS: {
                       FollowerStatus followerStatus = decode<FollowerStatus>(msg.second);
                       std::cout << "received '" << followerStatus.LongName()
                                 << "' from '" << sender << "'!" << std::endl;
                       break;
                   }
                   case LEADER_STATUS: {
                       LeaderStatus leaderStatus = decode<LeaderStatus>(msg.second);
                       std::cout << "received '" << leaderStatus.LongName()
                                 << "' from '" << sender << "'!" << std::endl;
                       break;
                   }
                   default: std::cout << "¯\\_(ツ)_/¯" << std::endl;
               }
           });

    AnnouncePresence ap;
    ap.vehicleIp("127.0.0.1");
    ap.activePort(DEFAULT_PORT);
    broadcast->send(ap);

    cluon::UDPSender udp("127.0.0.1", DEFAULT_PORT);
    FollowResponse fr;
    fr.ntpServerIp("127.0.0.1");
    udp.send(encode(fr));
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

std::pair<int16_t, std::string> V2VService::extract(std::string data) {
    int id, len;
    std::stringstream ssId(data.substr(0, 4));
    std::stringstream ssLen(data.substr(4, 10));
    ssId >> std::hex >> id;
    ssLen >> std::hex >> len;
    return std::pair<int16_t, std::string> (
            data.length() -10 == len ? id : -1,
            data.substr(10, data.length() -10)
    );
};

template <class T>
std::string V2VService::encode(T msg) {
    cluon::ToProtoVisitor v;
    msg.accept(v);
    std::stringstream buff;
    buff << std::hex << std::setfill('0')
         << std::setw(4) << msg.ID()
         << std::setw(6) << v.encodedData().length()
         << v.encodedData();
    return buff.str();
}

template <class T>
T V2VService::decode(std::string data) {
    std::stringstream buff(data);
    cluon::FromProtoVisitor v;
    v.decodeFrom(buff);
    T tmp = T();
    tmp.accept(v);
    return tmp;
}
