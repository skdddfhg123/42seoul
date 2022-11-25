/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:03:37 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 06:32:26 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int 				_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int& grade);
		Bureaucrat(const Bureaucrat&src);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& src);

		const std::string& getName() const;
		const int& getGrade() const;

		int& incrementGrade();
		int& decrementGrade();

		void signForm(const Form& ref) const;

		void executeForm(Form const &form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif
