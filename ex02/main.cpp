/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:44:20 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/10/18 16:04:23 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}

// int	main(void)
// {
// 	std::list<int>	mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << mstack.back() << std::endl;

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(0);

// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::deque<int> d(mstack.begin(), mstack.end());
// 	std::stack<int> s(d);
// 	return (0);
// }




// ----------------------------------------------------------
// Weird checks
//-----------------------------------------------------------





// int	main(void)
// {
// 	MutantStack<int>	mstack;

// 	MutantStack<int>::iterator it_a = mstack.begin();
// 	MutantStack<int>::iterator ite_a = mstack.end();
// 	if (it_a != ite_a)
// 	{
// 		it_a--;
// 		--it_a;
// 		++ite_a;
// 		ite_a++;
// 		std::cout << *it_a << std::endl;;
// 	}
// 	try 
// 	{
// 		std::cout << mstack.top() << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	mstack.pop();

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	it++;
// 	it--;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return (0);
// }


// int	main(void)
// {
// 	std::list<int>	mstack;

// 	std::list<int>::iterator it_a = mstack.begin();
// 	std::list<int>::iterator ite_a = mstack.end();
// 	if (it_a != ite_a)
// 	{
// 		it_a--;
// 		--it_a;
// 		++ite_a;
// 		ite_a++;
// 		std::cout << *it_a << std::endl;;
// 	}
// 	try 
// 	{
// 		std::cout << mstack.back() << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	// mstack.pop_back();

// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << mstack.back() << std::endl;

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(0);

// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	it++;
// 	it--;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	return (0);
// }