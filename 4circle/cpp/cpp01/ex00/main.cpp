/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:19:25 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/06 11:28:20 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)	{
	Zombie	*zombie;

	randomChump("stack");
	zombie = newZombie("heap");
	zombie->announce();
	delete zombie;
	return (0);
}
