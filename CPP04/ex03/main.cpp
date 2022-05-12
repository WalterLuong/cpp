/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 02:13:41 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:52:45 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Materia.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#define RED "\033[1;31m"
#define NOR "\033[m"
#define GR "\033[1;32m"
#define YELL "\033[1;33m"
#define IT "\033[3m"

int main()
{
	std::cout << RED << "==================================== FIRST TEST ====================================" << NOR << std::endl;
	std::cout << YELL << "===== SUBJECT MAIN =====" << NOR << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << RED << "==================================== SECOND TEST ====================================" << NOR << std::endl;
	std::cout << YELL << "===== UNEQUIP SLOT 1 =====" << NOR << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	ICharacter* me2 = new Character("me");
	AMateria* tmp2;
	tmp2 = src2->createMateria("ice");
	me2->equip(tmp);
	tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	me2->equip(tmp2);
	ICharacter* bob2 = new Character("bob");
	me2->use(0, *bob2);
	me2->use(1, *bob2);
	me2->use(2, *bob2);
	me2->unequip(1);
	me2->use(0, *bob2);
	me2->use(1, *bob2);
	std::cout << GR << "Here, the leak \"definitely lost\" is normal because of the subject...." << std::endl;
	std::cout << "SUbject :" << IT << " The unequip method must NOT delete Materia!" << NOR << std::endl;
	std::cout << YELL << "===== USING EMPTY SLOT =====" << NOR << std::endl;
	me2->use(2, *bob2);

	delete bob2;
	delete me2;
	delete src2;
	std::cout << RED << "==================================== THIRD TEST ====================================" << NOR << std::endl;
	std::cout << YELL << "===== LEARN TOO MUCH =====" << NOR << std::endl;
	IMateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Ice());
	src3->learnMateria(new Ice());
	src3->learnMateria(new Ice());
	src3->learnMateria(new Ice());
	src3->learnMateria(new Ice());
	std::cout << YELL << "===== EQUIP TOO MUCH =====" << NOR << std::endl;
	ICharacter* me3 = new Character("me");
	AMateria* tmp3;
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	std::cout << "Subject :" << IT << " In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent \
	Materia, don’t do a thing." << NOR << std::endl;
	std::cout << GR << "So no message is printed." << std::endl;
	delete me3;
	delete src3;
	std::cout << RED << "==================================== FOURTH TEST ====================================" << NOR << std::endl;
	std::cout << YELL << "===== EQUIP INEXISTANT MATERIA =====" << NOR << std::endl;
	IMateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Ice());
	src4->learnMateria(new Cure());
	ICharacter* me4 = new Character("me");
	AMateria* tmp4;
	tmp4 = src4->createMateria("fire");
	me4->equip(tmp4);
	tmp4 = src4->createMateria("thunder");
	me4->equip(tmp4);
	ICharacter* bob4 = new Character("bob");
	me4->use(0, *bob4);
	me4->use(1, *bob4);
	delete bob4;
	delete me4;
	delete src4;	
	return 0;
}