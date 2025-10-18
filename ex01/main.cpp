/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:50:28 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/10/18 15:10:57 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
int	main(void)
{

	Span sp_a = Span(5);
	sp_a.addNumber(6);
	sp_a.addNumber(3);
	sp_a.addNumber(17);
	sp_a.addNumber(9);
	sp_a.addNumber(11);
	std::cout << sp_a.shortestSpan() << std::endl;
	std::cout << sp_a.longestSpan() << std::endl;

	std::cout << "-----------------------" << std::endl;

	Span sp(100000);

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const Span::InsufficientElementsException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	try
	{
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const Span::InsufficientElementsException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	
	sp.addRange();
	try
	{
		sp.addNumber(1);
	}
	catch(const Span::FullArrayException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	// sp.print();
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "-----------------------" << std::endl;

	Span	*sp_b = new Span(50);
	sp_b->addRange();
	std::cout << sp_b->longestSpan() << std::endl;
	std::cout << sp_b->shortestSpan() << std::endl;
	Span	*sp_c = new Span(*sp_b);
	delete sp_b;
	std::cout << sp_c->longestSpan() << std::endl;
	std::cout << sp_c->shortestSpan() << std::endl;
	delete sp_c;
	return (0);
}