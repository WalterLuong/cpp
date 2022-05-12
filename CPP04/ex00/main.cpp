/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 02:50:29 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 00:29:45 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

# define GR "\033[1;32m"
# define NOR "\033[m"
# define RED "\033[1;31m"

int main()
{
	std::cout << GR << "==================================== ANIMAL ====================================" << NOR << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	std::cout << std::endl;
	delete i;
	delete j;
	delete meta;
	std::cout << RED << "================================= WRONG ANIMAL =================================" << NOR << std::endl;
	const WrongAnimal* chatNul = new WrongCat();
	const WrongAnimal* animo = new WrongAnimal();
	std::cout << std::endl << chatNul->getType() << " " << std::endl;
	std::cout << animo->getType() << " " << std::endl;
	chatNul->makeSound();
	animo->makeSound();
	std::cout << std::endl;
	delete animo;
	delete chatNul;
	return 0;
}