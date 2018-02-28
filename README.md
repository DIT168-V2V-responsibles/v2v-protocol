# DIT 168 V2V protocol proposal

This repo contains a V2V communication protocol between autonomous RCs with a focus on platooning. The RCs' specs can be found [here](https://github.com/chalmers-revere/opendlv.scaledcars).

### Table of contents

1. ##### [Installation](https://github.com/DIT168-V2V-responsibles/v2v-protocol#1-installation)
2. ##### [Get started](https://github.com/DIT168-V2V-responsibles/v2v-protocol#2-get-started)
3. ##### [License](https://github.com/DIT168-V2V-responsibles/v2v-protocol#3-license)
4. ##### [Requests](https://github.com/DIT168-V2V-responsibles/v2v-protocol#4-requests)

### 1. Installation
Please refer to the installation guide of [Libcluon](https://https://github.com/chrberger/libcluon)

### 2. Get started

Clone the repo using:

`git clone https://github.com/DIT168-V2V-responsibles/v2v-protocol.git`

### 3. License
The protocol is licenced under GNU Lesser General Public License version 3.0. This is due to the incorporation of "libcluon" library as part of the project. Libcluon offers their software under LGPLv 3.0 licence and due to the copyleft nature, anyone who distribute its code or derivative works, are required to make the source available under the same terms. 
Libcluon library can be found at https://github.com/chrberger/libcluon

### 4. Protocol Requests 
This section describes the the the protocol requests. Fields of requests and their types are denoted: Type field name.

#### 4.1 Common Requests

##### Announce Presence
This message is intended as a way of letting cars in the network know about each other. Each car should sent an Announce Presence message as soon as they connect to the network. A car, upon receiving an Announce Presence message, should in turn itself broadcast an Announce Presence message to let the newly connected car know about it too. This message does not expect a response.

***Fields***
* Identifier id - A unique identifier of the car sending the follow announcement.

##### Follow Request
This message is sent explicitly to a car when attempting to initiate following. The car intended to be followed is identified as *target*. This message requires a response, which can come as two different messages; Follow Reject or Follow Accepted. 

***Fields***
* Identifier target - A unique identifier of the target car of the request.

##### Reject Follow
This message is sent as a response to a Follow Request if the car identified in the *target* field of the Follow Request is already being followed. The response in turn sends the unique identifier of the car already following *target*. 

***Fields***
* Identifier nextInLine - A unique identifier of the car already following the target of the Follow Request.

##### Accept Follow
This message is sent in response to a Follow Request when the request was successfully accepted. This is a response to the Follow Request message. The message returns the identifier of the car that being the following.

***Fields***
* Identifier acceptedCar - A unique identifier of the car that accepted the request.

##### Stop Following Request
This message is sent by a car to indicate that following must come to an end. both the leading and the following vehicles are able to send this request. This message does not expect a response.

***Fields***
* Identifier target - A unique identifier of the car that will no longer be followed.

#### 4.2 Leader Specific Requests

##### Status Update
This message includes information about a leading vehicle and contains information relevant for a following car to be able to follow it. This message does not expect a response.

***Fields***
* int speed - Current speed of the leading vehicle
* int steering - Current steering angle of the leading vehicle

#### 4.3 Follower Specific Requests

##### Status Update
This message includes information about a following vehicle and contains information relevant for a leading car. This message does not expect a response.

***Fields***
* int speed - Current speed of the leading vehicle
* int steering - Current steering angle of the leading vehicle
* int distance - Current distance to the car being followed