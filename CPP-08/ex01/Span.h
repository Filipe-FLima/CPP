/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:32:45 by filipe            #+#    #+#             */
/*   Updated: 2025/11/06 15:33:53 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H


#include <exception>
#include <iostream>
#include <iterator>
#include <vector>


class Span
{
    private:
        std::vector<int>    _num;
        unsigned int        _filled;
    public:
        Span() = delete;
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber();
        unsigned int shortestSpan();
        unsigned int longestSpan();
        
};

#endif