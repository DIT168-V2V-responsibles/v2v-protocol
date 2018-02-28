#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "messages.hpp"

typedef std::basic_string<char> string;

/*
	Code based on lectures
	to send messages
*/

int main(int /*argc*/, char** /*argv*/) {


	cluon::OD4Session od4(111,
        [](cluon::data::Envelope &&envelope) noexcept {});

	
	while(1){
   		string message;
    	std::cout << "Enter message to send: ";
    	std::cin >> message;
    	Message msg;
    	msg.sMessage(message);

    	od4.send(msg);
	}

    return 0;
}