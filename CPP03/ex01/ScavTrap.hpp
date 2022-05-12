/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:35:28 by wluong            #+#    #+#             */
/*   Updated: 2022/01/02 04:19:32 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap ( void );
	ScavTrap ( ScavTrap const & src );
	ScavTrap ( std::string name );
	~ScavTrap ( void );

	ScavTrap &		operator=(ScavTrap const & other );
	
	void	guardGate( void );
	void	printSTAction( void ) const;
};

#endif