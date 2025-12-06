/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:44:46 by filipe            #+#    #+#             */
/*   Updated: 2025/12/01 14:49:04 by flima            ###   ########.fr       */
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

struct pairInt
{
    int a;
    int b;
};

using intVector = std::vector<int>;
using intDeque = std::deque<int>;
using pairVector = std::vector<pairInt>;
using pairDeque = std::deque<pairInt>;


class PmergeME
{
    public:
        PmergeME() = delete;
        ~PmergeME() = delete;
        PmergeME(const PmergeME& other) = delete;
        PmergeME& operator=(const PmergeME& other) = delete;
    
        static intVector sort(intVector c);
		//intVector merge_insertion(intVector c, intVector& pend);
        // static void sort(intDeque& c);
        static void fillContainer(intVector& c, intDeque& d, char **tokens);
        
    private:

        
};

#endif

