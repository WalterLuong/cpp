/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:23:43 by wluong            #+#    #+#             */
/*   Updated: 2021/12/26 17:33:46 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BOOK_HPP
# define	BOOK_HPP

# include "contact.hpp"



class	Book {

public :

		Book(int nbr);
		~Book(void);

		void			waiting_cmd(void);
		Contact			add_contact(void);
		void			search_contact(Contact[8], int size);
		std::string		resize_contact(std::string);
private:

		int				_nb_cont;
		Contact 		_all[8];
		


};

#endif