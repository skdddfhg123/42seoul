/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:48:51 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 16:35:33 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap Default constructor " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap string constructor " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap copy constructor " << src._name << " called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor" << _name << " called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "FragTrap operator= " << this->_name << " called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " positive high fives request" << std::endl;
}
