/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:05:33 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 04:11:17 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BRAIN_HPP
# define	BRAIN_HPP

# include <iostream>

class Brain
{

public:

	Brain( void );
	Brain( Brain const & src );
	Brain( std::string const & idea );
	~Brain( void );

	Brain &		operator=( Brain const & other );

	void			setNewIdea( int const & index, std::string const & idea );
	std::string		getIdea( int const & index ) const;
	std::string*	getAddress( void ) ;

private:

	std::string		_ideas[100];
	
};

#endif