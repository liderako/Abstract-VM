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
        void assert(std::string type, std::string value);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void exit();
        void print();
        void pop();

        std::vector<IOperand const *> 	values;

    class ExceptionEmptyStack : public std::exception {
        public:
        ExceptionEmptyStack();
        const char * what() const throw();
        ~ExceptionEmptyStack() throw() {}
    };

    class ExceptionAssert : public std::exception {
        public:
        ExceptionAssert();
        const char * what() const throw();
        ~ExceptionAssert() throw() {}
    };

    class ExceptionAssertTypeDifferent : public std::exception {
        public:
            ExceptionAssertTypeDifferent();
            const char * what() const throw();
            ~ExceptionAssertTypeDifferent() throw() {}
    };
};

#endif