/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:53:13 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/04 16:16:57 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void) {
	Phonebook	PB;

	std::string input;
	int cnt = 0;
	while (true) {
		PB.PrintCMD();
		std::getline(std::cin, input);
		if (std::cin.good()) ;
		else if (std::cin.fail()) {
			std::cout << "you enter fail input" << std::endl;
			return (0);
		}
		if (input == "EXIT" || input == "exit")
			break;
		else if (input == "ADD" || input == "add") {
			if (cnt < 8) {
				cnt = PB.Add(cnt);
				if (cnt == -1)
					return (0);
			}
			else {
				std::cout << "PHONEBOOK IS FULL" << std::endl;
				if(!(cnt = PB.OldestDelete()))
					return 0;
				else {
					cnt = PB.Add(cnt);
					if (cnt == -1)
						return (0);
					std::cout << cnt << std::endl;
				}
			}
		}
		else if (input == "SEARCH" || input == "search")
		{
			int flag = PB.Search(cnt);
			if (flag == -1)
				return (0);
		}
		else
			std::cout << "wrong input : " << input << std::endl;
	}
	return (0);
}