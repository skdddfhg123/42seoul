/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:23:14 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 18:57:48 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

struct Data
{
	std::string	name;
	float		number;
};

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int	main() {
	Data data = {
		"dongmlee",
		42.42
	};

	uintptr_t serialized = serialize(&data);
	Data* deserialized = deserialize(serialized);

	std::cout << &data << std::endl;
	std::cout << deserialized << std::endl;

	std::cout << "===before===" << std::endl;
	std::cout << data.name << std::endl;
	std::cout << data.number << std::endl;
	std::cout << "===after===" << std::endl;
	std::cout << deserialized->name << std::endl;
	std::cout << deserialized->number << std::endl;
}
