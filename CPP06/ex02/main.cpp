/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:12:13 by wluong            #+#    #+#             */
/*   Updated: 2022/01/15 05:11:10 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <stdlib.h>

int		random(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first) {
		srand( time(NULL) );
		first = false;
	}
	return min + rand() % (( max + 1 ) - min);
}

Base *		generate( void ) {
	Base *newBase;
	int type = random(1, 3);
	char typechar = 64 + type;
	std::cout << "Le type généré est : " << typechar << std::endl;
	switch (type) {
		case 1:
			newBase = new A();
			break;
		case 2:
			newBase = new B();
			break;
		case 3:
			newBase = new C();
			break;
		default:
			std::cout << "UNEXECPTED BEHAVIOR. I DESERVE 0/100" << std::endl;
			newBase = new Base();
	}
	return newBase;
}

void		identify(Base *p) {
	if (A* typeA = dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (B* typeB = dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (C* typeC = dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void		identify(Base &p) {
	try {
		A	&typeA = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void) typeA;
	}
	catch (std::exception & e) {};
	try {
		B	&typeB = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void) typeB;
	}
	catch (std::exception & e) {};
	try {
		C	&typeC = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void) typeC;
	}
	catch (std::exception & e) {};
}

int		main() {
	Base *p = generate();
	std::cout << std::endl << "\033[3;4mIdentification par pointeur :\033[m" << std::endl;
	identify(p);
	std::cout << std::endl << "\033[3;4mIdentification par référence :\033[m" << std::endl;
	identify(*p);
	delete p;
	return 0;
}