/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:33:00 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:06:55 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ICE_HPP
# define	ICE_HPP

# include "Materia.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{

public: 

	Ice( void );
	Ice( Ice const & src );
	~Ice( void );

	Ice &		operator=( Ice const & other );

	virtual AMateria*	clone( void ) const;
	virtual void		use( ICharacter & target );
	
};

#endif