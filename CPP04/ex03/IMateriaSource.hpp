/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 07:05:15 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:08:58 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		IMATERIASOURCE_HPP
# define	IMATERIASOURCE_HPP

class IMateriaSource;

# include "Materia.hpp"

class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif