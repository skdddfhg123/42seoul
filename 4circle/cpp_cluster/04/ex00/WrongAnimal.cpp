/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:49:22 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:01:14 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
	std::cout << "WrongAnimal: " << this->_type << " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal: " << this->_type << " string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : _type(src.getType()) {
	std::cout << "WrongAnimal: " << this->_type << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: " << this->_type << " destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src) {
	this->_type = src.getType();
	std::cout << "WrongAnimal: " << this->_type << " copy assignment operator called" << std::endl;
	return(*this);
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}

void WrongAnimal::makeSound() const {
	std::cout << this->_type << std::endl;
}
