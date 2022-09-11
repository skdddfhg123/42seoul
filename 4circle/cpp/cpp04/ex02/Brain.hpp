/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:04:49 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 20:46:00 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();

		Brain&  operator=(const Brain &src);

		const std::string *getIdea() const;
		void show(void) const;
};

#endif