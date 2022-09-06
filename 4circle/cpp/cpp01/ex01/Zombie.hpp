/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:20:57 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/06 11:34:09 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie {
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	void announce(void);
	void setName(std::string name);
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif