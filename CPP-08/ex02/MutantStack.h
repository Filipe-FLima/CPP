/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:45:00 by flima             #+#    #+#             */
/*   Updated: 2025/11/08 19:24:41 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
class	MutantStack
{
	private:
		std::vector<T> _container;
	
	public:
		~MutantStack() = default;
		MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		MutantStack& operator=(const MutantStack& other) = default;
		
		using value_type = T;
		using size_type = typename std::vector<T>::size_type;
		using iterator = typename std::vector<T>::iterator;
		using const_iterator = typename std::vector<T>::const_iterator;
		
		void		push(const T& element); //add element to the and of stack
		void		pop(); //remove last in element from stack;
		T& 			top(); //return the last in element
		const T& 	top() const; //const top 
		bool		empty() const noexcept; //return true if stack is empty
		size_type	size() const noexcept; //size of stack
		void		swap(MutantStack<T>& other) noexcept;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		
				
};

#include "MutantStack.tpp"

#endif

