/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:32:44 by wluong            #+#    #+#             */
/*   Updated: 2021/12/30 05:17:40 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{

public:

	Point( void );
	Point( Point const & src);
	Point ( Fixed const & a, Fixed const & b );
	~Point( void );

	Point &		operator=( Point const & rhs );
	
	float		getX( void ) const ;
	float		getY( void ) const ;

private:

	Fixed const	_x;
	Fixed const	_y;

};

bool	bsp( Point const a, Point const b, Point const c, Point const d);
bool	check_is_triangle(Point const a, Point const b, Point const c);

#endif