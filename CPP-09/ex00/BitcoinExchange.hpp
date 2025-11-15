/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:07:54 by filipe            #+#    #+#             */
/*   Updated: 2025/11/15 22:59:17 by filipe           ###   ########.fr       */
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
        bool    isFormValid(const_iterator& it) const;
        
        void    exchangeBTC(const Data& obj) const;
        
    
    private:
        std::map<std::string, std::string> data;
        std::string header;
        std::string fileName;
        
        bool    isValidDate(const std::string& data) const;
        Data::const_iterator    find(const_iterator& it) const;
        void    resultValue(const_iterator itDB, const_iterator itObj, std::ostringstream& os) const;
    
};

#endif