/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:36:08 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 19:39:08 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal const &src);
		Animal(std::string type);
		virtual ~Animal();
		Animal& operator=(Animal const &src);

		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif