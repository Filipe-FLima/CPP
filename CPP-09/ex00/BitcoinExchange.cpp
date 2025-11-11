/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:11:23 by filipe            #+#    #+#             */
/*   Updated: 2025/11/11 21:28:18 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Data::Data(std::ifstream file, char delimiter)
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
