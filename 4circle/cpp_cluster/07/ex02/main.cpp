/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:52:43 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/17 02:52:49 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define LEN   5
int main(void) {
  std::cout << "---------- int ----------" << std::endl;
  try {
    Array<int> arrayInt(LEN);
    for (int i = 0; i < LEN; i++)
      arrayInt[i] = i + 1;
    for (int i = 0; i < LEN; i++)
      std::cout << arrayInt[i] << " ";
    std::cout << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "---------- const int ----------" << std::endl;
  try {
    const Array<int> arrayInt(LEN);
    for (int i = 0; i < LEN; i++)
      arrayInt[i] = i + 1;
    for (int i = 0; i < LEN; i++)
      std::cout << arrayInt[i] << " ";
    std::cout << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "---------- double ----------" << std::endl;
  try {
    Array<double> arrayDouble(LEN);
    for (int i = 0; i < LEN; i++)
      arrayDouble[i] = (i + 1) * 1.1;
    for (int i = 0; i < LEN; i++)
      std::cout << arrayDouble[i] << " ";
    std::cout << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "---------- error: [] ----------" << std::endl;
  try {
    Array<int> arrayInt(LEN);
    for (int i = 0; i < LEN; i++)
      arrayInt[i] = i + 1;
    std::cout << arrayInt[LEN];
    std::cout << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}