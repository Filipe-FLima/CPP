/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:09:46 by filipe            #+#    #+#             */
/*   Updated: 2025/11/19 13:30:51 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::ifstream isFileValid(std::string fileName, std::string header)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file " + fileName);
    std::string line;
    getline(file, line);
    if (line != header)
        throw std::runtime_error("Error: Invalid header file " + fileName);
    return file;
}

std::string trim(std::string& s) 
{
    std::string trimmed;
    
    size_t first = s.find_first_not_of(' ');
    size_t last = s.find_last_not_of(' ');
    
    trimmed = s.substr(first, last - first + 1);
    
    return trimmed;
}

static void	btcExchange(const Data& data, std::ifstream& input)
{
	std::string line;

	while (getline(input, line))
	{
		std::stringstream   ss(line);
		std::string 		date;
		std::string 		value;
		
		getline(ss, date, '|');
		getline(ss, value, '|');
		
		if (date [date.size() - 1] == ' ' && value[0] == ' ')
		{
			date = trim(date);
			value = trim(value);
		}
        for (size_t i = 0; i < value.size(); ++i)
        {   
            if (!std::isdigit(value[i]))
                value = "";
        }
		data.exchangeBTC(date, value);
	}
	input.close();
}

int main(int argc, char **argv) 
{
    if (argc != 2)
	{
        std::cout << "Error: could not open the file.\n";
		return 1;
	}
    std::ifstream inputFile;
    std::ifstream dataFile;
	
    try
    {
        dataFile = isFileValid("data.csv", "date,exchange_rate");
        inputFile = isFileValid(argv[1], "date | value");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    Data BtcRates(dataFile, ',');
    
    BtcRates.setFileName("data.csv");
    BtcRates.setHeader("date,exchange_rate");
	btcExchange(BtcRates, inputFile);
    return 0;
}
