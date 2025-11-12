/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:09:46 by filipe            #+#    #+#             */
/*   Updated: 2025/11/12 20:35:22 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::ifstream isFileValid(std::string fileName, std::string header)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Can not open file " + fileName);
    std::string line;
    getline(file, line);
    if (line != header)
        throw std::runtime_error("Invalid header file " + fileName);
    return file;
}

int main() 
{
    std::ifstream dataFile;
    try
    {
        dataFile = isFileValid("data1.csv", "date,exchange_rate");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    Data rates(dataFile, ',');
    // rates.printData("date,exchange_rate");
    if (!rates.isFormValid())
    {
        std::cout << "Ivalid format.\n";
        return 1;
    }
    std::cout << "Valid\n";
    return 0;
    
    // map<string, double> rate = {
    //     {"2009-01-02", 1.0},
    //     {"2009-01-05", 2.0},
    //     {"2009-01-08", 3.0},
    //     {"2009-01-11", 4.0}
    // };

    // string dataBuscada = "2009-01-07";
    // auto it = rate.lower_bound(dataBuscada);
    // cout << "Data exata encontrada: " << it->first
    //           << "  rate = " << it->second << endl;
    // // if (it == rate.begin()) {
    // //     cout << "Nenhuma data anterior disponível." << endl;
    // // } else if (it == rate.end() || it->first != dataBuscada) {
    // //     // se passou do fim ou a chave não é igual, pegamos o anterior
    // //     --it;
    // //     cout << "Data mais próxima anterior: " << it->first
    // //          << "  rate = " << it->second << endl;
    // // } else {
    // //     // encontrou exatamente
    // //     cout << "Data exata encontrada: " << it->first
    // //          << "  rate = " << it->second << endl;
    // // }
}
