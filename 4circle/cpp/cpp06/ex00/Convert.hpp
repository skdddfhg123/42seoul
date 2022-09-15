/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:34:27 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 18:42:36 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <cmath>
#include <exception>
#include <iomanip>

#include "CheckType.hpp"

enum {
	TYPE_ERROR = 0,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_INT_OVERFLOW,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	MAX_TYPE
};

class Convert {
	private:
		std::string		_raw;
		int				_type;
		char			_c;
		bool			_c_overflow;
		long			_i;
		float			_f;
		double			_d;

		void	convertToActualType();
		void	convertToOtherType();

	public:
		Convert();
		Convert(std::string raw);
		Convert(const Convert& src);
		~Convert();
		Convert& operator=(Convert const &src);

		std::string getInput() const;

		int getType() const;
		char getChar() const;
		bool getCharOver() const;
		long getInt() const;
		float getFloat() const;
		double getDouble() const;
};

std::ostream& operator<<(std::ostream& out, const Convert& src);

#endif