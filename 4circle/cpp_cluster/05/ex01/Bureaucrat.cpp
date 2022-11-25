/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:52:17 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 04:02:27 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _grade(0) {
}

Bureaucrat::Bureaucrat(const std::string name, const int& grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade()) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		*(const_cast<std::string*>(&_name)) = src.getName();
		this->_grade = src.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName() const {
	return (_name);
}

const int& Bureaucrat::getGrade() const {
	return (_grade);
}

int& Bureaucrat::incrementGrade() {
	if (_grade -1 < 1)
		throw GradeTooHighException();
	return (--_grade);
}

int& Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	return (++_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

void Bureaucrat::signForm(const Form& src) const
{
	try {
		(*const_cast<Form*>(&src)).beSigned(*this);
		std::cout << _name << " signed " << src.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << _name << " couldn't sign " << src.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src) {
	return out << src.getName() << ", bureaucrat grade " << src.getGrade();
}