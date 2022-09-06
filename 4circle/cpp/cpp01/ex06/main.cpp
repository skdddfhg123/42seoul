/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:22:38 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/07 03:54:29 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	Harl Harl;

	if (ac != 2) {
		std::endl(std::cout << "Please enter as follows\n./Harl [SOMETHING]");
		return (0);
	}
	std::string filter(av[1]);
	if (!(filter == "DEBUG" || filter == "INFO" || filter == "WARNING" || filter == "ERROR")) {
		std::endl(std::cout << "[ Probably complaining about insignificant problems ]");
		return (0);
	}
	Harl.complain(av[1]);
	return (0);
}
