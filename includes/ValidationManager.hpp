#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <vector>
#include <regex>
#include <string>

class ValidationManager {
    public:
		bool runValidation(std::vector<std::string> buffer);

    private:
        class ExceptionInstructionUnknown : public std::exception {
            public:
                ExceptionInstructionUnknown();
                const char * what() const throw();
                ~ExceptionInstructionUnknown() throw() {}
        };

        class ExceptionExitDoesntExists : public std::exception {
            public:
                ExceptionExitDoesntExists();
                const char * what() const throw();
                ~ExceptionExitDoesntExists() throw() {}
        };
};

#endif