/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 04:19:07 by wluong            #+#    #+#             */
/*   Updated: 2021/12/29 02:20:44 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

# define SCALE(x, byte) (x >> byte)
# define UNSCALE(x, byte) (x << byte)
# define FIXED_POINT_ONE(byte) (1 << byte)

class Fixed
{

public:

	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( const int n );
	Fixed ( const float f );
	~Fixed( void );

	Fixed &		operator=( Fixed const & rhs );
	Fixed &		operator<<( Fixed const & rhs );

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );
	float		toFloat( void ) const;
	int			toInt( void ) const;

private:

	int			_value;
	static const int	_bytes = 8;
};

std::ostream &	operator<<( std::ostream & os, Fixed const & rhs );

# endif