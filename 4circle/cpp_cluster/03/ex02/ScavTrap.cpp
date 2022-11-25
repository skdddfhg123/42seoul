/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:15:12 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 13:13:22 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guard_mode(false) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap Default constructor " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap string constructor " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap copy constructor " << src._name << " called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor" << _name << " called" << std::endl;
}

void	ScavTrap::guardGate(void) {
	this->_guard_mode = true;
	std::cout << "ScavTrap " <<  this->_name << " have entereed in Gate keeper mode." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "ScavTrap operator= " << this->_name << " called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_hit_points == 0) {
		std::cout << "ScavTrap " << this->_name << " is already game over!" << std::endl;
		return ;
	}
	else if (this->_energy_points == 0) {
		std::cout << "ScavTrap " << this->_name << " energy points is zero!" << std::endl;
		return ;
	}
	else {
		this->_energy_points--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
}
