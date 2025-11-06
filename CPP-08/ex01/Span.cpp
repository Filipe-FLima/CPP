/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:32:42 by filipe            #+#    #+#             */
/*   Updated: 2025/11/06 15:33:42 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

Span::Span(unsigned int N) : 
    _filled{0},
    _num(N)
{
}

Span::Span(const Span& other)
{
    _filled = other._filled;
    _num = other._num;
}
