/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:13:00 by wluong            #+#    #+#             */
/*   Updated: 2022/01/15 04:27:14 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BASE_HPP
# define	BASE_HPP

class Base
{

public:

	virtual ~Base( void ) {};

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif