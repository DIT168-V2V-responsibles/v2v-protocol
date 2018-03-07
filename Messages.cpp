#include <Messages.hpp>

/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */


uint32_t AnnouncePresence::ID() {
    return 1001;
}

const std::string AnnouncePresence::ShortName() {
    return "AnnouncePresence";
}
const std::string AnnouncePresence::LongName() {
    return "AnnouncePresence";
}

AnnouncePresence& AnnouncePresence::vehicleIp(const std::string &v) noexcept {
    m_vehicleIp = v;
    return *this;
}
std::string AnnouncePresence::vehicleIp() const noexcept {
    return m_vehicleIp;
}

AnnouncePresence& AnnouncePresence::activePort(const uint16_t &v) noexcept {
    m_activePort = v;
    return *this;
}
uint16_t AnnouncePresence::activePort() const noexcept {
    return m_activePort;
}



#include <Messages.hpp>

/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */


uint32_t FollowRequest::ID() {
    return 1002;
}

const std::string FollowRequest::ShortName() {
    return "FollowRequest";
}
const std::string FollowRequest::LongName() {
    return "FollowRequest";
}



#include <Messages.hpp>

/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */


uint32_t FollowResponse::ID() {
    return 1003;
}

const std::string FollowResponse::ShortName() {
    return "FollowResponse";
}
const std::string FollowResponse::LongName() {
    return "FollowResponse";
}

FollowResponse& FollowResponse::ntpServerIp(const std::string &v) noexcept {
    m_ntpServerIp = v;
    return *this;
}
std::string FollowResponse::ntpServerIp() const noexcept {
    return m_ntpServerIp;
}



#include <Messages.hpp>

/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */


uint32_t StopFollow::ID() {
    return 1004;
}

const std::string StopFollow::ShortName() {
    return "StopFollow";
}
const std::string StopFollow::LongName() {
    return "StopFollow";
}



#include <Messages.hpp>

/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */


uint32_t LeaderStatus::ID() {
    return 2001;
}

const std::string LeaderStatus::ShortName() {
    return "LeaderStatus";
}
const std::string LeaderStatus::LongName() {
    return "LeaderStatus";
}

LeaderStatus& LeaderStatus::timestamp(const uint32_t &v) noexcept {
    m_timestamp = v;
    return *this;
}
uint32_t LeaderStatus::timestamp() const noexcept {
    return m_timestamp;
}

LeaderStatus& LeaderStatus::speed(const uint8_t &v) noexcept {
    m_speed = v;
    return *this;
}
uint8_t LeaderStatus::speed() const noexcept {
    return m_speed;
}

LeaderStatus& LeaderStatus::steeringAngle(const uint8_t &v) noexcept {
    m_steeringAngle = v;
    return *this;
}
uint8_t LeaderStatus::steeringAngle() const noexcept {
    return m_steeringAngle;
}

LeaderStatus& LeaderStatus::distanceTraveled(const uint8_t &v) noexcept {
    m_distanceTraveled = v;
    return *this;
}
uint8_t LeaderStatus::distanceTraveled() const noexcept {
    return m_distanceTraveled;
}



#include <Messages.hpp>

/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */


uint32_t FollowerStatus::ID() {
    return 3001;
}

const std::string FollowerStatus::ShortName() {
    return "FollowerStatus";
}
const std::string FollowerStatus::LongName() {
    return "FollowerStatus";
}

FollowerStatus& FollowerStatus::timestamp(const uint32_t &v) noexcept {
    m_timestamp = v;
    return *this;
}
uint32_t FollowerStatus::timestamp() const noexcept {
    return m_timestamp;
}

FollowerStatus& FollowerStatus::speed(const uint8_t &v) noexcept {
    m_speed = v;
    return *this;
}
uint8_t FollowerStatus::speed() const noexcept {
    return m_speed;
}

FollowerStatus& FollowerStatus::steeringAngle(const uint8_t &v) noexcept {
    m_steeringAngle = v;
    return *this;
}
uint8_t FollowerStatus::steeringAngle() const noexcept {
    return m_steeringAngle;
}

FollowerStatus& FollowerStatus::distanceFront(const uint8_t &v) noexcept {
    m_distanceFront = v;
    return *this;
}
uint8_t FollowerStatus::distanceFront() const noexcept {
    return m_distanceFront;
}

FollowerStatus& FollowerStatus::distanceTraveled(const uint8_t &v) noexcept {
    m_distanceTraveled = v;
    return *this;
}
uint8_t FollowerStatus::distanceTraveled() const noexcept {
    return m_distanceTraveled;
}



