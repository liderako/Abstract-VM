#include "ValidationManager.hpp"

bool ValidationManager::runValidation(std::vector<std::string> buffer) {
	std::regex regularCommand("(pop|dump|add|sub|mul|div|mod|print|exit)");
	std::regex regularCommandWithValue("(push|assert)(\\s)(int32|int8|int16)(\\([\\d]+\\))(\\s*)");
	std::regex regularFloatAndDouble("(push|assert)(\\s)(float|double)(\\([\\d]+\\.[\\d]+\\))(\\s*)");
	
	for (unsigned long i = 0; i < buffer.size(); i++) {
		if (std::regex_match(buffer[i].c_str(), regularCommand) == 1) {
			continue ;
		}
		else if (std::regex_match(buffer[i].c_str(), regularCommandWithValue) == 1) {
			continue ;
		}
		else if (std::regex_match(buffer[i].c_str(), regularFloatAndDouble) == 1) {
			continue ;
		}
		else {
			std::cout << "An instruction is unknown" << std::endl; // добавить exception
			std::exit(-1);
		}
	}
	return (true);
}