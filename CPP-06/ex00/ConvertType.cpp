/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:42:20 by filipe            #+#    #+#             */
/*   Updated: 2025/10/22 11:40:20 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

// Convert from int literal
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
	if (!isprint(value))
		output << "Char: Non displayable\n";
	else
		output << "Char: '" << char(value) << "'\n";
	output << "Int: " << value << "\n";
	output << std::fixed << std::setprecision(1);
	output << "Float: " << static_cast<float>(value) << "f\n";
	output << "Double: " << static_cast<double>(value) << "\n";
	std::cout << output.str();
	return ;
}

// Convert from float literal
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
	if (!isprint(value))
		output << "Char: Non displayable\n";
	else
		output << "Char: '" << char(static_cast<int>(value)) << "'\n";
	output << "Int: " << static_cast<int>(value) << "\n";
	output << std::fixed << std::setprecision(1);;
	output << "Float: " << value << "f\n";
	output << "Double: " << static_cast<double>(value) << "\n";
	std::cout << output.str();
	return ;
}

// Convert from double literal
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
	if (!isprint(value))
		output << "Char: Non displayable\n";
	else
		output << "Char: '" << char(static_cast<int>(value)) << "'\n";
	output << "Int: " << static_cast<int>(value) << "\n";
	output << std::fixed << std::setprecision(1);
	output << "Float: " << static_cast<float>(value) << "f\n";
	output << "Double: " << value << "\n";
	std::cout << output.str();
	return ;
}

// Convert from pseudo-literal
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

// Convert from char literal
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