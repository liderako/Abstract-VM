#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine() {

}

VirtualMachine::VirtualMachine(VirtualMachine const &f) {
	*this = f;
}

VirtualMachine::~VirtualMachine() {
}

VirtualMachine & VirtualMachine::operator=(VirtualMachine const &virtualMachine) {
	this->values = virtualMachine.values;
	this->commands = virtualMachine.commands;
	return (*this);
}

void VirtualMachine::runAVM(std::vector<std::string> buffer) {
    for (unsigned long i = 0; i < buffer.size(); i++) {
        std::cout << buffer[i] << std::endl;
    }
}

void VirtualMachine::setValues(std::vector<IOperand *> v) {
	this->values = v;
}

void VirtualMachine::setCommands(std::vector<std::string>	commands){
	this->commands = commands;
}

void VirtualMachine::printCommands() {
	for (unsigned long i = 0; i < commands.size(); i++) {
		std::cout << commands[i] << "\n";
	}
}