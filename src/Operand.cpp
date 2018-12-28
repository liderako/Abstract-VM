#include "Operand.hpp"
#include <string>
///* Canonical form */

template <class T>
Operand<T>::Operand(){
    return ;
}

template <class T>
Operand<T>::Operand(Operand<T> const &f) {
    *this = f;
}

template <class T>
Operand<T> & Operand<T>::operator=(Operand const &operand) {
    this->type = operand.type;
    this->precision = operand.precision;
    return (*this);
}

template <class T>
Operand<T>::~Operand() {
    return ;
}

////* ********* */

template <>
Operand<int8_t>::Operand(eOperandType type, std::string const & value) {
    this->type = type;
    this->value = value;
}

template <>
Operand<int16_t>::Operand(eOperandType type, std::string const & value) {
    this->type = type;
    this->value = value;
}

template <>
Operand<int32_t>::Operand(eOperandType type, std::string const & value) {
    this->type = type;
    this->value = value;
}

template <>
Operand<float>::Operand(eOperandType type, std::string const & value) {
    this->type = type;
    this->value = value;
}

template <>
Operand<double>::Operand(eOperandType type, std::string const & value) {
    this->type = type;
    this->value = value;
}

////

template <class T>
eOperandType Operand<T>::getType() const {
	return this->type;
}

template <class T>
int Operand<T>::getPrecision() const {
    return (this->precision);
}

template <class T>
std::string Operand<T>::getValue() const {
    return (this->value);
}

template <class T>
IOperand const * Operand<T>::operator+(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(rhs.toString()) + std::stod(this->toString()))));
}

template <class T>
IOperand const * Operand<T>::operator-(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(rhs.toString()) - std::stod(this->toString()))));
}

template <class T>
IOperand const * Operand<T>::operator*(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(rhs.toString()) * std::stod(this->toString()))));
}

template <class T>
IOperand const * Operand<T>::operator/(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(rhs.toString()) / std::stod(this->toString()))));
}

template <class T>
IOperand const * Operand<T>::operator%(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(rhs.toString()) % std::stod(this->toString()))));
}

template <class T>
std::string const & Operand<T>::toString(void) const {
    return (this->value);
}