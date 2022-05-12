/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:24:00 by wluong            #+#    #+#             */
/*   Updated: 2022/01/02 23:29:44 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRAGTRAP_HPP
# define	FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:

	FragTrap( void );
	FragTrap( FragTrap const & src );
	FragTrap( std::string name );
	~FragTrap( void );

	FragTrap &		operator=( FragTrap const & other );

	void			highFivesGuys( void );
};

#endif
