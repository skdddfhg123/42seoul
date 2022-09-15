/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:15 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 18:34:29 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {
	std::cout << "identify(Base* p) is called\nType: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	std::cout << "identify(Base& p) is called\nType: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch(...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch(...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch(...) {}
}


Base* generate(void) {
	int	rd = rand() % 3;
	if (rd == 0) {
		std::cout << "Generate creates A" << std::endl;
		return (new A());
	}
	else if (rd == 1) {
		std::cout << "Generate creates B" << std::endl;
		return (new B());
	}
	else {
		std::cout << "Generate creates C" << std::endl;
		return (new C());
	}
}

int main() {
	srand(time(NULL));
	Base *ptr;
	ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
}