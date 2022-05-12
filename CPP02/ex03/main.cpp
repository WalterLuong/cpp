/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:13:57 by wluong            #+#    #+#             */
/*   Updated: 2021/12/31 02:27:45 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {

	Point const a(Fixed(0.0f), Fixed(0.0f));
	Point const b(Fixed(0.0f), Fixed(2.0f));
	Point const c(Fixed(2.0f), Fixed(0.0f));
	Point const d(Fixed(1.0f), Fixed(1.0f));


	if (!check_is_triangle(a, b, c)) {
		std::cout << "Les poimts du triangle ne doivent pas etre confondus. Le triangle n'est donc pas valide." << std::endl;
		return 1;
	}
	std::cout << "\033[1;31m=====================================================" << std::endl;
	std::cout << "\t\t METHODE :\033[m" << std::endl << std::endl << std::endl;
	std::cout << "Nous avons les trois points A B C du triangle suivant :" << std::endl;
	std::cout << "\ta : (" << a.getX() << ", " << a.getY() << ")" << std::endl; 
	std::cout << "\tb : (" << b.getX() << ", " << b.getY() << ")" << std::endl; 
	std::cout << "\tc : (" << c.getX() << ", " << c.getY() << ")" << std::endl << std::endl;
	std::cout << "Nous souhaitons savoir si le point D est a l'interieur de ce triangle." << std::endl;
	std::cout << "\td : (" << d.getX() << ", " << d.getY() << ")" << std::endl << std::endl;
	std::cout << "Nous calculons le produit vectoriel entre D et les trois points du triangle :" << std::endl;
	std::cout << "(Xa - Xd)(Yb - Yd) - (Ya - Yd)(Xb - Xd)" <<std::endl;
	std::cout << "(Xb - Xd)(Yc - Yd) - (Yb - Yd)(Xc - Xd)" <<std::endl;
	std::cout << "(Xc - Xd)(Ya - Yd) - (Yc - Yd)(Xa - Xd)" <<std::endl << std::endl;
	std::cout << "Si les signes (négatif ou positif) des trois produits sont du meme signe, alors D est dans le triangle" << std::endl;
	std::cout << "\033[1;31m=====================================================\033[m" << std::endl << std::endl;

	if (bsp(a, b, c, d) == true ) {
		std::cout << "Le point est a l'interieur du triangle !" << std::endl;
		return 0;
	}
	else {
		std::cout << "Le point n'est pas dans le triangle !" << std::endl;
		return 0;
	}
}