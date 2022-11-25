/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:53:12 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/05 14:14:01 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::setFirstName(std::string str) {
	first_name = str;
}

void	Contact::setLastName(std::string str) {
	last_name = str;
}

void	Contact::setNickName(std::string str) {
	nick_name = str;
}

void	Contact::setPhone(std::string str) {
	phone_number = str;
}

void	Contact::setSecret(std::string str) {
	darkest_secret = str;
}

std::string	Contact::getFirstName(void) {
	return (first_name);
}

std::string	Contact::getLastName(void) {
	return (last_name);
}

std::string	Contact::getNickName(void) {
	return (nick_name);
}

std::string	Contact::getPhone(void) {
	return (phone_number);
}

std::string	Contact::getSecret(void) {
	return (darkest_secret);
}

void	Contact::clear(void) {
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

int	Phonebook::getIndex(void) {
	return (_i);
}

void	Phonebook::setIndex(int i) {
	this->_i = i;
}

void	Phonebook::PrintCMD() {
	std::cout << "Please enter one of the commands on the right [ ADD | SEARCH | EXIT ]" << std::endl;
	std::cout << "> ";
};

std::string	Phonebook::CutString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

int		Phonebook::Search(void) {
	std::string input;
	int cnt = Phonebook::getIndex();

	if (cnt == 0) {
		std::cout << "Empty phone number" << std::endl;
		return (1);
	}
	std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(10) << "index"
	<< "|" << std::setfill(' ') << std::setw(10) << "first name"
	<< "|" << std::setfill(' ') << std::setw(10) << "last name"
	<< "|" << std::setfill(' ') << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < cnt; i++) {
		std::cout << "=============================================" << std::endl;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << CutString(contact[i].getFirstName());
		std::cout << "|" << std::setfill(' ') << std::setw(10) << CutString(contact[i].getLastName());
		std::cout << "|" << std::setfill(' ') << std::setw(10) << CutString(contact[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "=============================================" << std::endl;
	while (1) {
		std::cout << "Please enter the index to see full contact information: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.good()) ;
		else if (std::cin.fail()){
			std::cout << "you enter fail input" << std::endl;
			return (-1);
		}
		if (input[0] >= '1' && input[0] <= '8' && input[1] == '\0' && std::stoi(input) <= cnt) {
			std::cout << "First name      : " << contact[std::stoi(input) - 1].getFirstName() << std::endl;
			std::cout << "Last name       : " << contact[std::stoi(input) - 1].getLastName() << std::endl;
			std::cout << "Nickname        : " << contact[std::stoi(input) - 1].getNickName() << std::endl;
			std::cout << "Phone number    : " << contact[std::stoi(input) - 1].getPhone() << std::endl;
			std::cout << "Darkest secret  : " << contact[std::stoi(input) - 1].getSecret() << std::endl;
		}
		else {
			std::cout << "Please SEARCH again and enter a valid index number. " << std::endl;
			continue;
		}
		std::cout << std::endl;
		break;
	}
	return (1);
}

int		Phonebook::Insert(void) {
	std::string str;

	int i = Phonebook::getIndex();
	std::cout << "Please enter first name." << std::endl;
	getline(std::cin, str);
	if (std::cin.good()) ;
	else if (std::cin.fail()) {
		std::cout << "you enter fail input" << std::endl;
		return (-1);
	}
	if (str.empty()) {
		std::cout << "you enter empty input" << std::endl;
		return (i);
	}
	contact[i].setFirstName(str);
	std::cout << "Please enter last name." << std::endl;
	getline(std::cin, str);
	if (std::cin.good()) ;
	else if (std::cin.fail()) {
		std::cout << "you enter fail input" << std::endl;
		return (-1);
	}
	if (str.empty()) {
		std::cout << "you enter empty input" << std::endl;
		return (i);
	}
	contact[i].setLastName(str);
	std::cout << "Please enter nickname." << std::endl;
	getline(std::cin, str);
	if (std::cin.good()) ;
	else if (std::cin.fail()) {
		std::cout << "you enter fail input" << std::endl;
		return (-1);
	}
	if (str.empty()) {
		std::cout << "you enter empty input" << std::endl;
		return (i);
	}
	contact[i].setNickName(str);
	std::cout << "Please enter phone number." << std::endl;
	getline(std::cin, str);
	if (std::cin.good()) ;
	else if (std::cin.fail()) {
		std::cout << "you enter fail input" << std::endl;
		return (-1);
	}
	if (str.empty()) {
		std::cout << "you enter empty input" << std::endl;
		return (i);
	}
	contact[i].setPhone(str);
	std::cout << "Please enter darkest secret." << std::endl;
	getline(std::cin, str);
	if (std::cin.good()) ;
	else if (std::cin.fail()) {
		std::cout << "you enter fail input" << std::endl;
		return (-1);
	}
	if (str.empty()) {
		std::cout << "you enter empty input" << std::endl;
		return (i);
	}
	contact[i].setSecret(str);
	Phonebook::setIndex(i + 1);
	return (i);
}

int		Phonebook::Add(void) {
	int	cnt = Phonebook::getIndex();
	if (cnt < 8) {
		cnt = Phonebook::Insert();
		if (cnt == -1)
			return (-1);
	}
	else {
		std::cout << "PHONEBOOK IS FULL" << std::endl;
		if(!(cnt = Phonebook::OldestDelete()))
			return 0;
	}
	return (1);
}

int	Phonebook::OldestDelete(void)
{
	std::string input;

	std::cout << "will you delete the oldest contacts? [ YES, NO ]" << std::endl;
	getline(std::cin, input);
	if (std::cin.good()) ;
	else if (std::cin.fail()) {
		std::cout << "you enter fail input" << std::endl;
		return (-1);
	}
	if (input == "YES" || input == "yes") {
		for (int j = 1; j < 8; j++) {
			contact[j - 1] = contact[j];
		}
		contact[7].clear();
		std::cout << "removed successfully!" << std::endl;
		Phonebook::setIndex(7);
		Phonebook::Insert();
	}
	return (8);
}

Phonebook::Phonebook(void) {
	std::cout << "Opening Phone Book" << std::endl;
	_i = 0;
}

Phonebook::~Phonebook(void) {
	std::cout << "Closing Phone Book" << std::endl;
}
