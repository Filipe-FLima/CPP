/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:42:20 by filipe            #+#    #+#             */
/*   Updated: 2025/10/27 13:01:41 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"


static void convertChar(std::ostringstream& output, int value)
{

	if (!(value >= 32 && value <= 126))
		output << "Char: Non displayable\n";
	else
		output << "Char: '" << value << "'\n";
	
}

static void convertInt(std::ostringstream& output, float value)
{
	if (value < INT_MIN || value > INT_MAX)
		output << "Int: impossible\n";
	else
		output << "Int: " << static_cast<int>(value) << "\n";
}

static void convertInt(std::ostringstream& output, double value)
{
	if (value < INT_MIN || value > INT_MAX)
		output << "Int: impossible\n";
	else
		output << "Int: " << static_cast<int>(value) << "\n";
}

void convertFromInt(const std::string &literal, std::ostringstream &output)
{
	int value;
	try
	{
		value = std::stoi(literal);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "Conversion is impossible: Int overflow/underflow\n";
		return ;
	}
	catch(const std::exception& e)
	{
		output << "Char: impossible\n";
		output << "Int: impossible\n";
		output << "Float: impossible\n";
		output << "Double: impossible\n";
		std::cout << output.str();
		return ;
	}
	convertChar(output, value);
	output << "Int: " << value << "\n";
	output << std::fixed << std::setprecision(1);
	output << "Float: " << static_cast<float>(value) << "f\n";
	output << "Double: " << static_cast<double>(value) << "\n";
	std::cout << output.str();
	return ;
}


void	convertFromFloat(const std::string &literal, std::ostringstream &output)
{
	float value;
	try
	{
		value = std::stof(literal);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "Conversion is impossible: Float overflow/underflow\n";
		return ;
	}
	catch(const std::exception& e)
	{
		output << "Char: impossible\n";
		output << "Int: impossible\n";
		output << "Float: impossible\n";
		output << "Double: impossible\n";
		std::cout << output.str();
		return ;
	}
	convertChar(output, static_cast<int>(value));
	convertInt(output, static_cast<float>(value));
	output << std::fixed << std::setprecision(1);
	output << "Float: " << value << "f\n";
	output << "Double: " << static_cast<double>(value) << "\n";
	std::cout << output.str();
	return ;
}


void	convertFromDouble(const std::string &literal, std::ostringstream &output)
{
	double value;
	try
	{
		value = std::stod(literal);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "Conversion is impossible: Double overflow/underflow\n";
		return ;
	}
	catch(const std::exception& e)
	{
		output << "Char: impossible\n";
		output << "Int: impossible\n";
		output << "Float: impossible\n";
		output << "Double: impossible\n";
		std::cout << output.str();
		return ;
	}
	convertChar(output, static_cast<int>(value));
	convertInt(output, value);
	output << std::fixed << std::setprecision(1);
	output << "Float: " << static_cast<float>(value) << "f\n";
	output << "Double: " << value << "\n";
	std::cout << output.str();
	return ;
}


void convertFromPseudo(const std::string &literal, std::ostringstream &output)
{
	output << "Char: impossible\n";
	output << "Int: impossible\n";
	if (literal == "nan" || literal == "nanf")
	{
		output << "Float: nanf\n";
		output << "Double: nan\n";
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		output << "Float: +inff\n";
		output << "Double: +inf\n";
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		output << "Float: -inff\n";
		output << "Double: -inf\n";
	}
	std::cout << output.str();
	return ;
}


void	convertFromChar(const std::string &literal, std::ostringstream &output)
{
	if (!isprint(literal[0]))
	{
		output << "Char: Non displayable\n";
		output << "Int: impossible\n";
		output << "Float: impossible\n";
		output << "Double: impossible\n";	
	}
	else
	{
		output << "Char: '" << literal[0] << "'\n";
		output << "Int: " << static_cast<int>(literal[0]) << "\n";
		output << std::fixed << std::setprecision(1);
		output << "Float: " << static_cast<float>(literal[0]) << "f\n";
		output << "Double: " << static_cast<double>(literal[0]) << "\n";
	}
	
	std::cout << output.str();
	return ;

}