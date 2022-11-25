/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:09:02 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/07 23:41:18 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &val) {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(val);
}

Fixed::~Fixed(void) {
	std::cout << "Destrutor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &val) {
	std::cout << "Copy assignment operator called" << std::endl;
	_value = val.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
