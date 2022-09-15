/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckType.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:36:05 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 18:37:25 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKTYPE_HPP
# define CHECKTYPE_HPP

#include <iostream>

enum {
	TYPE_ERROR = 0,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_INT_OVERFLOW,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	MAX_TYPE
};

int	CheckType(std::string str);

#endif