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
    this->value = operand.value;
    return (*this);
}

template <class T>
Operand<T>::~Operand() {
    return ;
}

////* ********* */

template <>
Operand<int8_t>::Operand(eOperandType type, std::string const & value) {
    try {
        if (stoi(value) > INT8_MAX) {
            throw ExceptionOverflow();
        }
        if (stoi(value) < INT8_MIN) {
            throw ExceptionUnderflow();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
    this->type = type;
    this->precision = type;
    this->value = std::to_string(atoi(value.c_str()));
}

template <>
Operand<int16_t>::Operand(eOperandType type, std::string const & value) {
    try {
        if (stoi(value) > INT16_MAX) {
            throw ExceptionOverflow();
        }
        if (stoi(value) < INT16_MIN) {
            throw ExceptionUnderflow();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
    this->type = type;
    this->precision = type;
    this->value = std::to_string(atoi(value.c_str()));
}

template <>
Operand<int32_t>::Operand(eOperandType type, std::string const & value) {
    try {
        if (stol(value) > INT32_MAX) {
            throw ExceptionOverflow();
        }
        if (stol(value) < INT32_MIN) {
            throw ExceptionUnderflow();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
    this->type = type;
    this->precision = type;
    this->value = std::to_string(atoi(value.c_str()));
}

template <>
Operand<float>::Operand(eOperandType type, std::string const & value) {
    try {
        if (std::stod(value) > FLT_MAX) {
            throw ExceptionOverflow();
        }
        if (std::stod(value) < -FLT_MAX) {
            throw ExceptionUnderflow();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
    this->type = type;
    this->precision = type;
    this->value = value;
}

template <>
Operand<double>::Operand(eOperandType type, std::string const & value) {
    try {
        if (std::stold(value) > DBL_MAX) {
            throw ExceptionOverflow();
        }
        if (std::stold(value) < -DBL_MAX) {
            throw ExceptionUnderflow();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
    this->type = type;
    this->precision = type;
    this->value = value;
}

template <class T>
eOperandType Operand<T>::getType() const {
	return this->type;
}

template <class T>
int Operand<T>::getPrecision() const {
    return (this->precision);
}

template <class T>
std::string const & Operand<T>::toString(void) const {
    return (this->value);
}

template <class T>
IOperand const * Operand<T>::operator+(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string( std::stod(this->toString()) + std::stod(rhs.toString()) )));
}

template <class T>
IOperand const * Operand<T>::operator-(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(this->toString()) - std::stod(rhs.toString()))));
}

template <class T>
IOperand const * Operand<T>::operator*(IOperand const & rhs) const {
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(this->toString()) * std::stod(rhs.toString()))));
}

template <class T>
IOperand const * Operand<T>::operator/(IOperand const & rhs) const {
    double del = std::stod(rhs.toString());
    try {
        if (del == 0) {
            throw ExceptionDivisionByZero();
        }
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::stod(this->toString()) / std::stod(rhs.toString()))));
}

template <class T>
IOperand const * Operand<T>::operator%(IOperand const & rhs) const {
    double del = std::stod(rhs.toString());
    try {
        if (del == 0) {
            throw ExceptionDivisionByZero();
        }
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        std::exit(-1);
    }
    eOperandType e = (rhs.getPrecision() > this->getPrecision() ? rhs.getType() : this->getType());
    return (new Operand(e, std::to_string(std::fmod(std::stod(this->toString()), del))));
}

template <class T>
Operand<T>::ExceptionDivisionByZero::ExceptionDivisionByZero() {}

template <class T>
const char *Operand<T>::ExceptionDivisionByZero::what() const throw() {
    return ("Exception: Division by zero");
}

template <class T>
Operand<T>::ExceptionOverflow::ExceptionOverflow() {}

template <class T>
const char *Operand<T>::ExceptionOverflow::what() const throw() {
    return ("Exception: overflow type");
}


template <class T>
Operand<T>::ExceptionUnderflow::ExceptionUnderflow() {}

template <class T>
const char *Operand<T>::ExceptionUnderflow::what() const throw() {
    return ("Exception: underflow type");
}