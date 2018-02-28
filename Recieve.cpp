#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "messages.hpp"

/*
	Code based on lectures
	to recieve messages
*/

int main(int /*argc*/, char** /*argv*/) {
	
	cluon::OD4Session od4(111,
        [](cluon::data::Envelope &&envelope) noexcept {
        if (envelope.dataType() == 1001) {

          Message receivedMsg = cluon::extractMessage<Message>(std::move(envelope));

          std::cout << receivedMsg.sMessage() << std::endl;
        }
    });

	//infinite loop to recieve messages
    while(1){

    }

    return 0;
}