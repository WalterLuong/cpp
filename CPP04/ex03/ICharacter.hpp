/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:45:36 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 02:35:24 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ICHARACTER_CPP
# define	ICHARACTER_CPP

class ICharacter;

# include "Materia.hpp"
# include <string>

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip( AMateria* m ) = 0;
	virtual void unequip( int idx ) = 0;
	virtual void use( int idx, ICharacter& target ) = 0;
};

#endif