/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 04:19:07 by wluong            #+#    #+#             */
/*   Updated: 2021/12/30 03:14:13 by wluong           ###   ########.fr       */
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

	bool		operator>( Fixed const & other) const ;
	bool		operator<( Fixed const & other ) const ;
	bool		operator>=( Fixed const & other ) const ;
	bool		operator<=( Fixed const & other ) const ;
	bool		operator==( Fixed const & other ) const ;
	bool		operator!=( Fixed const & other ) const ;

	Fixed		operator+( Fixed const & other ) const ;
	Fixed		operator-( Fixed const & other ) const ;
	Fixed		operator*( Fixed const & other ) const ;
	Fixed		operator/( Fixed const & other ) const ;
	Fixed&		operator++( void );
	Fixed&		operator--( void );
	Fixed		operator++( int );
	Fixed		operator--( int );

	static const Fixed &		min( Fixed const & a, Fixed const & b );
	static const Fixed &		max( Fixed const & a, Fixed const & b );
	static Fixed &				min( Fixed & a, Fixed & b );
	static Fixed &				max( Fixed & a, Fixed & b );

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