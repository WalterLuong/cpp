/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:05:28 by wluong            #+#    #+#             */
/*   Updated: 2022/01/20 05:21:07 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>

Span::Span( void ) : _size(0) {
	return ;
}

Span::Span( Span const & src ) : _size(src._size) {
	Span & tmp = const_cast<Span &>(src);
	for (std::vector<int>::iterator it = tmp._tab.begin(); it != tmp._tab.end(); it++) {
		this->_tab.push_back(*it);
	}
	return ;
}

Span::Span( unsigned int N ) : _size(N) {
	return ;
}

Span::~Span( void ) {
	return ;
}

Span &		Span::operator=( Span const & other ) {
	this->_tab.clear();
	this->_size = other._size;
	std::vector<int>::iterator	it;
	Span & tmp = const_cast<Span &>(other);
	for (it = tmp._tab.begin(); it != tmp._tab.end(); it++) {
		this->_tab.push_back(*it);
	}
	return *this;
}

void		Span::addNumber( int nbr ) {
	if (this->_tab.size() < this->_size) {
		this->_tab.push_back(nbr);
	}
	else {
		throw VectorIsFull();
	}
}

int			Span::shortestSpan( void ) {
	if (this->_tab.size() < 2) {
		throw NotEnoughNumbers();
	}
	else {
		std::vector<int>	tmp = this->_tab;
		std::sort( tmp.begin(), tmp.end());
		int		diff = tmp.at(1) - tmp.at(0);
		int		minspan = diff;
		for (unsigned int i(1); i < tmp.size() - 1; i++) {
			diff = tmp.at(i + 1) - tmp.at(i);
			if (diff < minspan) {
				minspan = diff;
			}
		}
		return minspan;
	}
}

int			Span::longestSpan( void ) {
	if (this->_tab.size() < 2) {
		throw NotEnoughNumbers();
	}
	else {
		std::vector<int>	vec2 = this->_tab;
		std::sort( vec2.begin(), vec2.end()); 
		return (*vec2.rbegin() - *vec2.begin());
	}
}

void		Span::addRangeIt( std::vector<int>::iterator first, std::vector<int>::iterator last ) {
	unsigned int i = 0;
	while (first != last && i < this->_size) {
		this->addNumber(*first);
		first++;
		i++;
	}
}

void		Span::printTab( void ) const {
	std::cout << YEL << "[";
	for (unsigned int i(0); i < this->_tab.size(); i++) {
		std::cout << this->_tab.at(i);
		if (i != this->_tab.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << NOR << std::endl;
}