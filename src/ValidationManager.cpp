#include "ValidationManager.hpp"

bool ValidationManager::runValidation(std::vector<std::string> buffer) {
	std::regex regularCommand("(pop|dump|add|sub|mul|div|mod|print|exit)");
	std::regex regularCommandWithValue("(push|assert)(\\s)(int32|int8|int16)(\\([\\d]+\\))(\\s*)");
	std::regex regularFloatAndDouble("(push|assert)(\\s)(float|double)(\\([\\d]+\\.[\\d]+\\))(\\s*)");

	try {
        for (unsigned long i = 0; i < buffer.size(); i++) {
            if (std::regex_match(buffer[i].c_str(), regularCommand) == 1) {
                continue;
            } else if (std::regex_match(buffer[i].c_str(), regularCommandWithValue) == 1) {
                continue;
            } else if (std::regex_match(buffer[i].c_str(), regularFloatAndDouble) == 1) {
                continue;
            } else {
                throw ValidationManager::ExceptionInstructionUnknown();
            }
        }
    } catch (std::exception &e) {
	    std::cout << e.what() << std::endl;
	    std::exit(-1);
	}
	return (true);
}


ValidationManager::ExceptionInstructionUnknown::ExceptionInstructionUnknown() {}

const char *ValidationManager::ExceptionInstructionUnknown::what() const throw() {
    return ("Error: An instruction is unknown");
}