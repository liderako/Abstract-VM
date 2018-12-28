#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <iostream>
#include "interface/IOperand.hpp"
#include <vector>

class VirtualMachine {
	private:
		std::vector<IOperand *> 	values;
		std::vector<std::string>	commands;

	public:
		VirtualMachine(); // canonical
		VirtualMachine(VirtualMachine const & f); // canonical
		~VirtualMachine(); // canonical

		VirtualMachine & operator=(VirtualMachine const &f); // canonical

		void setValues(std::vector<IOperand *> 	v);
		void setCommands(std::vector<std::string>	commands);
		void printCommands();
};

#endif