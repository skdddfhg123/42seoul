/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:57:37 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 11:22:46 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	{
		std::cout << "==================<<Wrong Form Test>> ========================"
				  << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat TestA( "TestA", 1 );
		Bureaucrat TestB( "TestB", 150 );
		try {
			rrf = someRandomIntern.makeForm( "presidential", "Bender" );
			std::cout << "-------------EXPECTED FAIL---------------" << std::endl;
			TestB.signForm( *rrf );
			TestA.executeForm( *rrf );
			std::cout << "----------------EXPECTED SUCCESS-----------" << std::endl;
			TestA.signForm( *rrf );
			TestA.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "================PresidentialPardonFormTest================" << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat TestA( "TestA", 1 );
		Bureaucrat TestB( "TestB", 150 );
		try {
			rrf = someRandomIntern.makeForm( "presidential pardon", "Bender" );
			std::cout << "----------------EXPECTED FAIL--------------------" << std::endl;
			TestB.signForm( *rrf );
			TestA.executeForm( *rrf );
			std::cout << "----------------EXPECTED SUCCESS-----------------" << std::endl;
			TestA.signForm( *rrf );
			TestA.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	

	{
		std::cout << "================RobotomyRequestFormTest================"
				  << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat TestA( "TestA", 1 );
		Bureaucrat TestB( "TestB", 150 );
		try {
			rrf = someRandomIntern.makeForm( "robotomy request", "Bender" );
			std::cout << "----------------EXPECTED FAIL--------------------" << std::endl;
			TestB.signForm( *rrf );
			TestA.executeForm( *rrf );
			std::cout << "----------------EXPECTED SUCCESS-----------------" << std::endl;
			TestA.signForm( *rrf );
			TestA.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "================ShrubberyFormTest================" << std::endl;
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat TestA( "TestA", 1 );
		Bureaucrat TestB( "TestB", 150 );
		try {
			rrf = someRandomIntern.makeForm( "shrubbery creation", "Bender" );
			std::cout << "----------------EXPECTED FAIL--------------------" << std::endl;
			TestB.signForm( *rrf );
			TestA.executeForm( *rrf );
			std::cout << "----------------EXPECTED SUCCESS-----------------" << std::endl;
			TestA.signForm( *rrf );
			TestA.executeForm( *rrf );
		} catch ( const std::exception &e ) {
			rrf = NULL;
			std::cerr << e.what() << std::endl;

			if ( rrf )
				delete rrf;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}