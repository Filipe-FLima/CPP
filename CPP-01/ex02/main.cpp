/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:18:15 by flima             #+#    #+#             */
/*   Updated: 2025/07/18 11:58:40 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "The memory address of the string variable: " << &brain << "\n";
	std::cout << "The memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "The memory address held by stringREF: " << &stringREF << "\n\n";

	std::cout << "The value of the string variable: " << brain << "\n";
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << "\n";
	std::cout << "The value pointed to by stringREF: " << stringREF << "\n";
	
	return 0;
}