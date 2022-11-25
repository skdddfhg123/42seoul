/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:35:32 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 21:20:41 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckType.hpp"

static bool isChar(std::string str) {
	const int len = str.length();
	if (len != 1 && len != 3)
		return (false);
	if (len == 1 && isdigit(str[0]))
		return (false);
	if (len == 3 && str[0] != '\'' && str[2] != '\'')
		return (false);
	return (true);
}

static int isInt(std::string str) {
	char* end = NULL;
	long l = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0') {
		if ((l > std::numeric_limits<int>::max())
		||  (l < std::numeric_limits<int>::min()))
			return TYPE_INT_OVERFLOW;
		return TYPE_INT;
	}
	return TYPE_ERROR;
}

static bool isFloat(std::string str) {
	char* end = NULL;
	std::strtod(str.c_str(), &end);
	if (strlen(end) != 1 || *end != 'f')
		return false;
	return true;
}

static bool isDouble(std::string str) {
	char* end = NULL;
	std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return false;
	return true;
}

int CheckType(std::string str) {
	int type;

	if (str.empty())
		return TYPE_ERROR;
	if (isChar(str))
		return TYPE_CHAR;
	if (TYPE_ERROR != (type = isInt(str)))
		return type;
	if (isFloat(str))
		return TYPE_FLOAT;
	if (isDouble(str))
		return TYPE_DOUBLE;
	return TYPE_ERROR;
}