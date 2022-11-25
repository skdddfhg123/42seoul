/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:15 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/15 21:30:38 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {
	std::cout << "pointer is call : ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	std::cout << "reference is call : ";
	try {
		A& a = dynamic_cast<A&>(p);
		p = dynamic_cast<Base&>(a);
		std::cout << "A" << std::endl;
		return ;
	} catch(const std::exception &e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		p = dynamic_cast<Base&>(b);
		std::cout << "B" << std::endl;
		return ;
	} catch(const std::exception &e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		p = dynamic_cast<Base&>(c);
		std::cout << "C" << std::endl;
		return ;
	} catch(const std::exception &e) {}
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