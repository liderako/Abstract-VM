#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include "VirtualMachine.hpp"

class Parser {
	public:
    std::vector<std::string> run(std::string buffer);
};

#endif