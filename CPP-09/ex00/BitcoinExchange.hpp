/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:07:54 by filipe            #+#    #+#             */
/*   Updated: 2025/11/12 20:53:34 by filipe           ###   ########.fr       */
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

# define MINYEAR 2009
# define MAXYEAR 2022
class Data
{
    private:
        std::map<std::string, std::string> data;
        std::string header;
        
        bool    isValidData(const std::string& data) const;
    
    public:
        Data(std::ifstream& file, char delimiter);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data() = default;

        void    printData(const std::string header) const;
        void    setHeader(const std::string& h);
        bool    isFormValid();
    
};

#endif