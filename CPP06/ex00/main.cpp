/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:23:16 by wluong            #+#    #+#             */
/*   Updated: 2022/01/21 05:02:31 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>



void	print_char( double value, std::string arg ) {

	if (value < 0 || value > 255 || arg == "nan" || arg == "nanf") {
		std::cout << "char : impossible" << std::endl;
	}
	else {
		char c = static_cast<char>(value);
		if (!isprint(c)) {
			std::cout << "char: Non displayable" << std::endl;
		}
		else {
			std::cout << "char: '" << c << "'" << std::endl;
		}
	}
}

void	print_int( double value, std::string arg ) {
	if (value > 2147483647 || value < -2147483648 || arg == "nan" || arg == "nanf") {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		int i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}
}

void	print_float(double value, int precision) {
	float f = static_cast<float>(value);
	std::cout << "float: "<< std::fixed << std::setprecision(precision) << f << "f" << std::endl;
}

int		precision(char *av) {
	std::string argv = av;
	std::size_t pos = argv.find(".");
	int	prec = argv.size() - pos - 1;
	if (argv.at(argv.size() - 1) == 'f')
		prec--;
	return (prec);
}

int		which_type(char *av) {
	std::string arg = av;

	if (!isdigit(arg.at(0)) && arg.size() == 1) {
		return 1;
	}
	else if (arg.size() > 1 && !isdigit(arg.at(1)) && arg.at(1) != '.' && arg != "nan" && arg != "nanf" && arg != "-inf" && arg != "-inff" && arg != "inf" && arg != "inff" && arg != "+inf" && arg != "+inff") {
		return 0;
	}
	else {
		for (unsigned int i(0); i < arg.size(); i++) {
			if (arg.at(i) == '.') {
				if (arg.at(arg.size() - 1) == 'f') {
					return 2;
				}
				return 3;
			}
		}
		return 4;
	}
}

void	impossible(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

int		main(int ac, char **av) {

	if (ac < 2) {
		std::cout << "Not enough arguments." << std::endl;
		return 1;
	}
	else if (ac > 2) {
		std::cout << "Too much arguments." << std::endl;
		return 1;
	}
	int		type = which_type(av[1]);
	double 	a;
	int		prec;
	std::string	arg = av[1];
	switch (type)
	{
	case 1:
		a = av[1][0];
		prec = 1;
		break;
	case 2:
		a = atof(av[1]);
		prec = precision(av[1]);
		break;
	case 3:
		a = atof(av[1]);
		prec = precision(av[1]);
		break;
	case 4:
		a = atof(av[1]);
		prec = 1;
		break;
	default:
		impossible();
		return 1;
	}
	print_char(a, arg);
	print_int(a, arg);
	print_float(a, prec);
	std::cout << "double: " << std::fixed << std::setprecision(prec) << a << std::endl;

}
