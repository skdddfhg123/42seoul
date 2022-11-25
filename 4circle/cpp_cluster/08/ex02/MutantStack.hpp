/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 08:58:28 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/17 09:02:45 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T> 
{
public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator begin() {return this->c.begin();}

	iterator end() {return this->c.end();}

	const_iterator cbegin() const {return this->c.cbegin();}

	const_iterator cend() const {return this->c.cend();}

	reverse_iterator rbegin() {return this->c.rbegin();}

	reverse_iterator rend() {return this->c.rend();}

	const_reverse_iterator crbegin() const {return this->c.crbegin();}

	const_reverse_iterator crend() const { return this->c.crend(); }

	MutantStack& operator=(const MutantStack& ref)
	{
		if (this != &ref)
			std::stack<T>::operator=(ref);
		return *this;
	}
	MutantStack() {};
	MutantStack(const MutantStack& ori) { *this = ori; };
	~MutantStack() {};
};

#endif