/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 04:19:07 by wluong            #+#    #+#             */
/*   Updated: 2021/12/29 18:05:25 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{

public:

	Fixed( void );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed &			operator=( Fixed const & rhs );

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

private:

	int			_value;
	static const int	_bytes = 8;
};

# endif