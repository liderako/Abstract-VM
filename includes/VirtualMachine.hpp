#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <iostream>
//#include "interface/IOperand.hpp"
#include "Parser.hpp"
#include "OperandFactory.hpp"
#include <vector>

//enum eTypeAction{Pop, Dump, Add, Sub, Mul, Div, Mod, Print, Exit, Push, Assert};

class VirtualMachine {

	public:
		VirtualMachine(); // canonical
		VirtualMachine(VirtualMachine const & f); // canonical
		~VirtualMachine(); // canonical

		VirtualMachine & operator=(VirtualMachine const &f); // canonical

        void runAVM(std::vector<std::string> buffer);
    private:
        void push(std::string type, std::string value);
        void dump();
        void assert();
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void exit();
        void print();

        std::vector<IOperand const *> 	values;
};

#endif