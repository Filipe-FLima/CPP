/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:57:44 by filipe            #+#    #+#             */
/*   Updated: 2025/10/19 20:41:40 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

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