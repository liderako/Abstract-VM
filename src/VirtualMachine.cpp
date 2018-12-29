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

    for (unsigned long i = 0; i < buffer.size(); i++) {
        action = parser.run(buffer[i].c_str());
        if (action.size() == 3) {
            if (action[0].compare("push") == 0) {
                this->push(action[1], action[2]);
            }
            else {
                std::cout << "assert\n";
            }
        }
        else {
            if (action[0].compare("dump") == 0) {
                dump();
            }
            else if (action[0].compare("exit") == 0) {
                this->exit();
            }
        }
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

void VirtualMachine::assert() {

}
void VirtualMachine::add() {

}
void VirtualMachine::sub() {

}
void VirtualMachine::mul() {

}
void VirtualMachine::div() {

}
void VirtualMachine::mod() {

}
void VirtualMachine::exit() {
    std::exit(1);
}

void VirtualMachine::print() {

}