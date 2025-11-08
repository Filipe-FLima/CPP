/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:32:42 by filipe            #+#    #+#             */
/*   Updated: 2025/11/08 13:49:54 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

Span::Span(unsigned int N) : 
	_num(N),
    _filledIdx{0}
{
}

Span::Span(const Span& other)
{
    _num = other._num;
    _filledIdx = other._filledIdx;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_num = other._num;
    	_filledIdx = other._filledIdx;
	}
	return *this;
}

std::vector<int>::const_iterator Span::begin() const
{
	return _num.begin();
}

std::vector<int>::const_iterator Span::end() const
{
	return _num.end();
}

unsigned int Span::getFilledIdx() const
{
	return _filledIdx;
}

Span::~Span()
{
	
}

void Span::addNumber(int num)
{
	if (_filledIdx == _num.size())
		throw MaxCapacity();
	_num[_filledIdx] = num;
	_filledIdx++;
}

void Span::printElements() const
{
	for (int i : _num)
		std::cout << i << " ";
}

void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (_filledIdx == _num.size())
		throw MaxCapacity();
	if (std::distance(_num.cbegin(), begin) < 0 || 
		std::distance(_num.cbegin(), end) < 0 ||
		std::distance(_num.cend(), begin) >= 0 ||
		std::distance(_num.cend(), end) > 0)
		throw std::out_of_range("Iterator out of range.");
	if (std::distance(begin, _num.cbegin() + _filledIdx) < 0)
		throw std::runtime_error("Can not add element out of sequence.");
	
	std::random_device	seed;
	std::mt19937		gen(seed());
	std::uniform_int_distribution<> dist(INT_MIN, INT_MAX);

	_filledIdx = std::distance(_num.cbegin(), begin);
	for (auto it = _num.begin() + _filledIdx; it != _num.begin() + std::distance(_num.cbegin(), end); ++it)
	{
		*it = dist(gen);
		_filledIdx++;
	}
}

unsigned int Span::shortestSpan() const
{
	if (_filledIdx <= 1)
		throw NotEnoughElements();
		
	std::vector<int> tmp(_num.begin(), _num.begin() + _filledIdx);
	std::sort(tmp.begin(), tmp.end());

	unsigned int diff;
	unsigned int span = UINT_MAX;
	for (size_t i = 1; i != tmp.size(); ++i)
	{
		diff = tmp[i] - tmp[i - 1];
		if (span > diff)
			span = diff;
	}
	return span;
}

unsigned int Span::longestSpan() const
{
	if (_filledIdx <= 1)
		throw NotEnoughElements();
	auto minIt = std::min_element(_num.begin(), _num.begin() + _filledIdx);
	auto maxIt = std::max_element(_num.begin(), _num.begin() + _filledIdx);

	return  *maxIt - *minIt;
}

const char *Span::MaxCapacity::what() const noexcept
{
	return "Max elements stored";
}

const char *Span::NotEnoughElements::what() const noexcept
{
	return "No span can be found";
}

