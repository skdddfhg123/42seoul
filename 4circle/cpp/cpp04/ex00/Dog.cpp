/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:47:16 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:00:48 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog: " << this->_type << " default contstructor called" << std::endl;
}

Dog::Dog(Dog const &src) {
	this->_type = src.getType();
	std::cout << "Dog: " << this->_type << " copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: " << this->_type << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &src) {
	this->_type = src.getType();
	std::cout << "Dog: " << this->_type << " copy assignment operator called" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "Dog: " << this->_type << " BowWow Bowwow!!" << std::endl;
}
