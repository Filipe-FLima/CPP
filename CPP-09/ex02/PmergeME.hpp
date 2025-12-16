/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:44:46 by filipe            #+#    #+#             */
/*   Updated: 2025/12/15 13:03:12 by flima            ###   ########.fr       */
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
				size_t	getComp();
				bool operator<(const Pair& other);
				bool operator==(const int a);
				
		};

		class SortTime
		{
			private:
				std::chrono::steady_clock::time_point start;
			public:
				SortTime();
				~SortTime(){};
				SortTime(const SortTime& o) = delete;
				SortTime& operator=(const SortTime& o) = delete;
				double getTime();

		};

        PmergeME() = delete;
        ~PmergeME() = delete;
        PmergeME(const PmergeME& other) = delete;
        PmergeME& operator=(const PmergeME& other) = delete;
		
        static intVector PmergeMe(intVector& c);
		static intDeque PmergeMe(intDeque& c);
        static void fillContainer(intVector& c, intDeque& d, char **tokens);
		
    private:
		
		using pairVector = std::vector<PmergeME::Pair>;
		using pairDeque = std::deque<PmergeME::Pair>;

		static intVector getInsertionSeq(size_t pendSize);
		static intVector getAsIndexs(size_t size);
		static void updateIndexAs(int idx, intVector& As);

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

		template <typename T>
		static int	easyFind(T& pairs, int a)
		{
			auto it = find(pairs.begin(), pairs.end(), a);
			if (it == pairs.end())
				return pairs[pairs.size() - 1].b;
			int b = it->b;
			return b;
		}

		template <typename T, typename U>
		static intVector getPend(T& As, U& pairs)
		{
			intVector pend;
			for (size_t i = 0; i < As.size(); ++i)
			{
				int b = easyFind(pairs, As[i]);
				pend.push_back(b);
			}
			return pend;
		}

		template <typename T, typename U>
		static T insertion(T& c, T& As, U& pairs)
		{
			T mainChain;
			intVector pend;

			getMainChain(mainChain, As, pairs);
			pend = getPend(As, pairs);

			if (c.size() % 2 == 1)
				pend.push_back(c[c.size() - 1]);
			int pendSize = pend.size();
			intVector seqInsertion = getInsertionSeq(pendSize);

			intVector indexAs = getAsIndexs(pairs.size());

			for (size_t i = 0; i < seqInsertion.size(); ++i)
			{
				int idx;
				int x = seqInsertion[i];
				if (x == pendSize && c.size() % 2 == 1)
					idx = mainChain.size();
				else 
					idx = indexAs[x - 1];
				int pos = binarySearch(idx, pend[x - 1], mainChain);
				updateIndexAs(pos, indexAs);
			}
			return mainChain;
		}

		template <typename T, typename U>
		static void getMainChain(T& m, T& As, U& p)
		{
			int b = easyFind(p, As[0]);
			m.push_back(b);
			for (size_t i = 0; i < As.size(); ++i)
				m.push_back(As[i]);
		}

		template <typename T, typename U>
		static	T getAsCont(T& type, U& pairs)
		{
			T c;
			
			(void)type;
			for (size_t i = 0; i < pairs.size(); ++i)
				c.push_back(pairs[i].a);
			return c;
		}
  
};

using Pair = PmergeME::Pair;

#endif

