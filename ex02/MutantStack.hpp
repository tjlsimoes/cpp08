/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:44:18 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/10/18 15:57:53 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <deque>

template <typename T>
class MutantStack
{
	private:
		std::vector<T> vec;

	public:
		MutantStack()
		{};
		MutantStack(const MutantStack & other)
		{
			vec.assign(other.vec.begin(), other.vec.end());
		};
		MutantStack	&operator=(const MutantStack &other)
		{
			if (this != &other)
			{
				vec.clear();
				vec.assign(other.vec.begin(), other.vec.end());
			}
			return (*this);
		};

		~MutantStack()
		{};

		T		&top()
		{
			return (vec.at(vec.size() - 1));
		};

		bool	empty()
		{
			return (vec.empty());
		}
		size_t	size()
		{
			return (vec.size());
		}
		void	push(T add)
		{
			return (vec.push_back(add));
		}
		void	pop()
		{
			if (!vec.empty())
				vec.pop_back();
		}

		
		struct iterator 
		{
			// Properties iterator
			// using Category = std::bidirectional_iterator_tag;
			// using Distance = std::ptrdiff_t;
			// Shorthand
			
			public:
				T 	*mPtr;
			
				iterator(T *ptr) : mPtr(ptr)
				{}

				T	&operator*() const
				{
					if (!mPtr)
						throw std::runtime_error("Dereferencing null iterator");
					return (*mPtr);
				}

				T	*operator->(){
					if (!mPtr)
						throw std::runtime_error("Accessing null iterator");
					return mPtr;
				}

				// --it
				iterator &operator--()
				{
					if (mPtr)
						--mPtr;
					return (*this);
				}

				// it--
				iterator operator--(int)
				{
					iterator tmp = *this;
					if (mPtr)
						--(*this);
					return (tmp);
				}

				// ++it
				iterator &operator++()
				{
					if (mPtr)
						++mPtr;
					return (*this);
				}

				// it++
				iterator operator++(int)
				{
					iterator tmp = *this;
					if (mPtr)
						++(*this);
					return (tmp);
				}

				bool operator==(const iterator &b)
				{
					return this->mPtr == b.mPtr;
				}

				bool operator!=(const iterator &b)
				{
					return this->mPtr != b.mPtr;
				}
		};


		T & operator[] (size_t index)
		{
			return vec.at(index);
		}


		iterator begin()
		{
			if (vec.empty())
				return (NULL);
			return (iterator(&vec.at(0)));
		}

		iterator end()
		{
			if (vec.empty())
				return (NULL);
			return (iterator(&vec[vec.size()]));
		}

		operator std::deque<T>() const
		{
			return std::deque<T>(vec.begin(), vec.end());
		}

};

#endif