/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:47:14 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/08 01:16:37 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	_value = val << _bits;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(val * (1 << _bits));
}

Fixed::Fixed(const Fixed &val) {
	std::cout << "Copy constructor called" << std::endl;
	*this = val;
}

Fixed::~Fixed(void) {
	std::cout << "Destrutor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &val) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = val._value;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::toInt(void) const {
	return (this->_value >> this->_bits);
}

float Fixed::toFloat(void) const {
	return (float(_value) / (1 << _bits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &val) {
	out << val.toFloat();
	return (out);
}
