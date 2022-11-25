/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:21:42 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/08 03:51:10 by idongmin         ###   ########.fr       */
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

	bool	operator>(Fixed const &val) const;
	bool	operator<(Fixed const &val) const;
	bool	operator>=(Fixed const &val) const;
	bool	operator<=(Fixed const &val) const;
	bool	operator==(Fixed const &val) const;
	bool	operator!=(Fixed const &val) const;

	Fixed	operator+(Fixed const &val) const;
	Fixed	operator-(Fixed const &val) const;
	Fixed	operator*(Fixed const &val) const;
	Fixed	operator/(Fixed const &val) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);
	
	static Fixed&		min(Fixed & val1, Fixed & val2);
	static Fixed const&	min(Fixed const & val1, Fixed const & val2);
	static Fixed&		max(Fixed & val1, Fixed & val2);
	static Fixed const&	max(Fixed const & val1, Fixed const & val2);
};

std::ostream& operator<<(std::ostream &out, const Fixed &val);

#endif
