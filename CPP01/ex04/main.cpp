/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 03:28:17 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 04:37:05 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int		main(int ac, char **av) {

	std::string		s1;
	std::string		s2;
	std::string		filename;
	std::string		extension;
	std::string		buff;
	std::string 	token;
	size_t 			pos = 0;

	if (ac != 4) {
		std::cout << "Error: You must have ./replace [filename] [string 1] [string 2]" << std::endl;
		return (1);
	}
	s1 = av[2];
	s2 = av[3];
	if (s1.size() == 0 || s2.size() == 0) {
		std::cout << "Error: empty string." << std::endl;
		return (1);
	}
	else {
		std::ifstream	ifs(av[1]);
		if (!ifs) {
			std::cout << "This file doesn't exist." << std::endl;
			return (1);
		}
		extension = ".replace";
		filename = av[1] + extension;
		std::ofstream	ofs(filename.c_str());
		while (!ifs.eof())
		{
			std::getline(ifs, buff);
			while ((pos = buff.find(s1)) != std::string::npos) {
    			token = buff.substr(0, pos);
    			ofs << token << s2;
    			buff.erase(0, pos + s1.length());
			}
			
			ofs << buff << std::endl;
		}
		ofs.close();
		ifs.close();
	}
	return (0);
}