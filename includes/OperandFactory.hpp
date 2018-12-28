#ifndef OPERAND_FACTORY
#define OPERAND_FACTORY

#include "interface/IOperand.hpp"

class OperandFactory {
	public:
		IOperand const *createInt8( std::string const & value ) const;
		IOperand const *createInt16( std::string const & value ) const;
		IOperand const *createInt32( std::string const & value ) const;
		IOperand const *createFloat( std::string const & value ) const;
		IOperand const *createDouble( std::string const & value ) const;
		IOperand const *createOperand( eOperandType type, std::string const & value ) const;
};

#endif