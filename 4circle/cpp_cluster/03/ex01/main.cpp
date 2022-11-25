/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:28:20 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 16:41:35 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap clap("clap");
	ScavTrap trap("trap");

	std::cout << std::endl;
	clap.guardGate();
	trap.guardGate();
	std::cout << std::endl;
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
	trap.beRepaired(10);
	std::cout << std::endl;
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
	trap.beRepaired(10);
	std::cout << std::endl;
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
}