/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:45:00 by flima             #+#    #+#             */
/*   Updated: 2025/11/10 15:13:54 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{

	public:
		~MutantStack() = default;
		MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		MutantStack& operator=(const MutantStack& other) = default;
		
		using iterator = typename std::stack<T>::container_type::iterator;
		using const_iterator = typename std::stack<T>::container_type::const_iterator;
		
		iterator begin() {return this->c.begin();}
		iterator end() { return this->c.end();}
		const_iterator cbegin() const {return this->c.cbegin();}
		const_iterator cend() const {return this->c.cend();}
				
};

#endif

