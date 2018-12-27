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

void VirtualMachine::setValues(std::vector<IOperand *> v) {
	this->values = v;
}

void VirtualMachine::setCommands(std::vector<std::string>	commands){
	this->commands = commands;
}