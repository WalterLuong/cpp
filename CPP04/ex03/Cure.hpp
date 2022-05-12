/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:43:08 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:06:51 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CURE_HPP
# define	CURE_HPP

# include "Materia.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{

public:

	Cure( void );
	Cure( Cure const & src );
	~Cure( void );

	Cure &		operator=( Cure const & other );

	virtual AMateria*	clone( void ) const;
	virtual void		use( ICharacter & target );

};

#endif