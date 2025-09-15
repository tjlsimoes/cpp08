/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:50:31 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/09/15 17:50:32 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
#include <exception>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Span
{
	private:
		std::vector<int>	array;
		size_t				length;
		bool				sorted;
		static bool			seeded;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span & other);
		Span	&operator=(const Span &other);
		~Span();

		void	addNumber(int nbr);
		void	addRange();
		int		shortestSpan();
		int		longestSpan();
		static int		generate_sequence();
		void	print();

		class	FullArrayException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Adding element to filled array");
				}
		};

		class	InsufficientElementsException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Insufficient elements to calculate span");
				}
		};
	
};

int difference(const void* x, const void* y);

#endif