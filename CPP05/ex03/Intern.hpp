/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 02:03:08 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 03:12:41 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INTERN_HPP
# define	INTERN_HPP

# include "Form.hpp"

class Intern
{

public:

	Intern( void );
	Intern( Intern const & src );
	~Intern( void );

	Intern &	operator=( Intern const & other );

	Form*		makeForm(std::string const & type, std::string const & target );

	class		NoForm : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "This kind of Form doesn't exist sir !"; }
	};

};

#endif