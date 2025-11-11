/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:07:54 by filipe            #+#    #+#             */
/*   Updated: 2025/11/11 21:28:38 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <exception>
#include <fstream>


class Data
{
    private:
        std::map<std::string, std::string> data;
    
    public:
        Data(std::ifstream file, char delimiter);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data() = default;
        
    
}

#endif