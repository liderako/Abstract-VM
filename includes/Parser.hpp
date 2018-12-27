#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include "VirtualMachine.hpp"

class Parser {
	public:
		void run(VirtualMachine vm, std::vector<std::string> inputBuffer);
};

#endif