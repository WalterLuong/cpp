/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:35:28 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 01:34:59 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:

	ScavTrap ( void );
	ScavTrap ( ScavTrap const & src );
	ScavTrap ( std::string name );
	virtual ~ScavTrap ( void );

	ScavTrap &		operator=(ScavTrap const & other );
	
	void	guardGate( void );
	void			attack( std::string const & target ) ;
	void			attack( ClapTrap & target ) ;
};

#endif