/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:52:29 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/17 02:52:29 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T& min(const T& a, const T& b) {
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
const T& max(const T& a, const T& b) {
    if (a > b)
        return (a);
    return (b);
}

#endif