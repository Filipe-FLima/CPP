/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:11:23 by filipe            #+#    #+#             */
/*   Updated: 2025/11/12 20:50:59 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Data::Data(std::ifstream& file, char delimiter)
{
    std::string line;

    
    while (getline(file, line))
    {
        std::stringstream   ss(line);
        std::string         key;
        std::string         value;

        getline(ss, key, delimiter);
        getline(ss, value, delimiter);

        data[key] = value;        
    }

    file.close();
}

Data::Data(const Data &other)
{
    data = other.data;
}

Data &Data::operator=(const Data &other)
{
    if (this != &other)
        data = other.data;
    return *this;
}

void Data::printData(std::string header) const
{
    std::cout << header << std::endl;
    for (auto  it = data.begin(); it != data.end(); ++it)
    {
        std::cout << it->first << " | " << it->second <<std::endl;
    }
}

void Data::setHeader(const std::string &h)
{
    header = h;
}

bool Data::isFormValid()
{
    for (auto  it = data.begin(); it != data.end(); ++it)
    {
        if (!isValidData(it->first))
            return false;
    }
    
    return true;
}

static  int convertDataValue(std::string value)
{
    int _value;
    
    try
    {
        _value = stoi(value);
    }
    catch(const std::exception& e)
    {
        _value = -1;
    }
    return _value;
}

static bool    isValidDataFormat(const std::string& data)
{
    if (data.size() != 10)
        return false;
    if (data[4] != '-' || data[7] != '-')
        return false;
    
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if(!std::isdigit(data[i]))
            return false; 
    }
    return true;
}

bool Data::isValidData(const std::string& data) const
{
    if (!isValidDataFormat(data))
        return false;
    int year = convertDataValue(data.substr(0, 4));
    int month = convertDataValue(data.substr(5, 7));
    int day = convertDataValue(data.substr(8, 10));

    if (year == -1 || month == -1 || day == -1)
        return false;
    
    if (year < MINYEAR || year > MAXYEAR)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    bool isleap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    if (month == 2 && day > (isleap ? 29 : 28))
        return false;
        
    return true;
}
