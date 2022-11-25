/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:36:12 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/07 15:26:02 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *newzombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::string tmp = "1";
		tmp[0] += i;
		newzombie[i].setName(name + tmp);
	}
	return newzombie;
}
