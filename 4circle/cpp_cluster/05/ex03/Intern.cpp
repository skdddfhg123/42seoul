/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:10:41 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 11:18:09 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
	static_cast<void>(src);
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& src) {
	static_cast<void>(src);
	return (*this);
}

Form* Intern::CreatePresidentialPardonForm(std::string &target) {
	return (new PresidentialPardonForm(target));
}

Form* Intern::CreateRobotomyRequestForm(std::string &target) {
	return (new RobotomyRequestForm(target));
}

Form* Intern::CreateShrubberyCreationForm(std::string &target) {
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	Form *(Intern:: *forms[3])(std::string &target) = {
		&Intern::CreatePresidentialPardonForm,
		&Intern::CreateRobotomyRequestForm,
		&Intern::CreateShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << names[i] << std::endl;
			return ((this->*(forms[i]))(target));
		}
	}
	throw Intern::NoNameException();

	return (nullptr);
}

const char* Intern::NoNameException::what() const throw() {
	return ("No match name");
}
