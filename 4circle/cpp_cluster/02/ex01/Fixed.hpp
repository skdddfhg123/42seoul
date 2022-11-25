/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:40:15 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/08 01:17:19 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_value;
	static const int	_bits;
public:
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &val);
	~Fixed(void);
	Fixed& operator=(Fixed const &val);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &val);

#endif
