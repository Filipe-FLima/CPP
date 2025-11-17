/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:09:46 by filipe            #+#    #+#             */
/*   Updated: 2025/11/17 14:11:25 by flima            ###   ########.fr       */
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
    size_t first = s.find_first_not_of(' ');
    size_t last = s.find_last_not_of(' ');
    return s.substr(first, last - first + 1);
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
