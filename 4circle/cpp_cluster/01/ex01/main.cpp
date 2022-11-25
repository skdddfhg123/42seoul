/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:29:54 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/07 15:19:37 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *zombie;

	zombie = zombieHorde(7, "Zombie");
	for (int i = 0; i < 7; i++)
		zombie[i].announce();
	delete []zombie;
	system("leaks Zombie");
	return (0);
}