/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:28 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:00:12 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat: " << this->_type << " default contstructor called" << std::endl;
}

Cat::Cat(Cat const &src) {
	this->_type = src.getType();
	std::cout << "Cat: " << this->_type << " copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat: " << this->_type << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &src) {
	this->_type = src.getType();
	std::cout << "Cat: " << this->_type << " copy assignment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << "Cat: " << this->_type << " meow meow!!" << std::endl;
}
