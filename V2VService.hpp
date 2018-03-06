//
// Created by julian on 3/6/18.
//

#ifndef V2V_PROTOCOL_DEMO_V2VSERVICE_H
#define V2V_PROTOCOL_DEMO_V2VSERVICE_H

#include "cluon/OD4Session.hpp"
#include "cluon/UDPSender.hpp"
#include "cluon/UDPReceiver.hpp"
#include "cluon/Envelope.hpp"
#include "Messages.hpp"

static const int DEMO_CAR_ID = 123;

static const int BROADCAST_CHANNEL = 200;
static const int DEFAULT_PORT = 50001;

static const int ANNOUNCE_PRESENCE = 1001;
static const int FOLLOW_REQUEST = 1002;
static const int FOLLOW_RESPONSE = 1003;
static const int STOP_FOLLOW = 1004;
static const int LEADER_STATUS = 2001;
static const int FOLLOWER_STATUS = 3001;

class V2VService {
public:
    V2VService();

    void announcePresence();
    void followRequest(std::string leader);
    void followResponse();
    void stopFollow();
    void leaderStatus(uint8_t speed, uint8_t steeringAngle, uint8_t distanceTraveled);
    void followerStatus(uint8_t speed, uint8_t steeringAngle, uint8_t distanceFront, uint8_t distanceTraveled);

private:
    std::string leaderIp;
    std::string followerIp;

    std::shared_ptr<cluon::OD4Session>  broadcast;
    std::shared_ptr<cluon::UDPReceiver> inbound;
    std::shared_ptr<cluon::UDPSender>   outboundLeader;
    std::shared_ptr<cluon::UDPSender>   outboundFollower;
};

#endif //V2V_PROTOCOL_DEMO_V2VSERVICE_H
