/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 03:07:07 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 12:47:52 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool 				_signed;
		const int 			_sign_grade;
		const int 			_exec_grade;
	public:
		Form();
		Form(const std::string name, const int& sign_grade, const int& exec_grade);
		Form(const Form&src);
		~Form();
		Form& operator=(const Form& src);

		const std::string& getName() const;
		const int& getSignGrade() const;
		const int& getExecGrade() const;
		const bool& getSigned() const;
		
		void beSigned(const Bureaucrat& src);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
				const char *what( void ) const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif
