/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:50:55 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/10/18 14:42:31 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <list>

int	main(void)
{
	std::vector<int> v(3, 3);
	std::cout << easyfind(v, 3) << std::endl;

	std::list<int> l(2, 3);
	std::cout << easyfind(l, 3) << std::endl;

	std::deque<int> d(2, 3);
	std::cout << easyfind(d, 3) << std::endl;

	try
	{
		easyfind(v, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}