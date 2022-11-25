/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:53:13 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/04 17:42:02 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void) {
	Phonebook	PB;

	std::string input;
	int flag = 0;
	while (true) {
		PB.PrintCMD();
		std::getline(std::cin, input);
		if (std::cin.good()) ;
		else if (std::cin.fail()) {
			std::cout << "you enter fail input" << std::endl;
			return (0);
		}
		if (input == "EXIT" || input == "exit")
			break ;
		else if (input == "ADD" || input == "add") {
			flag = PB.Add();
			if (flag == -1)
				return (0);
		}
		else if (input == "SEARCH" || input == "search")
		{
			flag = PB.Search();
			if (flag == -1)
				return (0);
		}
		else
			std::cout << "wrong input : " << input << std::endl;
	}
	return (0);
}