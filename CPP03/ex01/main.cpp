/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 06:45:26 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 02:18:26 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <stdlib.h>
#include <unistd.h>

bool	check_enter( std::string buff ) {
	int		res;

	if (buff.empty())
		return false;
	res = atoi(buff.c_str());
	if (buff.size() > 1 || !isdigit(buff.at(0)) || res > 2 || res == 0)
		return false;
	return true;
}

bool	check_enter2( std::string buff ) {
	int		res;

	if (buff.empty())
		return false;
	res = atoi(buff.c_str());
	if (buff.size() > 1 || !isdigit(buff.at(0)) || res > 3 || res == 0)
		return false;
	return true;
}

int		random(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first) {
		srand( time(NULL) );
		first = false;
	}
	return min + rand() % (( max + 1 ) - min);
}

ClapTrap	*newClapTrap(std::string name ) {
	ClapTrap	*new_CT = new ClapTrap(name);
	return (new_CT);
}

ScavTrap	*newScavTrap(std::string name ) {
	ScavTrap	*new_ST = new ScavTrap(name);
	return (new_ST);
}

void		CT_vs_CT( ClapTrap *C1, ClapTrap *C2 ) {
	int				act1;
	int				act2;
	std::string		buff;

	while (C1->getEnergyPoint() && C2->getEnergyPoint()) {
		if (C1->getEnergyPoint()) {
			std::cout << GREEN << "\t\t [PLAYER TURN]" << YELL << " PM[" << C1->getHitsPoint() << "]" << NOR << std::endl;
			C1->printAction();
			std::getline(std::cin, buff);
			while (!check_enter(buff))
			{
				if (std::cin.eof())
					return ;
				std::cout << "YOU MUST CHOOSE 1 OR 2" << std::endl;
				C1->printAction();
				std::getline(std::cin, buff);
			}
			act1 = atoi(buff.c_str());
			switch (act1)
			{
			case 1:
				C1->attack(*C2);
				break;
			case 2:
				C1->beRepaired(random(1, 100));
				break;
			default:
				break;
			}
		}
		if (C2->getEnergyPoint()) {
			std::cout << RED << "\t\t [ENNEMY TURN]" << YELL << " PM[" << C2->getHitsPoint() << "]" << NOR << std::endl;
			act2 = random(1, 5);
			switch (act2)
			{
			case 1:
				C2->attack(*C1);
				break;
			case 2:
				C2->attack(*C1);
				break;
			case 3:
				C2->attack(*C1);
				break;
			case 4:
				C2->attack(*C1);
				break;
			case 5:
				C2->beRepaired(random(1, 100));
				break;
			default:
				break;
			}
		}
		if (!C1->getHitsPoint() && !C2->getHitsPoint()) {
			std::cout << YELL << "Both of players have no more PM. The battle ends on a draw !" << NOR << std::endl;
			return ;
		}
		std::cout << "===============================================================" << std::endl;
	}
	if (!C1->getEnergyPoint()) {
		std::cout << BLUE << C1->getName() << NOR << " is dead. ☠️" << std::endl;
	}
	else {
		std::cout << BLUE << C2->getName() << NOR << " is dead. ☠️" << std::endl;
	}
}

void		CT_vs_ST( ClapTrap *C1, ScavTrap *C2 ) {
	int				act1;
	int				act2;
	std::string		buff;
	
	while (C1->getEnergyPoint() && C2->getEnergyPoint()) {
		if (C1->getEnergyPoint()) {
			std::cout << GREEN << "\t\t [PLAYER TURN]" << YELL << " PM[" << C1->getHitsPoint() << "]" << NOR << std::endl;
			C1->printAction();
			std::getline(std::cin, buff);
			while (!check_enter(buff))
			{
				if (std::cin.eof())
					return ;
				std::cout << "YOU MUST CHOOSE 1 OR 2" << std::endl;
				C1->printAction();
				std::getline(std::cin, buff);
			}
			act1 = atoi(buff.c_str());
			switch (act1)
			{
			case 1:
				C1->attack(*C2);
				break;
			case 2:
				C1->beRepaired(random(1, 100));
				break;
			default:
				break;
			}
		}
		if (C2->getEnergyPoint()) {
			std::cout << RED << "\t\t [ENNEMY TURN]" << YELL << " PM[" << C2->getHitsPoint() << "]" << NOR << std::endl;
			act2 = random(1, 5);
			switch (act2)
			{
			case 1:
				C2->attack(*C1);
				break;
			case 2:
				C2->attack(*C1);
				break;
			case 3:
				C2->attack(*C1);
				break;
			case 4:
				C2->guardGate();
				break;
			case 5:
				C2->beRepaired(random(1, 100));
				break;
			default:
				break;
			}
		}
		if (!C1->getHitsPoint() && !C2->getHitsPoint()) {
			std::cout << YELL << "Both of players have no more PM. The battle ends on a draw !" << NOR << std::endl;
			return ;
		}
		std::cout << "===============================================================" << std::endl;
	}
	if (!C1->getEnergyPoint()) {
		std::cout << BLUE << C1->getName() << NOR << " is dead. ☠️" << std::endl;
	}
	else {
		std::cout << BLUE << C2->getName() << NOR << " is dead. ☠️" << std::endl;
	}
}

void		ST_vs_CT( ScavTrap*C1, ClapTrap *C2 ) {
	int				act1;
	int				act2;
	std::string		buff;
	
	while (C1->getEnergyPoint() && C2->getEnergyPoint()) {
		if (C1->getEnergyPoint()) {
			std::cout << GREEN << "\t\t [PLAYER TURN]" << YELL << " PM[" << C1->getHitsPoint() << "]" << NOR << std::endl;
			C1->printSTAction();
			std::getline(std::cin, buff);
			while (!check_enter2(buff))
			{
				if (std::cin.eof())
					return ;
				std::cout << "YOU MUST CHOOSE 1, 2 or 3" << std::endl;
				C1->printSTAction();
				std::getline(std::cin, buff);
			}
			act1 = atoi(buff.c_str());
			switch (act1)
			{
			case 1:
				C1->attack(*C2);
				break;
			case 2:
				C1->beRepaired(random(1, 100));
				break;
			case 3:
				C1->guardGate();
			default:
				break;
			}
		}
		if (C2->getEnergyPoint()) {
			std::cout << RED << "\t\t [ENNEMY TURN]" << YELL << " PM[" << C2->getHitsPoint() << "]" << NOR << std::endl;
			act2 = random(1, 5);
			switch (act2)
			{
			case 1:
				C2->attack(*C1);
				break;
			case 2:
				C2->attack(*C1);
				break;
			case 3:
				C2->attack(*C1);
				break;
			case 4:
				C2->attack(*C1);
				break;
			case 5:
				C2->beRepaired(random(1, 100));
				break;
			default:
				break;
			}
		}
		if (!C1->getHitsPoint() && !C2->getHitsPoint()) {
			std::cout << YELL << "Both of players have no more PM. The battle ends on a draw !" << NOR << std::endl;
			return ;
		}
		std::cout << "===============================================================" << std::endl;
	}
	if (!C1->getEnergyPoint()) {
		std::cout << BLUE << C1->getName() << NOR << " is dead. ☠️" << std::endl;
	}
	else {
		std::cout << BLUE << C2->getName() << NOR << " is dead. ☠️" << std::endl;
	}
}

void		ST_vs_ST( ScavTrap*C1, ScavTrap *C2 ) {
	int				act1;
	int				act2;
	std::string		buff;
	
	while (C1->getEnergyPoint() && C2->getEnergyPoint()) {
		if (C1->getEnergyPoint()) {
			std::cout << GREEN << "\t\t [PLAYER TURN]" << YELL << " PM[" << C1->getHitsPoint() << "]" << NOR << std::endl;
			C1->printSTAction();
			std::getline(std::cin, buff);
			while (!check_enter2(buff) || buff.empty())
			{
				if (std::cin.eof())
					return ;
				std::cout << "YOU MUST CHOOSE 1, 2 or 3" << std::endl;
				C1->printSTAction();
				std::getline(std::cin, buff);
			}
			act1 = atoi(buff.c_str());
			switch (act1)
			{
			case 1:
				C1->attack(*C2);
				break;
			case 2:
				C1->beRepaired(random(1, 100));
				break;
			case 3:
				C1->guardGate();
			default:
				break;
			}
		}
		if (C2->getEnergyPoint()) {
			std::cout << RED << "\t\t [ENNEMY TURN]" << YELL << " PM[" << C2->getHitsPoint() << "]" << NOR << std::endl;
			act2 = random(1, 5);
			switch (act2)
			{
			case 1:
				C2->attack(*C1);
				break;
			case 2:
				C2->attack(*C1);
				break;
			case 3:
				C2->attack(*C1);
				break;
			case 4:
				C2->guardGate();
				break;
			case 5:
				C2->beRepaired(random(1, 100));
				break;
			default:
				break;
			}
		}
		if (!C1->getHitsPoint() && !C2->getHitsPoint()) {
			std::cout << YELL << "Both of players have no more PM. The battle ends on a draw !" << NOR << std::endl;
			return ;
		}
		std::cout << "===============================================================" << std::endl;
	}
	if (!C1->getEnergyPoint()) {
		std::cout << BLUE << C1->getName() << NOR << " is dead. ☠️" << std::endl;
	}
	else {
		std::cout << BLUE << C2->getName() << NOR << " is dead. ☠️" << std::endl;
	}
}

int		main(int ac, char **av) {

	(void) ac,
	(void) av;
	ClapTrap	*C1 = NULL;
	ClapTrap	*C2 = NULL;
	ScavTrap	*S1 = NULL;
	ScavTrap	*S2 = NULL;
	int				player1;
	int				player2;
	std::string		buff;


	std::cout << "CHOOSE YOUR FIGHTER :" << std::endl << "\t1 = ClapTrap" << std::endl << "\t2 = ScavTrap" << std::endl;
	while (buff.empty() ) {
		if (std::cin.eof())
			return 1;
		std::cout << "➡️  ";
		std::getline(std::cin, buff);
	}
	while (!check_enter(buff)) {
		if (std::cin.eof())
			return 1;
		std::cout << "YOU MUST CHOOSE 1 OR 2" << std::endl;
		std::cout << "➡️  ";
		std::getline(std::cin, buff);
	}
	player1 = atoi(buff.c_str());
	std::cout << "============================================================================" << std::endl;
	std::cout << "CHOOSE YOUR ENNEMY :" << std::endl << "\t1 = ClapTrap" << std::endl << "\t2 = ScavTrap" << std::endl << "➡️  ";
	std::getline(std::cin, buff);
	while (buff.empty()) {
		if (std::cin.eof())
			return 1;	
		std::cout << "➡️  ";
		std::getline(std::cin, buff);
	}
	while (!check_enter(buff)) {
		if (std::cin.eof())
			return 1;
		std::cout << "YOU MUST CHOOSE 1 OR 2" << std::endl;
		std::cout << "➡️  ";
		std::getline(std::cin, buff);
	}
	player2 = atoi(buff.c_str());
	std::cout << "============================================================================" << std::endl;
	std::cout << "Give a name to your fighter : " << BLUE;
	std::getline(std::cin, buff);
	while (buff.empty()) {
		if (std::cin.eof())
			return 1;
		std::cout << NOR << "Give a name to your fighter : " << BLUE;
		std::getline(std::cin, buff);
	}
	std::cout << NOR;
	if (player1 == 1) {
		C1 = newClapTrap(buff);
	}
	else { 
		S1 = newScavTrap(buff);
	}
	std::cout << "============================================================================" << std::endl;
	std::cout << "Give a name to your ennemy : " << BLUE;
	std::getline(std::cin, buff);
	while (buff.empty() ) {
		if (std::cin.eof())
			return 1;
		std::cout << NOR << "Give a name to your ennemy: " << BLUE;
		std::getline(std::cin, buff);
	}
	std::cout << NOR;
	if (player2 == 1) {
		C2 = newClapTrap(buff);
	}
	else { 
		S2 = newScavTrap(buff);
	}
	std::cout << "============================================================================" << std::endl;
	if (player1 == 1 && player2 == 1) {
		CT_vs_CT(C1, C2);
		std::cout << std::endl;
		delete C1;
		delete C2;
	}
	else if (player1 == 1 && player2 == 2) {
		CT_vs_ST(C1, S2);
		std::cout << std::endl;
		delete C1;
		delete S2;
	}
	else if (player1 == 2 && player2 == 1) {
		ST_vs_CT(S1, C2);
		std::cout << std::endl;
		delete S1;
		delete C2;
	}
	else if (player1 == 2 && player2 == 2) {
		ST_vs_ST(S1, S2);
		std::cout << std::endl;
		delete S1;
		delete S2;
	}
}