#include "Parser.hpp"

void 	Parser::run(VirtualMachine vm, std::vector<std::string> buffer) {
	std::regex regularCommand("(pop|dump|add|sub|mul|div|mod|print|exit)");
	
	std::vector<std::string>	commands;
	std::cmatch result;
	
	for (unsigned long i = 0; i < buffer.size(); i++) {
		if (std::regex_match(buffer[i].c_str(), regularCommand) == 1) {
			commands.push_back(buffer[i]);
		}
	}
	vm.setCommands(commands);
}