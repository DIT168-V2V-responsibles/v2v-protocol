# DIT 168 V2V protocol proposal

This repo contains a V2V communication protocol between autonomous RCs with a focus on platooning. The RCs' specs can be found [here](https://github.com/chalmers-revere/opendlv.scaledcars).

### Table of contents

1. ##### [Installation](https://github.com/DIT168-V2V-responsibles/v2v-protocol#1-installation)
2. ##### [Get started](https://github.com/DIT168-V2V-responsibles/v2v-protocol#2-get-started)
3. ##### [License](https://github.com/DIT168-V2V-responsibles/v2v-protocol#3-license)
4. ##### [Requests](https://github.com/DIT168-V2V-responsibles/v2v-protocol#4-requests)

### 1. Installation
To install libcluon please refer to the installation guide [Libcluon](https://https://github.com/chrberger/libcluon)

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
Libcluon library can be found at https://github.com/chrberger/libcluon

### 4. Protocol Requests 
This section describes the the the protocol requests. Fields of requests and their types are denoted: Type field name.

#### 4.1 Common Requests

##### Announce Presence
This message is intended as a way of letting cars in the network know about each other. Each car should sent an Announce Presence when joining a platoon. Different channels are used to distinguish between different platoons. No reply from the cars is required.

***Fields***
* unit8_t channel - A unique identifier of the car sending the follow announcement.

##### Follow Request  
This message is sent to a channel when a car is attempting to initiate following. This message requires a response i.e. Follow Response. 

***Fields***
* unit8_t carId - A unique identifier of the car that initiated the following.

##### Follow Response
This message is sent in response to a Follow Request. The message returns the identifier of the car at the last position of the platoon and the car ID that originally initiated the following.

***Fields***
* unit8_t meantForCar - A unique identifier of the car that initiated the following.
* unit8_t carToFollow - A unique identifier of the final car within the platoon line.

##### Emergency Brake
This message is sent in order to stop the cars from moving. The request is used to avoid any collision and possible damage between the cars. No reply from the cars is required.

***Fields***
* unit8_t speed - A speed value of 0, used to stop the cars.

#### 4.2 Leader Specific Requests

##### Status Update
This message includes information about a leading vehicle and contains information relevant for a following car to be able to follow it. This message does not expect a response.

***Fields***
* unit8_t speed - Current speed of the leading vehicle
* unit8_t steering - Current steering angle of the leading vehicle

#### 4.3 Follower Specific Requests

##### Status Update
This message includes information about a following vehicle and contains information relevant for a leading car. This message does not expect a response.

***Fields***
* unit8_t speed - Current speed of the leading vehicle
* unit8_t steering - Current steering angle of the leading vehicle
* unit8_t distance - Current distance to the car being followed

##### Stop Following Request
This message is sent by a car to indicate that following must come to an end. both the leading and the following vehicles are able to send this request. This message does not expect a response.

***Fields***
* unit8_t carInFront - A unique identifier of the car that will no longer be followed.