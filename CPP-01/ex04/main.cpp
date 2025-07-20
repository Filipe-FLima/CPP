/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:53:07 by flima             #+#    #+#             */
/*   Updated: 2025/07/20 18:23:31 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string	replaceContent(std::ifstream& infile, std::string s1, std::string s2)
{
	std::stringstream	buffer;
	buffer << infile.rdbuf();
	infile.close();

	std::string	content = buffer.str();
	std::string strcat;
	size_t found = 0, pos = 0;
	
	while((found = content.find(s1, pos)) != std::string::npos)
	{
		strcat.append(content, pos, found - pos);
		strcat.append(s2);
		pos = found + s1.length();
	}
	strcat.append(content, pos, content.length() - pos);
	return strcat;
}

int main(int argc, char **argv)
{
	if (argc == 4){
		std::ifstream	infile(argv[1], std::ios::in);
		if (!infile.is_open()){
			std::cerr << "Error: Could not open the file passed as argument!" << std::endl;
			return 1;
		}
		std:: string content = replaceContent(infile, argv[2], argv[3]);
		std::ofstream newfile(std::string(argv[1]) + ".replace", std::ios::out);
		if (!newfile.is_open())
		{
			std::cerr << "Error: Could not open the newfile!" << std::endl;
			return 1;
		}
		newfile << content;
		newfile.close();
	}
	else
		std::cerr << "Ivalid input!" << std::endl;
	return 0;
}