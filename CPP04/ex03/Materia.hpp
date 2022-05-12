/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:22:26 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:36:36 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MATERIA_HPP
# define	MATERIA_HPP

class AMateria;

# include "Character.hpp"
# include <iostream>

class AMateria
{

public:

	AMateria( void );
	AMateria( AMateria const & src );
	AMateria( std::string const & type );
	virtual ~AMateria( void );

	AMateria &		operator=( AMateria const & other );

	std::string const &		getType( void ) const;

	virtual AMateria*		clone( void ) const = 0;
	virtual void			use( ICharacter & Target );

protected:

	const std::string		_type;

};

#endif