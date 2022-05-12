/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:16:50 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 03:17:06 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WEAPON_HPP
# define	WEAPON_HPP

# include <string>
class Weapon
{

public:

	Weapon( std::string name );
	~Weapon( void );

	void			setType( std::string name );
	std::string		getType(void) const;
	
private:

	std::string _type;

};

#endif