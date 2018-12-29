#include "ValidationManager.hpp"

bool ValidationManager::runValidation(std::vector<std::string> buffer) {
	std::regex regularCommand("(pop|dump|add|sub|mul|div|mod|print)");
    std::regex regularCommandExit("(exit)");
	std::regex regularCommandWithValue("(push|assert)(\\s)(int32|int8|int16)(\\(-?[\\d]+\\))(\\s*)");
	std::regex regularFloatAndDouble("(push|assert)(\\s)(float|double)(\\(-?[\\d]+\\.[\\d]+\\))(\\s*)");

	int exitExists = 0;

	try {
        for (unsigned long i = 0; i < buffer.size(); i++) {
            if (std::regex_match(buffer[i].c_str(), regularCommand) == 1) {
                continue;
            } else if (std::regex_match(buffer[i].c_str(), regularCommandWithValue) == 1) {
                continue;
            } else if (std::regex_match(buffer[i].c_str(), regularFloatAndDouble) == 1) {
                continue;
            } else if (std::regex_match(buffer[i].c_str(), regularCommandExit) == 1) {
                exitExists++;
            }
            else {
                throw ValidationManager::ExceptionInstructionUnknown();
            }
        }
        if (exitExists == 0) {
            throw ExceptionExitDoesntExists();
        }
    } catch (std::exception &e) {
	    std::cout << e.what() << std::endl;
	    std::exit(-1);
	}
	return (true);
}


ValidationManager::ExceptionInstructionUnknown::ExceptionInstructionUnknown() {}

const char *ValidationManager::ExceptionInstructionUnknown::what() const throw() {
    return ("Exception: An instruction is unknown or syntax wrong");
}

ValidationManager::ExceptionExitDoesntExists::ExceptionExitDoesntExists() {}

const char *ValidationManager::ExceptionExitDoesntExists::what() const throw() {
    return ("Exception: The program doesn't have an exit instruction");
}