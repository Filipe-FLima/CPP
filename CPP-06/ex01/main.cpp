/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:33:49 by filipe            #+#    #+#             */
/*   Updated: 2025/10/25 15:17:59 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>  

struct Data {
    int value;
};

int main(void) 
{
    int data = 42;
    int* ptr = &data;

    // Serializa (ponteiro → inteiro)
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Ponteiro como inteiro: " << raw << std::endl;

    // Desserializa (inteiro → ponteiro)
    int* restored = reinterpret_cast<int*>(raw);
    std::cout << "Valor restaurado: " << *restored << std::endl;
	return 0;
}