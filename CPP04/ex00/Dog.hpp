/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:51:31 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 04:27:33 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{

public:

	Dog( void );
	Dog( Dog const & src );
	virtual ~Dog( void );

	Dog &	operator=( Dog const & other );

	virtual void	makeSound( void ) const;
};

#endif