/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 03:03:53 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/05 03:28:05 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type_) {
	type = type_;
}

Weapon::~Weapon() {
}

const std::string& Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}