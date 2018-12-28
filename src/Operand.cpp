#include "Operand.hpp"

///* Canonical form */
//
Operand::Operand(){
    return ;
}

//
//Operand::Operand(Operand const &f) {
//    *this = f;
//}
//
//Operand & Operand::operator=(Operand const &operand) {
//    this->type = operand.type;
//    this->precision = operand.precision;
//    return (*this);
//}

/* ********* */

Operand::~Operand() {

}


eOperandType Operand::getType(void) const {
	return this->type;
}


/*
		int getPrecision(void) const; // Precision of the type of the instance
		eOperandType getType(void) const; // Type of the instance
		IOperand const * operator+(IOperand const & rhs); // Sum
		IOperand const * operator-(IOperand const & rhs); // Difference
		IOperand const * operator*(IOperand const & rhs); // Product
		IOperand const * operator/(IOperand const & rhs); // Quotient
		IOperand const * operator%(IOperand const & rhs); // Modulo
		std::string const & toString(void)const; // String representation of the instance
		virtual ~Operand(void);
 */