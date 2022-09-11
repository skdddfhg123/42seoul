/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:06:49 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:44:25 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i=0; i < 100; i++) {
		std::stringstream str;
		str << i + 1;
		this->_ideas[i] = std::string("idea") + (str.str());
	}
	std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(Brain const &src) {
	const std::string	*ideas = src.getIdea();

	for (int i=0; i < 100; i++)
		this->_ideas[i] = ideas[i];
	std::cout << "Brain: copy constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain: destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &src) {
	const std::string	*ideas = src.getIdea();

	for (int i=0; i < 100; i++)
		this->_ideas[i] = ideas[i];
	std::cout << "Brain: copy assignment operator called" << std::endl;
	return (*this);
}

const std::string *Brain::getIdea() const {
	return (this->_ideas);
}

void Brain::show(void) const {
	for (int i=0; i < 100; i++)
		std::cout << "Number " << i << " idea : " << this->_ideas[i] << std::endl;
}