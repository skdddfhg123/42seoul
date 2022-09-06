/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:36:12 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/06 11:40:35 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *newzombie = new Zombie[N];
	std::string tmp = "";
	for (int i = 0; i < N; i++)
	{
		std::string tmp = "0";
		tmp[0] += i;
		newzombie[i].setName(name + tmp);
	}
	return newzombie;
}
