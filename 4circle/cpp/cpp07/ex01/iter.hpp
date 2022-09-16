#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T* arr, int len, void (*f)(const T& src)) {
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void println(const T& x) {
    std::cout << x << std::endl;
}

#endif