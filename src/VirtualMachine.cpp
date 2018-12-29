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
	return (*this);
}

void VirtualMachine::runAVM(std::vector<std::string> buffer) {
    Parser      parser;
    std::vector<std::string> action;
    try {
        for (unsigned long i = 0; i < buffer.size(); i++) {
            action = parser.run(buffer[i].c_str());
            if (action.size() == 3) {
                if (action[0].compare("push") == 0) {
                    this->push(action[1], action[2]);
                } else {
                    this->assert(action[1], action[2]);
                }
            } else {
                if (action[0].compare("dump") == 0) {
                    this->dump();
                }
                else if (action[0].compare("exit") == 0) {
                    this->exit();
                }
                else if (action[0].compare("pop") == 0) {
                    this->pop();
                }
            }
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
}

void VirtualMachine::push(std::string type, std::string value) {
    OperandFactory factory;

    if (type.compare("int32") == 0) {
        this->values.push_back(factory.createOperand(eOperandType::Int32, value ));
    }
    else if (type.compare("int16") == 0) {
        this->values.push_back(factory.createOperand(eOperandType::Int16, value ));
    }
    else if (type.compare("int8") == 0) {
        this->values.push_back(factory.createOperand(eOperandType::Int8, value ));
    }
    else if (type.compare("float") == 0) {
        this->values.push_back(factory.createOperand(eOperandType::Float, value ));
    }
    else if (type.compare("double") == 0) {
        this->values.push_back(factory.createOperand(eOperandType::Double, value ));
    }
}

void VirtualMachine::dump() {
    if (values.empty()) {
        return ;
    }
    for (unsigned long i = values.size() - 1; i > 0; i--) {
        std::cout << values[i]->toString() << std::endl;
    }
    if (values.size() != 0) {
        std::cout << values[0]->toString() << std::endl;
    }
}

void VirtualMachine::assert(std::string type, std::string value) {
    if (values.empty()) {
        throw ExceptionEmptyStack();
    }
    eOperandType e = Int32;
    if (type.compare("int32") == 0) {
        e = eOperandType::Int32;
    }
    else if (type.compare("int16") == 0) {
        e = eOperandType::Int16;
    }
    else if (type.compare("int8") == 0) {
        e = eOperandType::Int8;
    }
    else if (type.compare("float") == 0) {
        e = eOperandType::Float;
    }
    else if (type.compare("double") == 0) {
        e = eOperandType::Double;
    }
    if (values[values.size()-1]->getType() != e) {
        throw ExceptionAssertTypeDifferent();
    }
    else if (values[values.size()-1]->toString().compare(value) != 0) {
        throw ExceptionAssert();
    }
}

void VirtualMachine::add() {

}

void VirtualMachine::sub() {

}

void VirtualMachine::mul() {

}

void VirtualMachine::div() {

}

void VirtualMachine::pop() {
    if (values.empty()) {
        throw ExceptionEmptyStack();
    }
    values.erase(values.end() - 1);
}

void VirtualMachine::mod() {

}

void VirtualMachine::exit() {
    std::exit(1);
}

void VirtualMachine::print() {

}


VirtualMachine::ExceptionEmptyStack::ExceptionEmptyStack() {}

const char *VirtualMachine::ExceptionEmptyStack::what() const throw() {
    return ("Exception: stack is empty");
}

VirtualMachine::ExceptionAssert::ExceptionAssert() {}

const char *VirtualMachine::ExceptionAssert::what() const throw() {
    return ("Exception: assert is not true, value different");
}

VirtualMachine::ExceptionAssertTypeDifferent::ExceptionAssertTypeDifferent() {}

const char *VirtualMachine::ExceptionAssertTypeDifferent::what() const throw() {
    return ("Exception: assert is not true, type different");
}