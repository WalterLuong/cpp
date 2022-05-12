/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:17:25 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 02:52:14 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

# define RED	"\033[1;31m"
# define YEL	"\033[1;33m"
# define NOR	"\033[m"

class HumanB
{
public:

	HumanB( std::string name );
	~HumanB( void );

	void		setName( std::string name);
	std::string	getName( void ) const;
	void		setWeapon( Weapon &obj );
	void		attack( void ) const;

private:

	Weapon		*_myWeapon;
	std::string	_name;

};

#endif