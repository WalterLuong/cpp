/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:27:05 by wluong            #+#    #+#             */
/*   Updated: 2022/01/20 04:08:39 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#define GR "\033[1;32m"
#define YEL "\033[1;33m"
#define BLUE "\033[1;3;34m"
#define NOR "\033[m"


int		random(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first) {
		srand( time(NULL) );
		first = false;
	}
	return min + rand() % (( max + 1 ) - min);
}


int		main()
{
	std::cout << GR << "====== SUBJECT MAIN TEST ======" << NOR << std::endl << std::endl;
	try {
		
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printTab();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	std::cout << GR << "====== RANDOM ADDRANGE TEST ======" << NOR << std::endl << std::endl;
	try {
		std::vector<int> vec;
		Span	sp2(10);
		for (int i(0); i < 20; i++) {
			vec.push_back(random(1, 100));
		}
		std::cout << "VECTOR : ";
		for (int i(0); i < 20; i++) {
			std::cout << vec.at(i) << ", ";
		}
		std::cout << std::endl;
		sp2.addRangeIt(vec.begin(), vec.end());
		std::cout << "SPAN : ";
		sp2.printTab();
		std::cout << "shortest span : " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span : " << sp2.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	std::cout << GR << "====== COPY AND ASSIGNATION TEST ======" << NOR << std::endl << std::endl;
	try {
		Span sp3 = Span(5);
		sp3.addNumber(5);
		sp3.addNumber(3);
		sp3.addNumber(17);
		sp3.addNumber(9);
		sp3.addNumber(11);
		std::cout << "SPAN 3: ";
		sp3.printTab();
		Span sp4(sp3);
		std::cout << "SPAN 4: ";
		sp4.printTab();
		Span sp5(2);
		sp5 = sp4;
		std::cout << "SPAN 5: ";
		sp5.printTab();
		std::cout << "shortest span sp4 : " << sp4.shortestSpan() << std::endl;
		std::cout << "shortest span sp5 : " << sp5.shortestSpan() << std::endl;
		std::cout << "longest span sp4 : " << sp4.longestSpan() << std::endl;
		std::cout << "longest span sp5 : " << sp5.longestSpan() << std::endl << std::endl;
	
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	std::cout << GR << "====== MORE THAN 10000 TEST ======" << NOR << std::endl << std::endl;
	try {
		std::vector<int> vec;
		Span	sp2(20000);
		for (int i(0); i < 22000; i++) {
			vec.push_back(random(0, 100000));
		}
		sp2.addRangeIt(vec.begin(), vec.end());
		std::sort(vec.begin(), vec.end());
		std::cout << "Shortest value : " << vec.at(0) << " , Longest value : " << vec.at(21999) << std::endl;
		std::cout << BLUE << "You can uncomment 2 lines in the main to print the array" << NOR << std::endl;
//		std::cout << "SPAN : ";
//		sp2.printTab(); //I PUT THIS LINE IN COMMENTARY TO NOT SHOW A 20000 INTS VECTOR AND MAKE THE MAIN VISIBLE
		std::cout << "shortest span : " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span : " << sp2.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	std::cout << GR << "====== SPAN WITH ONLY 1 INT ======" << NOR << std::endl << std::endl;
	try {
		
		Span sp = Span(5);
		sp.addNumber(6);
		sp.printTab();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl << std::endl; }
	std::cout << GR << "====== ADD MORE INT THAN SIZE ======" << NOR << std::endl << std::endl;
	try {
		
		Span sp = Span(5);
		sp.addNumber(0);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		sp.printTab();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl << std::endl; }

}