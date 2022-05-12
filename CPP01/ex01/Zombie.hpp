/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:32:10 by wluong            #+#    #+#             */
/*   Updated: 2021/12/26 23:23:34 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
public:

	Zombie( void );
	~Zombie( void );

	void	setName( std::string );
	void	announce( void ) const;

private:

	std::string		_name;

};

Zombie*		newZombie( std::string name );
Zombie*		zombieHorde( int N, std::string name );

#endif