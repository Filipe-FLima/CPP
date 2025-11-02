/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:31:31 by filipe            #+#    #+#             */
/*   Updated: 2025/11/02 19:50:28 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

# include <exception>
#include <iostream>
#include <string>


template <typename T>
class   Array
{
    private:
        T               *array;
        unsigned int    size;
    
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        const unsigned int & getSize() const;
        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;
    
};

#include "Array.tpp"

#endif

