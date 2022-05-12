/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:17:08 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 02:51:46 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HUMANA_HPP
# define	HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

# define BLUE	"\033[1;34m"
# define YEL	"\033[1;33m"
# define NOR	"\033[m"

class HumanA
{

public:

	HumanA( std::string name, Weapon &obj );
	~HumanA( void );

	void		attack( void ) const;
	void		setName( std::string name );
	std::string	getName( void ) const;

private:

	Weapon&		_myWeapon;
	std::string	_name;

};

#endif