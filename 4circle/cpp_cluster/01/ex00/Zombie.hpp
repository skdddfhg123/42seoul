/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:20:57 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/07 15:15:20 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie {
private:
	std::string Name;
public:
	Zombie(std::string name);
	void announce(void);
	~Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif