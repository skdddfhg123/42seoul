/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:52:44 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:01:39 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat: " << this->_type << " default contstructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) {
	this->_type = src.getType();
	std::cout << "WrongCat: " << this->_type << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: " << this->_type << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src) {
	this->_type = src.getType();
	std::cout << "WrongCat: " << this->_type << " copy assignment operator called" << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat: " << this->_type << " meow meow!!" << std::endl;
}
