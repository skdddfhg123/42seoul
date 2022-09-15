/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:40:35 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 18:42:51 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _raw("") , _type(TYPE_ERROR) , _c(0) , _c_overflow(false) , _i(0) , _f(0.0f) , _d(0.0) {
	this->_type = CheckType(_raw);
	this->convertToActualType();
	this->convertToOtherType();
}

Convert::Convert(std::string raw) : _raw(raw) , _type(TYPE_ERROR) , _c(0) , _c_overflow(false) , _i(0) , _f(0.0f) , _d(0.0) {
	this->_type = CheckType(_raw);
	this->convertToActualType();
	this->convertToOtherType();
}

Convert::Convert(const Convert& src) {
	*this = src;
}

Convert& Convert::operator=(const Convert& src) {
	if (this != &src) {
    this->_raw = src._raw;
    this->_type = src._type;
    this->_c = src._c;
    this->_c_overflow = src._c_overflow;
    this->_i = src._i;
    this->_f = src._f;
    this->_d = src._d;
	}
	return (*this);
}

Convert::~Convert() {}

std::string Convert::getInput() const { return  (this->_raw); }

int Convert::getType() const { return (this->_type); }

char Convert::getChar() const { return (this->_c); }

bool Convert::getCharOver() const { return (this->_c_overflow); }

long Convert::getInt() const { return (this->_i); }

float Convert::getFloat() const { return (this->_f); }

double Convert::getDouble() const { return (this->_d); }

void Convert::convertToActualType() {
  switch (this->_type) {
  case TYPE_CHAR:
    if (this->_raw.length() == 1)  // a
      this->_c = this->_raw[0];
    else  // 'a'
      this->_c = this->_raw[1];
    break;
  case TYPE_INT:    this->_i = strtol(this->_raw.c_str(), NULL, 10);                 break;
  case TYPE_FLOAT:  this->_f = static_cast<float>(strtod(this->_raw.c_str(), NULL)); break;
  case TYPE_DOUBLE: this->_d = strtod(this->_raw.c_str(), NULL);                     break;
  }
}

void Convert::convertToOtherType() {
  switch (this->_type) {
  case TYPE_CHAR:
    this->_i = static_cast<long>(this->_c);
    this->_f = static_cast<float>(this->_c);
    this->_d = static_cast<double>(this->_c);
    break;
  case TYPE_INT:
    if (!isascii(static_cast<int>(this->_i)))
      this->_c_overflow = true;
    else
      this->_c = static_cast<char>(this->_i);
    this->_f = static_cast<float>(this->_i);
    this->_d = static_cast<double>(this->_i);
    break;
  case TYPE_FLOAT:
    if (!isascii(static_cast<int>(this->_f)))
      this->_c_overflow = true;
    else
      this->_c = static_cast<char>(this->_f);
    this->_i = static_cast<long>(this->_f);
    this->_d = static_cast<double>(this->_f);
    break;
  case TYPE_DOUBLE:
    if (!isascii(static_cast<int>(this->_d)))
      this->_c_overflow = true;
    else
      this->_c = static_cast<char>(this->_d);
    this->_i = static_cast<long>(this->_d);
    this->_f = static_cast<float>(this->_d);
    break;
  }
}

void printChar(std::ostream& out, const Convert& src) {
  out << "char: ";
  if (src.getType() == TYPE_ERROR || src.getType() == TYPE_INT_OVERFLOW || src.getCharOver())
    out << "impossible";
  else if (!isprint(src.getChar()))
    out << "Non displayable";
  else
    out << '\'' << src.getChar() << '\'';
  out << std::endl;
}

void printInt(std::ostream& out, const Convert& src) {
  out << "int: ";
  if ((src.getType() == TYPE_ERROR || src.getType() == TYPE_INT_OVERFLOW)
  || (src.getInt() > std::numeric_limits<int>::max())
  || (src.getInt() < std::numeric_limits<int>::min()))
    out << "impossible";
  else
    out << static_cast<int>(src.getInt());
  out << std::endl;
}

void printFloat(std::ostream& out, const Convert& src) {
  out << "float: ";
  if (src.getType() == TYPE_ERROR || src.getType() == TYPE_INT_OVERFLOW)
    out << "impossible";
  else
    out << std::fixed << std::setprecision(1) << src.getFloat() << "f";
  out << std::endl;
}

void  printDouble(std::ostream& out, const Convert& src) {
  out << "double: ";
  if (src.getType() == TYPE_ERROR || src.getType() == TYPE_INT_OVERFLOW)
    out << "impossible";
  else
    out << std::fixed << std::setprecision(1) << src.getDouble();
  out << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Convert& src) {
	printChar(out, src);
	printInt(out, src);
	printFloat(out, src);
	printDouble(out, src);
	return (out);
}