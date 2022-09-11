/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:25:56 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/09 17:10:14 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");

	std::cout << std::endl;
	clap.attack("Tlap");
	trap.takeDamage(clap.getDamage());
	std::cout << std::endl;
	trap.attack("Clap");
	clap.takeDamage(trap.getDamage());
	std::cout << std::endl;
	clap.beRepaired(25);
	std::cout << std::endl;
	return (0);
}