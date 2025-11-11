/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:09:46 by filipe            #+#    #+#             */
/*   Updated: 2025/11/11 21:36:54 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isFileValid(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        return false;
    
    std::string line;
    getline(file, line);
    if (line != "Data | value")
        return false;
    return true;
}

int main() 
{

    
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
