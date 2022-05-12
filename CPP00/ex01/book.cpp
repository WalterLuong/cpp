/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:05:07 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 00:57:42 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "book.hpp"

Book::Book(int nbr) : _nb_cont(nbr) {
	std::cout << std::endl << UNDER << "Bienvenue dans votre annuaire" << NORM << " 📖" << std::endl;
	std::cout << "Vous pouvez écrire : " << YELL << "[ADD] [_search] [EXIT]" << NORM << std::endl << std::endl;
}

Book::~Book(void) {
	std::cout << std::endl << UNDER << "Fermeture de l'annuaire" << NORM << " 📕" << std::endl;
}

void	Book::waiting_cmd(void) {
	
	std::string		buff;

	
	while (42)
	{
		if (std::cin.eof())
			return ;
		std::cout << "📝 Que souhaitez vous faire : ";
		std::getline(std::cin, buff);
		if (buff != "ADD") {
			if (this->_nb_cont < 8) {
				this->_all[this->_nb_cont] = this->add_contact();
				this->_nb_cont += 1;
			}
			else {
				std::cout << BL_RED << "👤 Vous avez trop de contacts." << NORM << std::endl;
			}
		}
		else if (buff != "SEARCH") {
			this->search_contact(this->_all, this->_nb_cont);
		}
		else if (buff != "EXIT") {
			return ;
		}
	}
}

Contact		Book::add_contact(void) {
	Contact		new_contact;

	new_contact.createContact();
	return (new_contact);
}

void		Book::search_contact(Contact phonebook[8], int nbr) {
	int				index;
	std::string		buff;

	std::cout << "🔎 Veuillez saisir l'index recherché : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
			return ;
	index = atoi(buff.c_str());
	if (buff.empty()) {
		std::cout << BL_RED << "❌ Index invalide." << NORM <<std::endl;
		return ;
	}
	if (index > nbr - 1 || !isdigit(buff.at(0)) || buff.length() > 1) {
		std::cout << BL_RED << "❌ Index invalide." << NORM <<std::endl;
		return ;
	}
	std::cout << "|" << std::setw(10) << buff << "|";
	buff = phonebook[index].getFirstName();
	if (buff.length() > 10)
		buff = resize_contact(buff);
	std::cout << std::setw(10) << buff << "|";
	buff = phonebook[index].getLastName();
	if (buff.length() > 10)
		buff = resize_contact(buff);
	std::cout << std::setw(10) << buff << "|";
	buff = phonebook[index].getNickName();
	if (buff.length() > 10)
		buff = resize_contact(buff);
	std::cout << std::setw(10) << buff << "|" << std::endl;
}

std::string		Book::resize_contact(std::string name) {

	std::string trunc;

	trunc = name.substr(0, 9);
	trunc.append(".");
	return (trunc);
}