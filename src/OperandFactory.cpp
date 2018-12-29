#include "OperandFactory.hpp"

IOperand const *OperandFactory::createInt8( std::string const & value ) const {
    return (new Operand<int8_t>(eOperandType::Int8, value));
}

IOperand const *OperandFactory::createInt16( std::string const & value ) const {
    return (new Operand<int16_t>(eOperandType::Int16, value));
}

IOperand const *OperandFactory::createInt32( std::string const & value ) const {
    return (new Operand<int32_t>(eOperandType::Int32, value));
}

IOperand const *OperandFactory::createFloat( std::string const & value ) const {
    return (new Operand<float>(eOperandType::Float, value));
}

IOperand const *OperandFactory::createDouble( std::string const & value ) const {
    return (new Operand<double>(eOperandType::Double, value));
}

IOperand const *OperandFactory::createOperand( eOperandType type, std::string const & value ) const {
    switch (type) {
        case Int32:
            return (createInt32(value));
        case Int16:
            return (createInt16(value));
        case Int8:
            return (createInt8(value));
        case Float:
            return (createFloat(value));
        case Double:
             return (createDouble(value));
    }
}