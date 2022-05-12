/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:24:42 by wluong            #+#    #+#             */
/*   Updated: 2022/01/19 02:00:33 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		EASYFIND_HPP
# define	EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <vector>

class	NotFoundException : public std::exception
{
	public :
			virtual const char* what() const throw() { return " not found in container !" ;}
};

template <typename T>
void	easyfind(T & a, const int n) {

	typename T::iterator		it;

	for (it = a.begin(); it != a.end(); it++) {
		if (*it == n) {
			std::cout << "The number " << n << " is in the container !" << std::endl;
			return ;
		}
	}
	throw NotFoundException();
	

}

#endif