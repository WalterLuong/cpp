/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:15:49 by wluong            #+#    #+#             */
/*   Updated: 2022/01/20 05:14:16 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MUTANTSTACK_HPP
# define	MUTANTSTACK_HPP

# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{

public:

	typedef typename std::stack<T>::container_type::iterator	iterator;
	MutantStack( void ) : std::stack<T>() {};
	MutantStack( MutantStack const & src ) : std::stack<T>(src) {};
	~MutantStack( void ) {};

	MutantStack &	operator=( MutantStack const & other ) { std::stack<T>::operator=(other); return *this; }

	iterator	begin( void ) { return std::stack<T>::c.begin(); }
	iterator	end( void ) { return std::stack<T>::c.end(); }
	
private:

};

#endif