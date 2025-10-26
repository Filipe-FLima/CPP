/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:33:49 by filipe            #+#    #+#             */
/*   Updated: 2025/10/26 19:57:58 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

int main(void) 
{
    {
        Data person = {"Filipe", 25};
        std::cout << "Name: " << person.name << std::endl << "Age: " << person.age << std::endl;
        uintptr_t raw = Serializer::serialize(&person);
        std::cout << "Serialized data (" << &person << "): " << raw << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Deserializing..." << std::endl;
        Data* deserializedPerson = Serializer::deserialize(raw);
        std::cout << "Name: " << deserializedPerson->name << std::endl << "Age: " << deserializedPerson->age << std::endl;
    }
    std::cout << "========================" << std::endl;
    {
        Data* person = new Data();
        person->name = "Mateus";
        person->age = 45;
        std::cout << "Name: " << person->name << std::endl << "Age: " << person->age << std::endl;
        uintptr_t raw = Serializer::serialize(person);
        std::cout << "Serialized data (" << &person << "): " << raw << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Deserializing..." << std::endl;
        Data* deserializedPerson = Serializer::deserialize(raw);
        deserializedPerson->name = "Carlos";
        deserializedPerson->age = 30;
        std::cout << "Name: " << person->name << std::endl << "Age: " << person->age << std::endl;
        delete person;
    }
    
    return 0;
}