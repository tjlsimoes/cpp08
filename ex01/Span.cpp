/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:50:30 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/09/15 17:50:30 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

bool	Span::seeded = false;

Span::Span() : length(0), sorted(false)
{}


Span::Span(unsigned int N) : length(N), sorted(false)
{}

Span::Span(const Span & other)
{
	array.assign(other.array.begin(), other.array.end());
	length = other.length;
	sorted = other.sorted;
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		array.clear();
		array.assign(other.array.begin(), other.array.end());
		length = other.length;
	}
	return (*this);
}

void	Span::addNumber(int nbr)
{
	if (array.size() == length)
		throw Span::FullArrayException();
	array.push_back(nbr);
	sorted = false;
}

void	Span::addRange()
{
	if (array.size() == length)
		throw Span::FullArrayException();
	array.resize(length);
	// std::iota(array.begin(), array.begin() + length - 1, 42);
	std::generate(array.begin(), array.end(), &generate_sequence);
	sorted = false;
}

int	Span::longestSpan()
{
	if (array.size() <= 1)
		throw Span::InsufficientElementsException();
	std::sort(array.begin(), array.end());
	// std::qsort(array.data(), array.size(), sizeof(array[0]), difference);
	sorted = true;
	return (array[array.size() - 1] - array[0]);
}

int	Span::shortestSpan()
{
	int	diff;

	if (array.size() <= 1)
		throw Span::InsufficientElementsException();
	if (!sorted)
	{
		std::sort(array.begin(), array.end());
		// std::qsort(array.data(), array.size(), sizeof(array[0]), difference);
		sorted = true;
	}
	diff = array[array.size() - 1] - array[array.size() - 2];
	for (int i = array.size() - 1; i > 0; i--)
	{
		if (array[i] - array[i - 1] < diff)
			diff = array[i] - array[i - 1];
	}
	return (diff);
}

void	Span::print()
{
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
}

// int	Span::generate_sequence()
// {
// 	static int	i = 42;
// 	return (i++);
// }

int	Span::generate_sequence()
{
	if (!seeded)
	{
		std::srand(time(0));
		seeded = true;
	}
	// static int	i = rand() % 100;
	// srand(time(NULL));
	// i += rand() % 100;
	return (rand() % 100);
}

Span::~Span()
{}

int difference(const void* x, const void* y)
{
	const int arg1 = *static_cast<const int*>(x);
	const int arg2 = *static_cast<const int*>(y);

	if (arg1 < arg2)
		return -1;
	if (arg1 > arg2)
		return 1;
	return 0;
}