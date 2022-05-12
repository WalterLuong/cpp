/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:53:35 by wluong            #+#    #+#             */
/*   Updated: 2022/01/17 14:13:51 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WHATEVER_HPP
# define	WHATEVER_HPP

template <typename T>
void	swap( T & a, T & b ) {
	T const tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &		min(T const & a, T const & b) {
	return (a < b) ? a : b;
}

template <typename T>
T const &		max(T const & a, T const & b) {
	return (a > b) ? a : b;
}

#endif