/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:30:32 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/06 12:18:20 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <fstream>

void	Writeline(bool &flag,
				std::ofstream &writeFile,
				std::string line,
				std::string to_change) {
	if (flag) {
		writeFile << line << to_change;
		flag = false;
	}
	else
		writeFile << std::endl << line << to_change;
}

void	Transform(std::ifstream &readFile,
				std::ofstream &writeFile,
				const std::string& s1,
				const std::string& s2) {
	std::string	to_find(s1);
	std::string	to_change(s2);
	std::string	line;
	bool		flag = true;
	
	while (std::getline(readFile, line)) {
		size_t	Next = line.find(to_find);

		if (Next == std::string::npos)
			Writeline(flag, writeFile, line, "");
		else {
			Writeline(flag, writeFile, line.substr(0, Next), to_change);
			std::string	nextLine = line.substr(Next + to_find.length());
			Next = nextLine.find(to_find);
			while (Next != std::string::npos) {
				writeFile << nextLine.substr(0, Next) << to_change;
				nextLine = nextLine.substr(Next + to_find.length());
				Next = nextLine.find(to_find);
			}
			writeFile << nextLine;
		}
	}
}

void	Replace(const std::string& filename,
				const std::string& s1,
				const std::string& s2) {
	std::ifstream	readfile(filename);
	if (!(readfile.is_open())) {
		std::endl(std::cout << "Error: Read file.");
		return ;
	}
	
	std::ofstream	writefile(filename + ".replace");
	if (writefile.fail()) {
		std::cerr << "Error: Write file\n";
		readfile.close();
		return ;
	}
	
	Transform(readfile, writefile, s1, s2);
	readfile.close();
	writefile.close();
}

int main(int ac, char **av) {
	if (ac != 4 || !av[1] || !av[2] || !av[3])
		std::cout << "Please enter as follows. \n./Replace <filename> <s1> <s2>" << std::endl;
	else
		Replace(av[1], av[2], av[3]);
	return (0);
}
