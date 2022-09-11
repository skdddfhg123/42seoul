/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:28:20 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 12:44:01 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap clap("clap");
	ScavTrap trap("trap");

	clap.guardGate();
	trap.guardGate();
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	trap.beRepaired(10);
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
	trap.beRepaired(10);
	clap.attack("trap");
	trap.takeDamage(clap.getDamage());
}