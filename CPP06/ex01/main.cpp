/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:48:53 by wluong            #+#    #+#             */
/*   Updated: 2022/01/15 05:13:23 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>


typedef struct		s_Data 
{
	int		n;
}					Data;

uintptr_t		serialize(Data* ptr) {
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data*			deserialize(uintptr_t raw) {
	Data	*ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}
int		main() {
	Data	*D = new Data;
	Data	*D2;
	D->n = 42;
	std::cout << "La valeur de l'int est : " << D->n << std::endl;
	uintptr_t u = serialize(D);
	std::cout << "La valeur de u apres un serialize(D) est : " << u << std::endl;
	D2 = deserialize(u);
	std::cout << "La valeur du nouveau int dans D2 est : " << D2->n << std::endl;
	std::cout << "\033[1;32mLe reinterpret_cast a permis de retrouver la valeur 42 !\033[m" << std::endl;
	delete D;
	
}