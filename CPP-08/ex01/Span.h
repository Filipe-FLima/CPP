/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:32:45 by filipe            #+#    #+#             */
/*   Updated: 2025/11/07 14:32:50 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <climits>
#include <vector>
#include <random>

class Span
{
    private:
        std::vector<int>    _num;
        unsigned int        _filledIdx;
    public:
		~Span();
        Span() = delete;
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);

		std::vector<int>::const_iterator begin() const;
		std::vector<int>::const_iterator end() const;
        void    addNumber(int num);
		void	printElements() const;
        unsigned int longestSpan() const;
        unsigned int shortestSpan() const;
		void	addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
    
	class MaxCapacity : public std::exception
	{
		const char * what() const noexcept override;
	};

	class NotEnoughElements : public std::exception
	{
		const char* what() const noexcept override;
	};
};

#endif