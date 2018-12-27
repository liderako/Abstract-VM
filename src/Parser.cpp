#include "Parser.hpp"

void 	Parser::run(VirtualMachine vm, std::vector<std::string> inputBuffer) {
	for (unsigned long i = 0; i < inputBuffer.size(); i++) {
		vm.setCommands(inputBuffer);
	}
}