/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:44:46 by filipe            #+#    #+#             */
/*   Updated: 2025/12/08 10:52:43 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <chrono>
#include <concepts>


using intVector = std::vector<int>;
using intDeque = std::deque<int>;

class PmergeME
{
    public:
		class Pair
		{
			private:
				
				
			public:
				static size_t compCount;	
				int	a;
				int b;
				
				Pair(int _a, int _b);
				~Pair(){};
				Pair(const Pair& other);
				Pair& operator=(const Pair& other);
				bool operator<(const Pair& other);
				bool operator==(const int a);
				
		};
		
        PmergeME() = delete;
        ~PmergeME() = delete;
        PmergeME(const PmergeME& other) = delete;
        PmergeME& operator=(const PmergeME& other) = delete;
		
        static intVector PmergeMe(intVector c);
		static intDeque PmergeMe(intDeque c);
		static intVector getInsertionSeq(size_t pendSize);
        static void fillContainer(intVector& c, intDeque& d, char **tokens);
		static intVector getAsIndexs(size_t size);
		static void updateIndexAs(int idx, intVector& As);
		
    private:
  
};

using pairVector = std::vector<PmergeME::Pair>;
using pairDeque = std::deque<PmergeME::Pair>;
using Pair = PmergeME::Pair;

template <typename T>
static int	binarySearch(int idx, int b, T& mainChain)
{
	int &right = idx;
    int left  = 0; 
    while (left < right)
    {
        int mid = (left + right) / 2;
		Pair::compCount++;
        if (mainChain[mid] < b)
            left = mid + 1;
        else
            right = mid;
    }
    mainChain.insert(mainChain.begin() + left, b);
	return left;
}


template <typename T, typename U>
T insertion(T& c, U& pairs)
{
	T mainChain;
	T pend;

	getMainChain_N_Pend(mainChain, pend, pairs);

	if (c.size() % 2 == 1)
		pend.push_back(c[c.size() - 1]);
    intVector seqInsertion = PmergeME::getInsertionSeq(pend.size());

	intVector indexAs = PmergeME::getAsIndexs(pairs.size());

    for (size_t i = 0; i < seqInsertion.size(); ++i)
    {
		int idx;
        int x = seqInsertion[i];
		if ((size_t)(x - 1) == pairs.size()) //need it?
			idx = mainChain.size();
		else 
			idx = indexAs[x - 1];
        int pos = binarySearch(idx, pend[x - 1], mainChain);
		PmergeME::updateIndexAs(pos, indexAs);
    }
	return mainChain;
}

template <typename T>
void insertionPair(T& left, T& right)
{
	for (Pair x : right){
		auto pos = std::lower_bound(left.begin(), left.end(), x);
		left.insert(pos, x);
	}
}

template <typename T>
T merge_insertion(T& c)
{
	if (c.size() <= 1)
		return c;
	
	size_t mid = c.size() / 2;

	T left(c.begin(), c.begin() + mid);
	T right(c.begin() + mid, c.end());

	left = merge_insertion(left);
	right = merge_insertion(right);

	insertionPair(left, right);
	return left;
	
}

template <typename T, typename U>
void getMainChain_N_Pend(T& m, T& pend, U& p)
{
	m.push_back(p[0].b);
	m.push_back(p[0].a);
	pend.push_back(p[0].b);
	for (size_t i = 1; i < p.size(); ++i)
	{
		m.push_back(p[i].a);
		pend.push_back(p[i].b);
	}
}

#endif

