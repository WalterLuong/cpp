/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:17:03 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 04:17:50 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGANIMAL_HPP
# define	WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

public:

	WrongAnimal( void );
	WrongAnimal( WrongAnimal const & src );
	virtual ~WrongAnimal( void );

	WrongAnimal &		operator=( WrongAnimal const & other );

	virtual std::string		getType( void ) const;
	virtual void			makeSound( void ) const;

protected:
	std::string		_type;

};

#endif