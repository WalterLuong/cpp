/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 06:07:16 by wluong            #+#    #+#             */
/*   Updated: 2022/01/02 18:00:42 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP

# include <iostream>
# include <string>

# define NOR "\033[m"
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELL "\033[1;33m"

class ClapTrap
{

public:

	ClapTrap( void );
	ClapTrap( ClapTrap const & src );
	ClapTrap( std::string name );
	~ClapTrap( void );

	ClapTrap &		operator=( ClapTrap const & other );

	void			attack( std::string const & target ) ;
	void			attack( ClapTrap & target ) ;
	void			takeDamage( unsigned int amount );
	void			takeDamage( ClapTrap const & attacker );
	void			beRepaired( unsigned int amount );

	std::string		getName( void ) const;
	unsigned int	getAttackDmg( void ) const;
	unsigned int	getEnergyPoint( void ) const;

private:

	std::string		_name;
	int				_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDmg;
};

#endif