#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <vector>
#include <regex>
#include <string>

class ValidationManager {
	public:
		bool runValidation(std::vector<std::string> buffer);
};

#endif