/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:32:49 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 08:32:45 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form() {
	setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form(target, R_Sign, R_Exec) {
	setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) 
	: Form(src.getName(), src.getSignGrade(), src.getExecGrade()) {
	setType("RobotomyRequestForm");
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	Form::operator=(src);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& src) const
{
	executeValidation(src);
	std::cout << "wiiiiiiiiing~" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->getName() << " has been robotomized" << std::endl;
	else
		std::cout << this->getName() << " has been failed to robotomized" << std::endl;
}