#include <iostream>
#include <list>
#include "Span.hpp"

int main()
{
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Creating spA with size 0!" << std::endl;
	Span spA;
	try
	{
		std::cout << "trying to add 5 to spA: ";
		spA.addNumber(5);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	Span spB(5);
	try
	{
		std::cout << "trying to add 12 to spB: ";
		spB.addNumber(12);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 90 to spB: ";
		spB.addNumber(90);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 92 to spB: ";
		spB.addNumber(92);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 202 to spB: ";
		spB.addNumber(202);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add -5 to spB: ";
		spB.addNumber(-5);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 3 to spB: ";
		spB.addNumber(3);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Shortest span of SpB: " << spB.shortestSpan() << std::endl;
	std::cout << "Longest span of SpB: " << spB.longestSpan() << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	try
	{
		std::cout << "Shortest span of SpA: ";
		std::cout << spA.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest span of SpA: ";
		std::cout << spA.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Assigning spA = spB" << std::endl;
	spA = spB;
	try
	{
		std::cout << "Shortest span of SpA: ";
		std::cout << spA.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest span of SpA: ";
		std::cout << spA.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Creating spC with size 3!" << std::endl;
	Span spC(3);
	try
	{
		std::cout << "trying to add 42 to spC: ";
		spC.addNumber(42);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 42 to spC: ";
		spC.addNumber(42);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 21 to spC: ";
		spC.addNumber(21);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Shortest span of SpC: ";
	std::cout << spC.shortestSpan() << std::endl;
	std::cout << "Longest span of SpC: ";
	std::cout << spC.longestSpan() << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Creating Span spD(spC) - copy constructor" << std::endl;
	Span spD(spC);
	std::cout << "Shortest span of SpD: ";
	std::cout << spD.shortestSpan() << std::endl;
	std::cout << "Longest span of SpD: ";
	std::cout << spD.longestSpan() << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "BIG BOI TEST! Creating Span spE(25000) and filling it with random numbers" << std::endl;
	Span spE(25000);
	srand(time(NULL));
	for (int i = 0; i < 25000; i++)
		spE.addNumber(rand());
	std::cout << "Shortest span of SpE: ";
	std::cout << spE.shortestSpan() << std::endl;
	std::cout << "Longest span of SpE: ";
	std::cout << spE.longestSpan() << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "BIG BOI TEST2! Creating Span spF(25000) and filling it with consecutive numbers" << std::endl;
	Span spF(25000);
	std::vector<int> v;
	for (int i = 0; i < 25000; i++)
		v.push_back(i);
	try
	{
		spF.addNumber(v.begin(), v.end());
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Shortest span of SpF: ";
	std::cout << spF.shortestSpan() << std::endl;
	std::cout << "Longest span of SpF: ";
	std::cout << spF.longestSpan() << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	try
	{
		std::cout << "Trying to add JUST ONE MORE number to spF: ";
		spF.addNumber(5);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
