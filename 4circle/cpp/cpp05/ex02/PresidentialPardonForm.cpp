/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:11:24 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 08:32:13 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form() {
	setType("PesidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form(target, P_Sign, P_Exec){
	setType("PesidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) 
	: Form(src.getName(), src.getSignGrade(), src.getExecGrade()) {
	setType("PesidentialPardonForm");
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	Form::operator=(src);
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& src) const {
	executeValidation(src);
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
