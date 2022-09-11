/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:28:20 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 13:18:24 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap frag("frag");
	ScavTrap scav("scav");

	scav.guardGate();
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	scav.beRepaired(10);
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
	scav.beRepaired(10);
	frag.attack("scav");
	scav.takeDamage(frag.getDamage());
}