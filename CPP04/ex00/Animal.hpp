/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 02:50:46 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 04:24:09 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

public:

	Animal( void );
	Animal( Animal const & src );
	virtual ~Animal( void );

	Animal &		operator=( Animal const & other );

	virtual std::string		getType( void ) const;
	virtual void			makeSound( void ) const;

protected:
	std::string		_type;

};

#endif