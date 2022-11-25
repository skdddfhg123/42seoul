/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 06:56:49 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/17 08:11:45 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>
#include <limits>

class Span {
    private:
        unsigned int        N;
        std::vector<int>    v;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        void addNumber(int number);
        template <typename T>
        void addNumber(T begin, T end) {
            if (static_cast<unsigned long long>(std::distance(begin, end)) > this->N - this->v.size())
                throw Span::AlreadyFullException();
            while (begin != end)
                this->v.push_back(*(begin++));
        }
        
        int shortestSpan() const;
        int longestSpan() const;
        
        class AlreadyFullException : public std::exception {
            const char* what() const throw();
        };

        class OutOfBoundException : public std::exception {
            const char* what() const throw();
        };
};

#endif