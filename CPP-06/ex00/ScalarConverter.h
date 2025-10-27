/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:57:44 by filipe            #+#    #+#             */
/*   Updated: 2025/10/27 12:42:49 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	NONE
};

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		
	public:
		static void convert(const std::string& literal);
};

void	convertFromChar(const std::string &literal, std::ostringstream &output);
void	convertFromInt(const std::string &literal, std::ostringstream &output);
void	convertFromFloat(const std::string &literal, std::ostringstream &output);
void	convertFromDouble(const std::string &literal, std::ostringstream &output);
void	convertFromPseudo(const std::string &literal, std::ostringstream &output);

#endif