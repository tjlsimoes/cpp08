/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:50:51 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/09/15 17:50:51 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <stdlib.h>
#include <exception>
#include <algorithm>

template <typename T>
int easyfind(T container, int x)
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		if ((*it) == x)
			return *it;
	}

	throw std::exception();
}

// int &result = find(container, container.begin(), container.end(), x);
// if (result != container.end())
// 	return result;
// else
// 	throw std::exception();
// for (size_t i = 0; i < container.size(); i++)
// {
// 	if (container.at(i) == x)
// 		return (container.at(i));
// }

// std::find(container.begin(), container.end(), x);

#endif