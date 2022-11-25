/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:26:35 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/14 08:43:46 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {
	setType("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form(target, S_Sign, S_Exec) {
	setType("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) 
	: Form(src.getName(), src.getSignGrade(), src.getExecGrade()) {
	setType("ShrubberyCreationForm");
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	Form::operator=(src);
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& src) const
{
	executeValidation(src);
	std::ofstream out(this->getName() + "_shrubbery");
	if (out.fail())
		throw FileErrorException();
	std::string tree =	"              # #### ####\n"
						"            ### \\/#|### |/####\n"
						"           ##\\/#/ \\||/##/_/##/_#\n"
						"         ###  \\/###|/ \\/ # ###\n"
						"       ##_\\_#\\_\\## | #/###_/_####\n"
						"      ## #### # \\ #| /  #### ##/##\n"
						"       __#_--###`  |{,###---###-~\n"
						"                 \\ }{\n"
						"                  }}{\n"
						"                  }}{\n"
						"                  {{}\n"
						"            , -=-~{ .-^- _";
	out << tree;
	out.close();
}
