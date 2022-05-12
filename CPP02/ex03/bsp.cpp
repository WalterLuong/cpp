/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:59:32 by wluong            #+#    #+#             */
/*   Updated: 2021/12/31 02:11:41 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"



bool	check_same_point(Point const a, Point const b) {
	if (a.getX() == b.getX() && a.getY() == b.getY())
		return false;
	return true;
}

bool	check_is_triangle(Point const a, Point const b, Point const c) {
	if (!check_same_point(a, b) || !check_same_point(b, c) || !check_same_point(c, a))
		return false;
	return true;
}

int		check_vec_prod(Point const a, Point const b, Point const d) {

	if (((a.getX() - d.getX()) * (b.getY() - d.getY()) - (a.getY() - d.getY()) * (b.getX() - d.getX())) < 0)
		return -1;
	else if (((a.getX() - d.getX()) * (b.getY() - d.getY()) - (a.getY() - d.getY()) * (b.getX() - d.getX())) > 0)
		return 1;
	else
		return 0;
	
}

bool	bsp( Point const a, Point const b, Point const c, Point const d) {

	int		check1;
	int		check2;
	int		check3;

	check1 = check_vec_prod(a, b, d);
	check2 = check_vec_prod(b, c, d);
	check3 = check_vec_prod(c, a, d);
	if ((check1 >=0 && check2 >= 0 && check3 >= 0) || (check1 <= 0 && check2 <= 0 && check3 <= 0))
		return true;
	return false;
	
}