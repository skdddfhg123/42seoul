/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:36:57 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/11 12:49:16 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const & src);
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int att);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);

		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		unsigned int	getDamage(void) const;
};

#endif