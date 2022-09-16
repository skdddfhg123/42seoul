/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:45:52 by dongmlee          #+#    #+#             */
/*   Updated: 2022/09/17 01:05:44 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
  std::cout << "=====int=====" << std::endl;
  int test1[5] = {1, 2, 3, 4, 5};
  iter<int>(test1, 5, println);
  std::cout << "=====float=====" << std::endl;
  float test2[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  iter<float>(test2, 5, println);
  std::cout << "=====double=====" << std::endl;
  double test3[5] = {1.11, 2.22, 3.33, 4.44, 5.55};
  iter<double>(test3, 5, println);
  std::cout << "=====string=====" << std::endl;
  std::string test4[5] = {"string1", "string2", "string3", "string4", "string5"};
  iter<std::string>(test4, 5, println);

  return (0);
}