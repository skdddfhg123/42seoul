/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 03:07:07 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 11:08:54 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		const std::string	_type;
		bool 				_signed;
		const int 			_sign_grade;
		const int 			_exec_grade;
	public:
		Form();
		Form(const std::string name, const int& sign_grade, const int& exec_grade);
		Form(const Form&src);
		virtual ~Form();
		Form& operator=(const Form& src);

		const std::string& getName() const;
		const int& getSignGrade() const;
		const int& getExecGrade() const;
		const bool& getSigned() const;

		void beSigned(const Bureaucrat& src);

		const std::string& getType() const;
		void setType(const std::string& type);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void executeValidation(Bureaucrat const &b) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
				const char *what( void ) const throw();
		};
		class NoSignExecption : public std::exception {
			public:
				const char *what() const throw();
		};
		class FileErrorException : public std::exception {
		public:
			const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& ori);

#endif
