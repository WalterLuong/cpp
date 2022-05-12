/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 02:50:46 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 06:22:48 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{

public:

	AAnimal( void );
	AAnimal( AAnimal const & src );
	virtual ~AAnimal( void );

	AAnimal &		operator=( AAnimal const & other );

	virtual std::string		getType( void ) const;
	virtual void			makeSound( void ) const = 0;

protected:
	std::string		_type;

};

#endif