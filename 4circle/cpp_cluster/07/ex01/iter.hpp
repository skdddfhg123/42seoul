/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:52:24 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/17 02:52:25 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void    iter(const T* arr, int len, void (*f)(const T& src)) {
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void    println(const T& x) {
    std::cout << x << std::endl;
}

#endif