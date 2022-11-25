/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:53:10 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/05 14:16:09 by dongmlee         ###   ########.fr       */
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
	int			_i;
public:
	Phonebook(void);
	int			getIndex(void);
	void		setIndex(int i);
	void		PrintCMD(void);
	void		PrintContact(int i);
	int			Search(void);
	int			OldestDelete(void);
	int			Add(void);
	int			Insert(void);
	std::string	CutString(std::string str);
	~Phonebook(void);
};

#endif