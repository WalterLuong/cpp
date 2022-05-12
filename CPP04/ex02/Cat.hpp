/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:01:39 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 06:24:16 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

# include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{

public:

	Cat( void );
	Cat( Cat const & src );
	virtual ~Cat( void );

	Cat &	operator=( Cat const & other );

	virtual void	makeSound( void ) const;
	void			setNewIdea( int const & index, std::string const & idea );
	std::string		getIdea( int const & index ) const;

private:

	Brain*		_catBrain;

};

#endif