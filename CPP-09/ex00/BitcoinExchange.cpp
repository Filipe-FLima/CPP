/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:11:23 by filipe            #+#    #+#             */
/*   Updated: 2025/11/15 22:59:44 by filipe           ###   ########.fr       */
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

void Data::printData() const
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

void Data::setFileName(const std::string &name)
{
    fileName = name;
}

bool Data::isFormValid(const_iterator& it) const
{
    
    if (!isValidDate(it->first))
          return false;
    return true;
}

Data::const_iterator Data::cbegin() const
{
    return data.cbegin();
}

Data::const_iterator Data::cend() const
{
    return data.cend();
}

void Data::exchangeBTC(const Data &obj) const
{
    std::ostringstream output;
    obj.printData();
    // for (const_iterator it = obj.cbegin(); it != obj.cend(); ++it)
    // {
    //     const_iterator itDB;
        
    //     if (obj.isFormValid(it))
    //     {
    //         std::cout << "Error: bad input => " << it->first << '\n'; 
    //         continue;
    //     }
        
    //     output << it->first << " => " << it->second << " ";
        
    //     try
    //     {
    //         std::cout << it->first << '\n';
    //         itDB = find(it);
            
    //         std::cout << itDB->first << '\n';
    //     }
    //     catch (std::exception& e)
    //     {
    //         std::cout << e.what() << std::endl;
    //         output.str("");
    //         output.clear();
    //         continue;
    //     }
    //     if (!isFormValid(itDB))
    //     {
    //         output.str("");
    //         output.clear();
    //         output << "Error: bad input => " << itDB->first;   
    //     }
    //     else 
    //         resultValue(itDB, it, output);
    //     std::cout << output.str() << std::endl;
    // }
    
}

static  int convertDateValue(std::string value)
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

static bool    isValidDateFormat(const std::string& data)
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

bool Data::isValidDate(const std::string& data) const
{
    if (!isValidDateFormat(data))
        return false;
    int year = convertDateValue(data.substr(0, 4));
    int month = convertDateValue(data.substr(5, 7));
    int day = convertDateValue(data.substr(8, 10));

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

Data::const_iterator Data::find(const_iterator& it) const
{
    auto itFound = data.find(it->first);
    if (itFound == data.end())
    {
        itFound = data.lower_bound(it->first);
        if (itFound == data.begin())
            throw std::runtime_error("Error: date not found in DataBase.");
        itFound--;
    }
    return itFound;
}

void Data::resultValue(const_iterator itDB, const_iterator itObj, std::ostringstream& os) const
{
    float value;
    float DB;

    try
    {
        value = std::stof(itObj->second);
        DB = std::stof(itDB->second);
    }
    catch(const std::out_of_range& e)
    {
        os.clear();
        os << "Error: too large number.";
        return;
    }
    if (std::signbit(value) || std::signbit(DB))
    {
        os.clear();
        os << "Error: not a possitive number.";
        return;
    }
    float result = value * DB;
    os << result;
}

