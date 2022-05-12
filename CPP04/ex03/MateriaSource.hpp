/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 07:06:24 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:09:43 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MATERIASOURCE_HPP
# define	MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	
public:
	
	MateriaSource( void );
	MateriaSource( MateriaSource const & src );
	virtual ~MateriaSource( void );

	MateriaSource &		operator=( MateriaSource const & other );

	virtual void learnMateria( AMateria* );
	virtual AMateria* createMateria( std::string const & type );

private:

	AMateria*	_stuff[4];
	int			_learned;

};

#endif