/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:35:28 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/11 21:17:17 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal *test[4];
	std::cout << std::endl;
	test[0] = new Dog();
	std::cout << std::endl;
	test[1] = new Dog();
	std::cout << std::endl;
	test[2] = new Cat();
	std::cout << std::endl;
	test[3] = new Cat();
	std::cout << std::endl;

	std::cout << "##############Make Sound##############" << std::endl;
	std::cout << "Test dog1" << std::endl;
	test[0]->makeSound();
	std::cout << "Test dog2" << std::endl;
	test[1]->makeSound();
	std::cout << "Test cat1" << std::endl;
	test[2]->makeSound();
	std::cout << "Test cat2" << std::endl;
	test[3]->makeSound();
	std::cout << std::endl;
	
	std::cout << "=====================================" << std::endl;
	for (int i = 0; i < 4; i++)
		delete test[i];
	std::cout << std::endl;
	
	std::cout << "##############Check Dog##############" << std::endl;
	Dog	*dog1 = new Dog();
	std::cout << std::endl;
	Dog	dog2(*dog1);
	std::cout << std::endl;
	std::cout << dog1->getType() << std::endl;
	std::cout << std::endl;
	delete	dog1;
	std::cout << std::endl;
	
	std::cout << "=====================================" << std::endl;
	dog2.getBrain()->show();
	std::cout << std::endl;
	dog2.makeSound();
	std::cout << std::endl;
	
	std::cout << "##############Check Cat##############" << std::endl;
	Cat	*cat1 = new Cat();
	std::cout << std::endl;
	Cat	cat2(*cat1);
	std::cout << std::endl;
	std::cout << cat1->getType() << std::endl;
	std::cout << std::endl;
	delete	cat1;
	std::cout << std::endl;
	
	std::cout << "=====================================" << std::endl;
	cat2.getBrain()->show();
	std::cout << std::endl;
	cat2.makeSound();
	std::cout << std::endl;
	
	std::cout << "=====================================" << std::endl;
	Animal a;
	std::cout << std::endl;
	a.makeSound();
	system("leaks Brain");
}