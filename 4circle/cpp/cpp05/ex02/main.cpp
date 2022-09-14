/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:57:37 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 10:50:38 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	{
		std::cout << "=================PresidentialPardonFormTest ========================" << std::endl;
		Bureaucrat aTest("ATEST", 1);
		Bureaucrat bTest("BTEST", 150);
		
		PresidentialPardonForm aForm("PRE_AFORM");
		PresidentialPardonForm bForm("PRE_BFORM");

		aTest.signForm(aForm);
		aTest.executeForm(aForm);
		std::cout << std::endl;
		std::cout << "-------------------EXPECTED FAIL------------------------" << std::endl;
		bTest.executeForm(aForm);
		bTest.signForm(aForm);
		bTest.executeForm(bForm);
		bTest.signForm(bForm);
		aTest.executeForm(bForm);
	}
	{
		std::cout << std::endl;
		std::cout << "===================RobotomyRequestFormTest ========================" << std::endl;
		Bureaucrat aTest("ATEST", 1);
		Bureaucrat bTest("BTEST", 150);

		RobotomyRequestForm aForm( "ROB_AFORM" );
		RobotomyRequestForm bForm( "ROB_BFORM" );

		aTest.signForm(aForm);
		aTest.executeForm(aForm);
		std::cout << std::endl;
		std::cout << "------------------EXPECTED FAIL-------------------" << std::endl;
		bTest.executeForm(aForm);
		bTest.signForm(aForm);
		bTest.executeForm(bForm);
		bTest.signForm(bForm);
		aTest.executeForm(bForm);
	}
	{
		std::cout << std::endl;
		std::cout << "=========================ShrubberyCreationFormTest ========================" << std::endl;
		Bureaucrat aTest("ATEST", 1);
		Bureaucrat bTest("BTEST", 150);

		ShrubberyCreationForm aForm("SHR_AFORM");
		ShrubberyCreationForm bForm("SHR_BFORM");

		aTest.signForm(aForm);
		aTest.executeForm(aForm);
		std::cout << std::endl;
		std::cout << "----------------------EXPECTED FAIL------------------" << std::endl;
		bTest.signForm(bForm);
		bTest.executeForm(aForm);
		bTest.signForm(aForm);
		bTest.executeForm(bForm);
		bTest.signForm(bForm);
		aTest.executeForm(bForm);
	}
}