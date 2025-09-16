/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:44:18 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/09/16 13:44:19 by tjorge-l         ###   ########.fr       */
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
			return (vec[vec.size() - 1]);
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
					return (*mPtr);
				}

				T	*operator->(){
					return mPtr;
				}

				// --it
				iterator operator--()
				{
					--mPtr;
					return (*this);
				}

				// it--
				T 	*operator--(T)
				{
					iterator tmp = *this;
					--(*this);
					return (tmp);
				}

				// ++it
				iterator operator++()
				{
					++mPtr;
					return (*this);
				}

				// it++
				T 	*operator++(T)
				{
					iterator tmp = *this;
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
			return vec[index];
		}


		iterator begin()
		{
			return (iterator(&vec[0]));
		}

		iterator end()
		{
			return (iterator(&vec[vec.size()]));
		}

		operator std::deque<T>() const
		{
			return std::deque<T>(vec.begin(), vec.end());
		}

};

#endif