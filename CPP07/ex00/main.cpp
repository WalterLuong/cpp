/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:01:40 by wluong            #+#    #+#             */
/*   Updated: 2022/01/18 15:55:27 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "Hello";
	std::string d = "Bonjour";
	std::cout << "Before swap" << std::endl;
	std::cout << "string1 = " << c << std::endl;
	std::cout << "string2 = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap" << std::endl;
	std::cout << "string1 = " << c << std::endl;
	std::cout << "string2 = " << d << std::endl;
	std::cout << "min( string1, string2 ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( string1, string2 ) = " << ::max( c, d ) << std::endl;
	return 0;
}