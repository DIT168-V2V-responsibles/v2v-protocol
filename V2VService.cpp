#include "V2VService.hpp"

int main() {
    std::shared_ptr<V2VService> v2vService = std::make_shared<V2VService>();

    while (1) {
        int choice;
        std::cout << "Which message would you like to send?" << std::endl;
        std::cout << "(1) AnnouncePresence" << std::endl;
        std::cout << "(2) FollowRequest" << std::endl;
        std::cout << "(3) FollowResponse" << std::endl;
        std::cout << "(4) StopFollow" << std::endl;
        std::cout << "(5) LeaderStatus" << std::endl;
        std::cout << "(6) FollowerStatus" << std::endl;
        std::cout << "(#) Nothing, just quit." << std::endl;
        std::cout << ">> ";
        std::cin >> choice;

        switch (choice) {
            case 1: v2vService->announcePresence(); break;
            case 2: v2vService->followRequest(DEMO_CAR_IP); break;
            case 3: v2vService->followResponse(); break;
            case 4: v2vService->stopFollow(DEMO_CAR_IP); break;
            case 5: v2vService->leaderStatus(50, 0, 100); break;
            case 6: v2vService->followerStatus(50, 0, 10, 100); break;
            default: exit(0);
        }
    }
}

V2VService::V2VService() {
    broadcast =
        std::make_shared<cluon::OD4Session>(BROADCAST_CHANNEL,
          [this](cluon::data::Envelope &&envelope) noexcept {
              std::cout << "[OD4] ";
              switch (envelope.dataType()) {
                  case ANNOUNCE_PRESENCE: {
                      AnnouncePresence ap = cluon::extractMessage<AnnouncePresence>(std::move(envelope));
                      std::cout << "received 'AnnouncePresence' from '"
                                << ap.vehicleIp() << ":" << ap.activePort() << "', GroupID '"
                                << ap.groupId() << "'!" << std::endl;

                      /* TODO: monitor these IPs so you know which ones to choose from */

                      break;
                  }
                  default: std::cout << "¯\\_(ツ)_/¯" << std::endl;
              }
          });

    incoming =
        std::make_shared<cluon::UDPReceiver>("0.0.0.0", DEFAULT_PORT,
           [this](std::string &&data, std::string &&sender, std::chrono::system_clock::time_point &&ts) noexcept {
               std::cout << "[UDP] ";
               std::pair<int16_t, std::string> msg = extract(data);
               switch (msg.first) {
                   case FOLLOW_REQUEST: {
                       FollowRequest followRequest = decode<FollowRequest>(msg.second);
                       std::cout << "received '" << followRequest.LongName()
                                 << "' from '" << sender << "'!" << std::endl;

                       if (followerIp.empty()) {
                           followerIp = sender;
                           toFollower = std::make_shared<cluon::UDPSender>(followerIp, DEFAULT_PORT);
                           followResponse();
                       }
                       break;
                   }
                   case FOLLOW_RESPONSE: {
                       FollowResponse followResponse = decode<FollowResponse>(msg.second);
                       std::cout << "received '" << followResponse.LongName()
                                 << "' with NTPServerIP '" << followResponse.ntpServerIp()
                                 << "' from '" << sender << "'!" << std::endl;

                       /* TODO: implement NTP synchronisation */

                       break;
                   }
                   case STOP_FOLLOW: {
                       StopFollow stopFollow = decode<StopFollow>(msg.second);
                       std::cout << "received '" << stopFollow.LongName()
                                 << "' from '" << sender << "'!" << std::endl;

                       if (sender == followerIp) {
                           followerIp = "";
                           toFollower.reset();
                       }
                       else if (sender == leaderIp) {
                           leaderIp = "";
                           toLeader.reset();
                       }
                       break;
                   }
                   case FOLLOWER_STATUS: {
                       FollowerStatus followerStatus = decode<FollowerStatus>(msg.second);
                       std::cout << "received '" << followerStatus.LongName()
                                 << "' from '" << sender << "'!" << std::endl;

                       /* TODO: implement lead logic (if applicable) */

                       break;
                   }
                   case LEADER_STATUS: {
                       LeaderStatus leaderStatus = decode<LeaderStatus>(msg.second);
                       std::cout << "received '" << leaderStatus.LongName()
                                 << "' from '" << sender << "'!" << std::endl;

                       /* TODO: implement follow logic */

                       break;
                   }
                   default: std::cout << "¯\\_(ツ)_/¯" << std::endl;
               }
           });
}

void V2VService::announcePresence() {
    if (!followerIp.empty()) return;
    AnnouncePresence announcePresence;
    announcePresence.vehicleIp(DEMO_CAR_IP);
    announcePresence.activePort(DEFAULT_PORT);
    announcePresence.groupId(DEMO_GROUP_ID);
    broadcast->send(announcePresence);
}

void V2VService::followRequest(std::string vehicleIp) {
    if (!leaderIp.empty()) return;
    leaderIp = vehicleIp;
    toLeader = std::make_shared<cluon::UDPSender>(leaderIp, DEFAULT_PORT);
    FollowRequest followRequest;
    toLeader->send(encode(followRequest));
}

void V2VService::followResponse() {
    if (followerIp.empty()) return;
    FollowResponse followResponse;
    followResponse.ntpServerIp(DEMO_NTP_IP);
    toFollower->send(encode(followResponse));
}

void V2VService::stopFollow(std::string vehicleIp) {
    StopFollow stopFollow;
    if (vehicleIp == leaderIp) toLeader->send(encode(stopFollow));
    else if (vehicleIp == followerIp) toFollower->send(encode(stopFollow));
}

void V2VService::followerStatus(uint8_t speed, uint8_t steeringAngle, uint8_t distanceFront,
                                uint8_t distanceTraveled) {
    if (leaderIp.empty()) return;
    FollowerStatus followerStatus;
    followerStatus.timestamp(getTime());
    followerStatus.speed(speed);
    followerStatus.steeringAngle(steeringAngle);
    followerStatus.distanceFront(distanceFront);
    followerStatus.distanceTraveled(distanceTraveled);
    toLeader->send(encode(followerStatus));
}

void V2VService::leaderStatus(uint8_t speed, uint8_t steeringAngle, uint8_t distanceTraveled) {
    if (followerIp.empty()) return;
    LeaderStatus leaderStatus;
    leaderStatus.timestamp(getTime());
    leaderStatus.speed(speed);
    leaderStatus.steeringAngle(steeringAngle);
    leaderStatus.distanceTraveled(distanceTraveled);
    toFollower->send(encode(leaderStatus));
}

uint32_t V2VService::getTime() {
    timeval now;
    gettimeofday(&now, nullptr);
    return (uint32_t ) now.tv_usec / 1000;
}

std::pair<int16_t, std::string> V2VService::extract(std::string data) {
    if (data.length() < 10) return std::pair<int16_t, std::string>(-1, "");
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
