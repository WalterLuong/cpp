/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:02:39 by wluong            #+#    #+#             */
/*   Updated: 2022/01/20 03:56:40 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SPAN_HPP
# define	SPAN_HPP

# include <vector>
# include <iterator>
# include <iostream>
# define GR "\033[1;32m"
# define YEL "\033[1;33m"
# define NOR "\033[m"

class Span
{

public:

	Span( Span const & src );
	Span( unsigned int N );
	~Span( void );

	Span &		operator=( Span const & other );

	void		addNumber( int nbr );
	int			shortestSpan( void );
	int			longestSpan( void );
	void		addRangeIt( std::vector<int>::iterator first, std::vector<int>::iterator last );
	void		printTab( void ) const;


	class	VectorIsFull : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "Vector is already full." ;}
	};

	class	NotEnoughNumbers : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "There is not enough numbers." ;}
	};

private:

	Span( void );
	std::vector<int>		_tab;
	unsigned int		_size;

};

#endif