#include "Parser.hpp"

void 	Parser::run(VirtualMachine vm, std::vector<std::string> buffer) {
	std::cout << "PARSE START__________\n";
    std::regex regularCommand("(pop|dump|add|sub|mul|div|mod|print|exit)");
    std::regex regularCommandWithValue("(push|assert)"
                                       "(\\s)"
                                       "(int32|int8|int16)"
                                       "(\\()"
                                       "([\\d]+)"
                                       "(\\))"
                                       "(\\s*)");
    std::regex regularFloatAndDouble("(push|assert)"
                                     "(\\s)(float|double)"
                                     "(\\()"
                                     "([\\d]+\\.[\\d]+)"
                                     "(\\))"
                                     "(\\s*)");

    std::cmatch result;

	std::vector<std::string>	commands;

	for (unsigned long i = 0; i < buffer.size(); i++) {
		if (std::regex_match(buffer[i].c_str(), regularCommandWithValue) == 1) {
		    std::regex_search(buffer[i].c_str(), result, regularCommandWithValue);
		    std::cout <<":0:  "<< result[1] << "\n";
            std::cout <<":1:  "<< result[3] << "\n";
            std::cout <<":2:  "<< result[5] << "\n";
		}
		else if(std::regex_match(buffer[i].c_str(), regularFloatAndDouble) == 1) {
            std::regex_search(buffer[i].c_str(), result, regularFloatAndDouble);
            std::cout <<":0:  "<< result[1] << "\n";
            std::cout <<":1:  "<< result[3] << "\n";
            std::cout <<":2:  "<< result[5] << "\n";
		}
		else if (std::regex_match(buffer[i].c_str(), regularCommand) == 1) {
		    // run command
		}
	}
//	}
	vm.setCommands(commands);
}