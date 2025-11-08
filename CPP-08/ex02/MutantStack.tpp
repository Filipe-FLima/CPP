/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:49:40 by flima             #+#    #+#             */
/*   Updated: 2025/11/08 19:29:52 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"

template <typename T>
inline void MutantStack<T>::push(const T &element)
{
	_container.push_back(element);
}

template <typename T>
inline void MutantStack<T>::pop()
{
	if (_container.empty())
		throw std::runtime_error("Empty container.");
	_container.pop_back();
}

template <typename T>
inline T &MutantStack<T>::top()
{
	if (_container.empty())
		throw std::runtime_error("Empty container.");
	return _container.back();
}

template <typename T>
inline const T &MutantStack<T>::top() const
{
	if (_container.empty())
		throw std::runtime_error("Empty container.");
	return _container.back();
}

template <typename T>
inline bool MutantStack<T>::empty() const noexcept
{
	return (_container.size()) ? false : true;
}

template <typename T>
inline typename MutantStack<T>::size_type MutantStack<T>::size() const noexcept
{
	return _container.size();
}

template <typename T>
inline void MutantStack<T>::swap(MutantStack<T> &other) noexcept
{
	_container.swap(other._container);
}


template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return _container.begin();
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return _container.end();
}

template <typename T>
inline typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return _container.begin();
}

template <typename T>
inline typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return _container.end();
}
