/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:43:57 by filipe            #+#    #+#             */
/*   Updated: 2025/11/02 19:23:30 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"

template <typename T>
Array<T>::Array() : 
    array{nullptr},
    size{0}
{
}

template <typename T>
Array<T>::Array(unsigned int n):
    array{new T[n]()},
    size{n}
{
}

template <typename T>
Array<T>::Array(const Array &other):
    array{new T[other.size]},
    size{other.size}
{
    for (unsigned int i = 0; i < size; i++)
        array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] array;
        array = new T[other.size];
        size = other.size;
        
        for (unsigned int i = 0; i < size; i++)
            array[i] = other.array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
const unsigned int &Array<T>::getSize() const
{
    return size;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= size)
        throw std::exception();
    return array[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{  
    if (i >= size)
        throw std::exception();
    return array[i];
    
}
