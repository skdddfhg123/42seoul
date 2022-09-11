/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:36:33 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:00:28 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("default") {
	std::cout << "Animal: " << this->_type << " Default constructor called" << std::endl;
}
	
Animal::Animal(Animal const &src) : _type(src.getType()) {
	std::cout << "Animal: " << this->_type << " copy constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal: " << this->_type << " string constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal: " << this->_type << " destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const &src) {
	this->_type = src.getType();
	std::cout << "Animal: " << this->_type << " copy assignment operator called!" << std::endl;
	return (*this);
}

std::string Animal::getType(void) const {
	return (this->_type);
}

void Animal::makeSound(void) const {
	std::cout << (this->_type) << std::endl;
}