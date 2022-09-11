/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:02 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:52:03 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();

		Cat& operator=(const Cat &src);

		virtual void makeSound(void) const;

		Brain*	getBrain() const;
};

#endif
