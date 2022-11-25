/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:18:22 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/17 07:55:23 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {
    this->v.reserve(N);
}

Span::Span(const Span& obj) {
    *this = obj;
}

Span& Span::operator=(const Span& src) {
    if (this != &src) {
        this->N = src.N;
        this->v = src.v;
    }
  return (*this);
}

Span::~Span() {}

int Span::shortestSpan() const {
    if (this->v.size() < 2)
        throw Span::OutOfBoundException();
    int diff = INT_MAX;
    for (size_t i = 0; i < v.size() - 1; i++) {
        for (size_t j = i + 1; j < v.size() - 1; j++) {
            if (diff > abs(v[i] - v[j]))
                diff = abs(v[i] - v[j]);
        }
    }
    return (diff);
}

int Span::longestSpan() const {
    if (this->v.size() < 2)
        throw Span::OutOfBoundException();
    int max = *std::max_element(this->v.begin(), this->v.end());
    int min = *std::min_element(this->v.begin(), this->v.end());
    return (max - min);
}

void Span::addNumber(int number) {
    if (this->v.size() == this->v.capacity())
        throw Span::OutOfBoundException();
    this->v.push_back(number);
}

const char* Span::OutOfBoundException::what() const throw() {
    return ("Out of Bound Error");
}

const char* Span::AlreadyFullException::what() const throw() {
    return ("Already Full Error");
}