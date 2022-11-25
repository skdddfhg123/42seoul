/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:28 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 21:09:27 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat: " << this->_type << " default contstructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) {
	this->_type = src.getType();
	std::cout << "Cat: " << this->_type << " copy constructor called" << std::endl;
	Brain	*this_brain = new Brain(*src.getBrain());
	this->_brain = this_brain;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat: " << this->_type << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &src) {
	this->_type = src.getType();
	std::cout << "Cat: " << this->_type << " copy assignment operator called" << std::endl;
	*(this->_brain) = *(src._brain);
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << "Cat: " << this->_type << " meow meow!!" << std::endl;
}

Brain* Cat::getBrain() const {
	return (this->_brain);
}