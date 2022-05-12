/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 02:50:29 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 06:07:55 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

# define GR "\033[1;32m"
# define NOR "\033[m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"

int main()
{
	std::cout << RED << "==================================== FIRST TEST ====================================" << NOR << std::endl;
	std::cout << GR << "==================================== CONSTRUCTION ====================================" << NOR << std::endl;
	Animal*		zoo[100];
	for (int i(0); i < 100; i++) {
		std::cout << BLUE << "ANIMAL " << i + 1 << " :" << NOR;
		if (i < 50) {
			zoo[i] = new Dog ();
		}
		else {
			zoo[i] = new Cat();
		}
	}
	std::cout << GR << "==================================== SOUND + DELETE ====================================" << NOR << std::endl;
	for (int i(0); i < 100; i++) {
		std::cout << BLUE << "ANIMAL " << i + 1 << " :" << NOR;
		zoo[i]->makeSound();
		delete zoo[i];
	}
	std::cout << RED << "==================================== SECOND TEST ====================================" << NOR << std::endl;
	std::cout << BLUE << "===== CONSTRUCTIONS =====" << NOR << std::endl;
	Dog*	dog1;
	Dog*	dog2;
	Dog		dog3;
	dog1 = new Dog();
	dog2 = new Dog();
	std::cout << BLUE << "===== SET FIRST IDEA =====" << NOR << std::endl;
	dog1->setNewIdea(0, "I love my master 🐶❤️ 👦!");
	std::cout << "Dog 1 Idea : " << dog1->getIdea(0) << std::endl;
	std::cout << "Dog 1 address : "  << dog1->getAddress() << std::endl;
	std::cout << "Dog 2 Idea : " << dog2->getIdea(0) << std::endl;
	std::cout << "Dog 2 address : "  << dog2->getAddress() << std::endl;
	std::cout << BLUE << "===== DEEP COPY OVERLOAD OPERATOR =====" << NOR << std::endl;
	delete dog2;
	dog2 = dog1;
	std::cout << GR << "ASSIGNATION DONE" << NOR << std::endl;
	std::cout << "Dog 1 assignation Idea : "  << dog1->getIdea(0) << std::endl;
	std::cout << "Dog 1 address : "  << dog1->getAddress() << std::endl;
	std::cout << "Dog 2 assignation Idea : "  << dog2->getIdea(0) << std::endl;
	std::cout << "Dog 2 address : "  << dog2->getAddress() << std::endl;
	dog1->setNewIdea(0, "I love playing with my tail 🐩 !!!");
	std::cout << GR << "IDEA SET DONE" << NOR << std::endl;
	std::cout << "Dog 1 new Idea : "  << dog1->getIdea(0) << std::endl;
	std::cout << "Dog 1 address : "  << dog1->getAddress() << std::endl;
	std::cout << "Dog 2 new Idea : "  << dog2->getIdea(0) << std::endl;
	std::cout << "Dog 2 address : "  << dog2->getAddress() << std::endl;
	dog3 = *dog1;
	std::cout << GR << "ASSIGNATION DONE" << NOR << std::endl;
	dog1->setNewIdea(0, "Squirrel ?");
	std::cout << GR << "IDEA SET DONE" << NOR << std::endl;
	std::cout << "Dog 3 Idea : " << dog3.getIdea(0) << std::endl;
	std::cout << "Dog 3 address : "  << dog3.getAddress() << std::endl;
	std::cout << "Dog 1 Idea : "  << dog1->getIdea(0) << std::endl;
	std::cout << "Dog 1 address : "  << dog1->getAddress() << std::endl;
	std::cout << BLUE << "===== DEEP COPY CONSTRUCTOR =====" << NOR << std::endl;
	Dog		dog4(*dog1);
	std::cout << "Dog 4 Idea : " << dog4.getIdea(0) << std::endl;
	std::cout << "Dog 4 address : "  << dog4.getAddress() << std::endl;
	dog4.setNewIdea(0, "I hope my master will come back one day...  🐕🏠");
	std::cout << "Dog new 4 Idea : " << dog4.getIdea(0) << std::endl;
	std::cout << "Dog 4 address : "  << dog4.getAddress() << std::endl;
	std::cout << "Dog 1 Idea : " << dog1->getIdea(0) << std::endl;
	std::cout << "Dog 1 address : "  << dog1->getAddress() << std::endl;
	std::cout << BLUE << "===== DESTRUCTIONS =====" << NOR << std::endl;
	delete dog1;
	return 0;
}