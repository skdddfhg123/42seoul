/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 03:07:57 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 10:45:09 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _type("Form") , _sign_grade(0), _exec_grade(0) {}

Form::Form(const std::string name, const int& sign_grade, const int& exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src) : _type("Form"), _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade()) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form& Form::operator=(const Form& src) {
	if (this != &src) {
		*(const_cast<std::string*>(&_name)) = src.getName();
		*(const_cast<int*>(&_sign_grade)) = src.getSignGrade();
		*(const_cast<int*>(&_exec_grade)) = src.getExecGrade();
		setType(src.getType());
		this->_signed = src.getSigned();
	}
	return (*this);
}

const std::string& Form::getName() const {
	return (_name);
}

const int& Form::getSignGrade() const {
	return (_sign_grade);
}

const int& Form::getExecGrade() const {
	return (_exec_grade);
}

const bool& Form::getSigned() const {
	return (_signed);
}

const std::string& Form::getType() const {
	return (_type);
}

void Form::beSigned(const Bureaucrat& src) {
	if (_signed == true)
		throw Form::AlreadySignedException();
	if (src.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw Form::GradeTooHighException();
}

void Form::setType(const std::string& type) {
	*(const_cast<std::string*>(&_type)) = type;
}

void Form::executeValidation( Bureaucrat const &b ) const {
	if (_signed == false)
		throw Form::NoSignExecption();
	if (getExecGrade() < b.getGrade() )
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form Grade Too Low");
}

const char* Form::AlreadySignedException::what() const throw() {
	return ("Already Signed");
}

const char* Form::NoSignExecption::what() const throw() {
	return ("Form No Signed");
}

const char* Form::FileErrorException::what() const throw() {
	return ("File Error");
}

std::ostream& operator<<(std::ostream& out, const Form& src) {
	return (out << src.getName() << std::boolalpha << ", Form sign grade " << src.getSignGrade()
		<< ", Form exec grade " << src.getExecGrade() << ", Form sign " << src.getSigned());
}
