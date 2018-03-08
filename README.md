# DIT 168 V2V protocol proposal

This repo contains a V2V communication protocol between autonomous RCs with a focus on platooning. The RCs' specs can be found [here](https://github.com/chalmers-revere/opendlv.scaledcars).

### Table of contents

1. ##### [Installation](https://github.com/DIT168-V2V-responsibles/v2v-protocol#1-installation)
2. ##### [Get started](https://github.com/DIT168-V2V-responsibles/v2v-protocol#2-get-started)
3. ##### [License](https://github.com/DIT168-V2V-responsibles/v2v-protocol#3-license)
4. ##### [Requests](https://github.com/DIT168-V2V-responsibles/v2v-protocol#4-protocol-requests)

### 1. Installation
To install libcluon please refer to the installation guide [Libcluon](https://github.com/chrberger/libcluon).

### 2. Get started

Clone the repo using:
```
git clone https://github.com/DIT168-V2V-responsibles/v2v-protocol.git
```

Make a build folder and navigate into it:
```
mkdir build
cd build
```

Run `cmake` to create the necessary build files:
```
cmake ..
```

Finally compile:
```
make
```

### 3. License
The protocol is licenced under GNU Lesser General Public License version 3.0. This is due to the incorporation of "libcluon" library as part of the project. Libcluon offers their software under LGPLv 3.0 licence and due to the copyleft nature, anyone who distribute its code or derivative works, are required to make the source available under the same terms. 
Libcluon library can be found [here](https://github.com/chrberger/libcluon).

### 4. Protocol Requests 
This section describes the protocol requests. Fields of requests and their types are denoted: Type field name.

#### 4.1 Common Requests

##### Announce Presence
This message is intended for the cars not leading other cars yet, to inform their presence on the network. The Announce Presence holds the IP of the car as a unique identification among all the cars and also the port that followers can connect to, if they choose to follow the car sending Announce Presence message. Moreover, the car also includes the id of the group in the message in order to inform the cars about the group number.

***Fields***
* string   vehicleIp  - IP of the car that sends the announce presence, used as a unique idetifier.
* uint16_t activePort - A unique port that allows followers to connect to the car sending the announcement.
* string   groupId    - The project group number of the group that has the car.

##### Follow Request  
This message is sent to the car that is about to be followed by another car that wants to initiate following. This message requires a response i.e. Follow Response. 

##### Follow Response
This message is sent in response to a Follow Request. The message returns a string containing the IP of the NTP server that the following car is synced to. In order the acquire a better time synchronization between the cars, each vehicle should run its own NTP server.

***Fields***
* string ntpServerIp - A string containing the IP of the NTP server.

##### Stop Follow Request
This message is sent by a car to indicate that following must come to an end. Both the leading and the following vehicles are able to send this request. This message does not expect a response.

#### 4.2 Leader Specific Requests

##### Status Update
This message includes information about a leading vehicle and contains information relevant for a following car to be able to follow it. The LeaderStatus is sent in regular intervals of 125ms. Also, a new status update will be sent if a sudden change in speed (>0.1 pedal position) or steering angle (>5°) occurs. This message does not expect a response.

***Fields***
* unit32_t timestamp       - The time stamp (the time that the message has been sent) of the leading vehicle.
* uint8_t  speed           - Current speed of the leading vehicle.
* uint8_t steeringAngle    - Current steering angle of the leading vehicle.
* unit8_t distanceTraveled - The distance travelled since the last status update (according the odometer).

#### 4.3 Follower Specific Requests

##### Status Update
This message includes information about a following vehicle and contains information relevant for a leading car. The FollowerStatus is sent in regular intervals of 125ms. Also, a new status update will be sent if a sudden change in speed (>0.1 pedal position) or steering angle (>5°) occurs. This message does not expect a response.

***Fields***
* unit32_t timestamp       - A time stamp (the time that the message has been sent) for the following vehicle.
* uint8_t speed            - Current speed of the following vehicle.
* uint8_t steeringAngle    - Current steering angle of the following vehicle.
* uint8_t distanceFront    - Current distance to the vehicle being followed (according to ultrasonic sensor).
* unit8_t distanceTraveled - The distance travelled since the last status update (according the odometer).
