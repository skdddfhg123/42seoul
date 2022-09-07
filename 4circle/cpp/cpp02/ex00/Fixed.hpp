/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:09:14 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/08 01:17:14 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_bits;
public:
	Fixed(void);
	Fixed(const Fixed &val);
	~Fixed(void);
	Fixed& operator=(const Fixed &val);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
