/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:28:20 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 16:41:59 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap frag("frag");
	ScavTrap scav("scav");

	std::cout << std::endl;
	scav.guardGate();
	std::cout << std::endl;
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	std::cout << std::endl;
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	std::cout << std::endl;
	scav.beRepaired(10);
	std::cout << std::endl;
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	std::cout << std::endl;
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	std::cout << std::endl;
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	std::cout << std::endl;
	scav.beRepaired(10);
	std::cout << std::endl;
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	std::cout << std::endl;
}