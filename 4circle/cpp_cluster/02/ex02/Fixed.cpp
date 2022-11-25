/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:27:05 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/08 04:04:33 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(const int val) {
	_value = val << _bits;
}

Fixed::Fixed(const float val) {
	_value = roundf(val * (1 << _bits));
}

Fixed::Fixed(const Fixed &val) {
	*this = val;
}

Fixed::~Fixed(void) {
}

Fixed& Fixed::operator=(Fixed const &val) {
	this->_value = val._value;
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::toInt(void) const {
	return (_value >> _bits);
}

float Fixed::toFloat(void) const {
	return (float(_value) / (1 << _bits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &val) {
	out << val.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const &val) const {
	return (_value > val._value);
}

bool	Fixed::operator>=(Fixed const &val) const {
	return (_value >= val._value);
}

bool	Fixed::operator<(Fixed const &val) const {
	return (_value < val._value);
}

bool	Fixed::operator<=(Fixed const &val) const {
	return (_value <= val._value);
}

bool	Fixed::operator==(Fixed const &val) const {
	return (_value == val._value);
}

bool	Fixed::operator!=(Fixed const &val) const {
	return (_value != val._value);
}

Fixed	Fixed::operator+(Fixed const &val) const {
	return (Fixed(this->toFloat() + val.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &val) const {
	return (Fixed(this->toFloat() - val.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &val) const {
	return (Fixed(this->toFloat() * val.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &val) const {
	return (Fixed(this->toFloat() / val.toFloat()));
}

Fixed& Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	val(*this);

	this->_value++;
	return (val);
}

Fixed& Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	val(*this);

	this->_value--;
	return (val);
}

Fixed& Fixed::min(Fixed &val1, Fixed &val2) {
	if (val1 < val2)
		return (val1);
	return (val2);
}

Fixed const& Fixed::min(Fixed const &val1, Fixed const &val2) {
	if (val1 < val2)
		return (val1);
	return (val2);
}

Fixed& Fixed::max(Fixed &val1, Fixed &val2) {
	if (val1 > val2)
		return (val1);
	return (val2);
}

Fixed const& Fixed::max(Fixed const &val1, Fixed const &val2) {
	if (val1 > val2)
		return (val1);
	return (val2);
}