/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:47:16 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 21:09:12 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog: " << this->_type << " default contstructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) {
	this->_type = src.getType();
	std::cout << "Dog: " << this->_type << " copy constructor called" << std::endl;
	Brain	*this_brain = new Brain(*src.getBrain());
	this->_brain = this_brain;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog: " << this->_type << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &src) {
	this->_type = src.getType();
	std::cout << "Dog: " << this->_type << " copy assignment operator called" << std::endl;
	*(this->_brain) = *(src._brain);
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "Dog: " << this->_type << " BowWow Bowwow!!" << std::endl;
}

Brain* Dog::getBrain() const {
	return (this->_brain);
}