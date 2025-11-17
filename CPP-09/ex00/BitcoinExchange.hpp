/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:07:54 by filipe            #+#    #+#             */
/*   Updated: 2025/11/17 14:18:13 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <sstream>
#include <exception>
#include <fstream>
#include <cmath>
#include <sstream>

# define MINYEAR 2009
# define MAXYEAR 2022
class Data
{
    public:
        Data(std::ifstream& file, char delimiter);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data() = default;

        using const_iterator = std::map<std::string, std::string>::const_iterator;
        const_iterator    cbegin() const;
        const_iterator    cend() const;
        
        void    printData() const;
        void    setHeader(const std::string& h);
        void    setFileName(const std::string& name);
        
        void 	exchangeBTC(const std::string& date, const std::string& value) const;
        
    
    private:
        std::map<std::string, std::string>	data;
        std::string 						header;
        std::string							fileName;
        
        
        const_iterator find(const std::string& date) const;
    
};

bool    isFormValid(const std::string& date);

#endif