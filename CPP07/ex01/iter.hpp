/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:26:11 by wluong            #+#    #+#             */
/*   Updated: 2022/01/17 15:56:54 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ITER_HPP
# define	ITER_HPP

template <typename T>
void	print(T & a) {
	std::cout << a << std::endl;
}

template <typename T>
void	increase(T & a) {
	a += 1;
}

template <typename T>
void	iter(T * adress, unsigned int const length, void f(T & a)) {
	for(unsigned int i(0); i < length; i++) {
			f(adress[i]);
	}
}

#endif