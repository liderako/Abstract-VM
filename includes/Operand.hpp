#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <iostream>
#include "interface/IOperand.hpp"

class Operand : public IOperand {
	public:
		Operand(); // canonical
		Operand(Operand const & f); // canonical

		Operand & operator=(Operand const &f); // canonical

		int getPrecision(void) const; // Precision of the type of the instance
		eOperandType getType(void) const; // Type of the instance
		IOperand const * operator+(IOperand const & rhs); // Sum
		IOperand const * operator-(IOperand const & rhs); // Difference
		IOperand const * operator*(IOperand const & rhs); // Product
		IOperand const * operator/(IOperand const & rhs); // Quotient
		IOperand const * operator%(IOperand const & rhs); // Modulo
		std::string const & toString(void)const; // String representation of the instance
		virtual ~Operand(void);
	private:
		eOperandType type;
		int precision;
};

#endif
