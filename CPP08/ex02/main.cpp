/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:15:57 by wluong            #+#    #+#             */
/*   Updated: 2022/01/20 05:12:13 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "VALUE ON TOP OF STACK : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "WE POP THIS VALUE ..." << std::endl;
	std::cout << "SIZE OF THE STACK : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int> mstack2(mstack);
	MutantStack<int> mstack3;
	mstack3 = mstack2;
	MutantStack<int>::iterator it = mstack2.begin();
	MutantStack<int>::iterator ite = mstack2.end();
	std::cout << "FIRST IT : " << *it << std::endl;
	++it;
	std::cout << "FIRST IT : " << *it << std::endl;
	--it;
	std::cout << "FIRST IT : " << *it << std::endl;
	std::cout << "STACK BY COPY CONSTRUCTOR : [";
	while (it != ite)
	{	
		std::cout << *it;
		if (it != (ite - 1))
			std::cout << ", ";
		++it;
	}
	std::cout << "]" << std::endl;
	MutantStack<int>::iterator it2 = mstack3.begin();
	MutantStack<int>::iterator ite2 = mstack3.end();
	std::cout << "STACK BY ASSIGNATION : [";
	while (it2 != ite2)
	{	
		std::cout << *it2;
		if (it2 != (ite2 - 1))
			std::cout << ", ";
		++it2;
	}
	std::cout << "]" << std::endl;
	std::stack<int> s(mstack2);
	return 0;
}