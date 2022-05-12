/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:01:39 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 04:27:37 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{

public:

	Cat( void );
	Cat( Cat const & src );
	virtual ~Cat( void );

	Cat &	operator=( Cat const & other );

	virtual void	makeSound( void ) const;
};

#endif