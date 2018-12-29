#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <iostream>
#include "interface/IOperand.hpp"
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <float.h>
template <class T>
class Operand : public IOperand {
	public:

        Operand(); // canonical
		Operand(Operand const & f); // canonical
		Operand & operator=(Operand const &f); // canonical
        virtual ~Operand(); // canonical
        Operand(eOperandType type, std::string const & value);

		int getPrecision() const; // Precision of the type of the instance
		eOperandType getType() const; // Type of the instance

		IOperand const * operator+(IOperand const & rhs)const; // Sum
		IOperand const * operator-(IOperand const & rhs)const; // Difference
		IOperand const * operator*(IOperand const & rhs)const; // Product
		IOperand const * operator/(IOperand const & rhs)const; // Quotient
		IOperand const * operator%(IOperand const & rhs)const; // Modulo

		std::string const & toString()const; // String representation of the instance
	private:
		eOperandType type;
		int precision;
		std::string value;

        void    changeType(IOperand const & rhs);

        class ExceptionDivisionByZero : public std::exception {
            public:
            ExceptionDivisionByZero();
                const char * what() const throw();
                ~ExceptionDivisionByZero() throw() {}
        };

    class ExceptionOverflow : public std::exception {
        public:
        ExceptionOverflow();
            const char * what() const throw();
            ~ExceptionOverflow() throw() {}
    };

    class ExceptionUnderflow : public std::exception {
        public:
            ExceptionUnderflow();
            const char * what() const throw();
            ~ExceptionUnderflow() throw() {}
    };
};

#endif
