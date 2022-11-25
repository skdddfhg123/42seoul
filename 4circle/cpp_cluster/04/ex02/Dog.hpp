/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:46:07 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:50:29 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &ori);
		virtual ~Dog();

		Dog& operator=(const Dog &ref);
		
		virtual void makeSound(void) const;

		Brain*	getBrain() const;
};

#endif