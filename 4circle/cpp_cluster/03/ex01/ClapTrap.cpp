/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:28:40 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/11 16:37:50 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap Default constructor " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap string constructor " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int att) : _name(name), _hit_points(hit), _energy_points(energy), _attack_damage(att){
    std::cout << "ClapTrap string constructor " << _name << " calledsss" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap copy constructor " << _name << " called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destuctor " << this->_name << " called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &src) {
    _name = src._name;
    _hit_points = src._hit_points;
    _energy_points = src._energy_points;
    _attack_damage = src._attack_damage;
    std::cout << "ClapTrap operator= " << this->_name << " called" << std::endl;
    return (*this);
}

void    ClapTrap::attack(const std::string &target) {
    if (this->_hit_points == 0) {
        std::cout << "ClapTrap " << this->_name << " is already game over!" << std::endl;
        return ;
    }
    else if (this->_energy_points == 0) {
        std::cout << "ClapTrap " << this->_name << " energy points is zero!" << std::endl;
        return ;
    }
    else {
        this->_energy_points--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit_points == 0) {
        std::cout << "ClapTrap " << this->_name << " is already game over!" << std::endl;
        return ;
    }
    if (this->_energy_points > 0) {
        if (amount >= this->_hit_points) {
            this->_hit_points = 0;
            std::cout << "ClapTrap " << this->_name << " is game over!" << std::endl;
        }
        else {
            this->_hit_points -= amount;
            std::cout << "ClapTrap " << this->_name << " is attack!" << std::endl;
        }
    }
    else {
        std::cout << "ClapTrap " << this->_name << " energy points is zero" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hit_points == 0) {
        std::cout << "ClapTrap " << this->_name << " is already game over!" << std::endl;
        return ;
    }
    if (this->_energy_points > 0) {
        if (static_cast<unsigned long long>(this->_hit_points + amount) >= 4294967295)
            this->_hit_points = 4294967295;
        else
            this->_hit_points += amount;
        this->_energy_points--;
        std::cout << "ClapTrap " << this->_name << " is repaired" << std::endl;
    }
    else {
        std::cout << "ClapTrap " << this->_name << "energy points is zero!" << std::endl;
        return ;
    }
}

unsigned int	ClapTrap::getDamage(void) const {
	return (this->_attack_damage);
}
