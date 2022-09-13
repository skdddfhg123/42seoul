/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:57:37 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 03:15:25 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		try {
			Bureaucrat test("test", -1);
		}
		catch(const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		Bureaucrat test1("Test1", 1);
		Bureaucrat test2("Test2", 150);

		std::cout << test1 << std::endl;
		test1.incrementGrade();
		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		// test2.decrementGrade();
		std::cout << test2 << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat test3("test3", -1);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	// Bureaucrat test3("test3", -1);
}