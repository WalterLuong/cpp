/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:16:53 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 04:20:17 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGCAT_HPP
# define	WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:

	WrongCat( void );
	WrongCat( WrongCat const & src );
	virtual ~WrongCat( void);

	WrongCat &	operator=( WrongCat const & other );
};

#endif