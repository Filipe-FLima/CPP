/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:33:55 by filipe            #+#    #+#             */
/*   Updated: 2025/10/25 15:14:04 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Serializer.h"
#include <iostream>
#include <cstdint>  

struct Data {
    int value;
};

int main(void) 
{
    Data data = {42};
    Data* ptr = &data;

    // Serializa (ponteiro → inteiro)
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Ponteiro como inteiro: " << raw << std::endl;

    // Desserializa (inteiro → ponteiro)
    Data* restored = reinterpret_cast<Data*>(raw);
    std::cout << "Valor restaurado: " << restored->value << std::endl;
	return 0;
}