#include "ValidationManager.hpp"

bool ValidationManager::runValidation(std::vector<std::string> buffer) {
	std::cout << "validation start\n";
	std::cmatch result;


	std::regex regularCommand("(pop|dump|add|sub|mul|div|mod|print|exit)");
	std::regex regularCommandWithValue("(push|assert)(\\s)(int32|int8|int16)(\\([\\d]+\\))");
	std::regex regularFloatAndDouble("(push|assert)(\\s)(float|double)(\\([\\d]+\\.[\\d]+\\))");
	
	for (unsigned long i = 0; i < buffer.size(); i++) {
		std::cout << buffer[i] << std::endl;
		
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
		}
	}
	
	return (true);
}