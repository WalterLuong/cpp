/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 05:13:51 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 20:06:59 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		KAREN_HPP
# define	KAREN_HPP

# include <iostream>
# include <string>

# define GR	"\033[1;32m"
# define NOR "\033[m"
# define YEL "\033[1;33m" 
# define IT "\033[3m"

class Karen
{

public:

	Karen( void );
	~Karen( void );

	int		complain( std::string level);
	void	filter( std::string level );

private:

	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );
};

#endif