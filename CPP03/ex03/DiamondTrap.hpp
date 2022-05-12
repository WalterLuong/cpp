/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:28:04 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 02:05:49 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DIAMONDTRAP_HPP
# define	DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

public:
	
	DiamondTrap( void );
	DiamondTrap( DiamondTrap const & src );
	DiamondTrap( std::string name );
	~DiamondTrap( void );

	DiamondTrap &		operator=( DiamondTrap const & other );

	void				whoAmI( void );
	void				attack( std::string const & target ) ;
	void				attack( ClapTrap & target ) ;
	std::string			getName( void );

private:

	std::string		_name;

};

#endif