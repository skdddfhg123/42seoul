/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:53:10 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/04 16:26:28 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact(void);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);
	std::string	getPhone(void);
	std::string	getSecret(void);
	void		clear(void);
	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickName(std::string str);
	void		setPhone(std::string str);
	void		setSecret(std::string str);
	~Contact(void);
};

class Phonebook {
private:
	Contact		contact[8];
public:
	Phonebook(void);
	void		PrintCMD(void);
	void		PrintContact(int i);
	int			Search(int cnt);
	int			OldestDelete(void);
	int			Add(int i);
	std::string	CutString(std::string str);
	~Phonebook(void);
};

#endif