/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:06:48 by filipe            #+#    #+#             */
/*   Updated: 2025/10/27 13:11:58 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"


std::string trimSpaces(std::string toTrim)
{
	if (toTrim.length() == 1 && toTrim[0] == ' ')
		return toTrim;
	size_t start = toTrim.find_first_not_of(" ");
	if (start == std::string::npos)
		return "";
	size_t end = toTrim.find_last_not_of(" ");
	return toTrim.substr(start, end - start + 1);
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	
	std::string input = argv[1];
	std::string literal = trimSpaces(input);
	ScalarConverter::convert(literal);
	
	return 0;
}
