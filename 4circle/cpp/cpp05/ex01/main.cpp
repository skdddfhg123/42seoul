/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:57:37 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 04:06:37 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat bure("bureaucrat", 10);
	try {
		Form test("propose 1", 1, 10);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form test("propose 1", 10, 151);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form1("propose 1", 10, 10);
		std::cout << form1 << std::endl;
		bure.signForm(form1);
		std::cout << form1 << std::endl;
		bure.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		Form form2("propose 2", 9, 10);
		bure.signForm(form2);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}