/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:55:58 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 02:36:32 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CHARACTER_HPP
# define	CHARACTER_HPP

# include "ICharacter.hpp"
# include "Materia.hpp"

class Character : public ICharacter
{

public:

	Character( void );
	Character( Character const & src );
	Character( std::string const & name );
	virtual ~Character( void );

	Character &		operator=( Character const & other );

	virtual std::string const & getName( void ) const;
	virtual void equip( AMateria* m );
	virtual void unequip( int idx );
	virtual void use( int idx, ICharacter& target );

private:

	std::string		_name;
	AMateria*		_stuff[4];
	int				_space;

};

#endif