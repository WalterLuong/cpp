/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:51:31 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 06:38:16 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{

public:

	Dog( void );
	Dog( Dog const & src );
	virtual ~Dog( void );

	Dog &	operator=( Dog const & other );

	virtual void	makeSound( void ) const;
	void			setNewIdea( int const & index, std::string const & idea );
	std::string		getIdea( int const & index ) const;
	std::string*	getAddress( void ) const;

private:

	Brain*		_dogBrain;

};

#endif