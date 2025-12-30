/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:11:23 by filipe            #+#    #+#             */
/*   Updated: 2025/12/29 15:20:47 by flima            ###   ########.fr       */
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


Data::const_iterator Data::cbegin() const
{
    return data.cbegin();
}

Data::const_iterator Data::cend() const
{
    return data.cend();
}

static void	reWriteOS(std::ostringstream& os, const std::string& newstr)
{
	os.str("");
    os.clear();
	os << newstr;
}
static void resultValue(Data::const_iterator itDB, const std::string& _value, std::ostringstream& os, const std::string& date)
{
    float value;
    float DB;
	size_t pos;
    try
    {
        value = std::stof(_value, &pos);
		if (pos != _value.size())
        	throw std::invalid_argument("invalid characters in value");
        DB = std::stof(itDB->second);
    }
    catch(const std::out_of_range& e)
    {
		reWriteOS(os, "Error: too large number.");
        return;
    }
	catch(const std::exception& e)
	{
		reWriteOS(os, "Error: Invalid value.");
        return;
	}
	if (value == 0)
	{
		reWriteOS(os, date + " => 0 = 0");
        return;
	}
    if (std::signbit(value) || std::signbit(DB))
    {
		reWriteOS(os, "Error: not a positive number.");
        return;
    }
	if (value > 1000)
	{
		reWriteOS(os, "Error: too large number.");
        return;
	}
    float result = value * DB;
    os << result;
}

void Data::exchangeBTC(const std::string& date, const std::string& value) const
{
    std::ostringstream	output;
	
    const_iterator itDB;
        
	if (!isFormValid(date) || value == "")
	{
		std::cout << "Error: bad input => " << date << '\n'; 
		return;
	}
	
	// output << std::fixed << std::setprecision(2);
	output << date << " => " << value << " = ";
	
	try
	{
		itDB = find(date);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	resultValue(itDB, value, output, date);
	std::cout << output.str() << std::endl;
    
}

Data::const_iterator Data::find(const std::string& date) const
{
    auto itFound = data.find(date);
    if (itFound == data.end())
    {
        itFound = data.lower_bound(date);
        if (itFound == data.begin())
            throw std::runtime_error("Error: date not found in DataBase.");
        --itFound;
    }
    return itFound;
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

static bool    isValidDateFormat(const std::string& date)
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return false; 
    }
    return true;
}

static bool isValidDate(const std::string& date)
{
    if (!isValidDateFormat(date))
        return false;
    int year = convertDateValue(date.substr(0, 4));
    int month = convertDateValue(date.substr(5, 7));
    int day = convertDateValue(date.substr(8, 10));

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

bool isFormValid(const std::string& date)
{
    
    if (isValidDate(date))
          return true;
    return false;
}