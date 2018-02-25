# Protocol suggestion

## Requests/Reponses

Fields of requests and their types are denoted: Type field name.

### Announce Presence
This message is intended as a way of letting cars in the network know about each other. Each car should sent an Announce Presence message as soon as they connect to the network. A car, upon receiving an Announce Presence message, should in turn itself broadcast an Announce Presence message to let the newly connected car know about it too. This message does not expect a response.

**Fields**
* Identifier identifier - A unique identifier for the car sending the announcement.

### Follow Request
This message is sent to explicitly point out a car that the requester wants to follow. This message needs a response.

**Fields**
* Identifier target - A unique identifier for the target of the request.

### Follow Reject
This message is sent as a response to a Follow Request due to the car identified in the *target* field of the Follow Request is already being followed. This is a response to the Follow Request message.

**Fields**
* Identifier nextInLine - A unique identifier for the car following the target of the Follow Request.

### Follow Accepted
This message is sent in response to a Follow Request when the request was successfully accepted. This is a response to the Follow Request message.

**Fields**
* Identifier acceptedCar - A unique identifier for the car for which the sent request was accepted.

### Status Update
This message includes information about a leading vehicle and contains information relevant for a following car to be able to follow it. This message does not expect a response.

**Fields**
* int speed - Current speed of the leading vehicle

### Detach Request
This message is sent by a car to indicate that it wishes to stop following the leading vehicle. This message does not expect a response.

**Fields**
* Identifier target - A unique identifier of the car that the requesting vehicle wished to stop following.

### Change Leader Request
This message is sent by a car who wants to detach from following its leader but also has a follower itself. To ensure the integrity of the platoon, the requeting car should send this request to its follower which will cause the follower to instead start listening for status updates sent by the requesters leader. This message does not expect a response.

**Fields**
* Identifier newLeader - A unique identifier of the car that the target of the request should start listening to updates from.
