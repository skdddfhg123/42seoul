/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:38 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/06 11:23:52 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	Name = name;
}

void Zombie::announce(void) {
	std::endl(std::cout << Name << ": BraiiiiiiinnnzzzZ...");
}

Zombie::~Zombie() {
	std::cout << Name << ": has been killed" << std::endl;
}
