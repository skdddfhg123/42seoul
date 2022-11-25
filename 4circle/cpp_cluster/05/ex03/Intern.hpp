/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:10:10 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 11:17:45 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern& operator=(const Intern& src);

		Form* makeForm(const std::string name, const std::string target);

		Form* CreatePresidentialPardonForm(std::string &target);
		Form* CreateRobotomyRequestForm(std::string &target);
		Form* CreateShrubberyCreationForm(std::string &target);

		class NoNameException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif