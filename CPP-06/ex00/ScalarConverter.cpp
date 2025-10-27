/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:03:12 by filipe            #+#    #+#             */
/*   Updated: 2025/10/27 13:02:44 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"



static bool	isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
			literal == "nanf" || literal == "+inff" || literal == "-inff");
}

static bool	isFloatnDoubleLiteral(const std::string &literal, int type) 
{
	size_t	len = literal.length();
	size_t	i = 0;
	size_t	dotCount = 0;
	
	if (type == FLOAT && (len < 3 || literal.back() != 'f'))
		return false;
	else if (type == DOUBLE && len < 2)
		return false;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (!isdigit(literal[i]) && literal[i] != '.')
		return false;
	while (i < len -1)
	{
		if (literal[i] == '.')
		{
			dotCount++;
			if (dotCount > 1)
				return false;
		}
		if (!isdigit(literal[i]) && literal[i] != '.')
			return false;
		i++;
	}
	if (dotCount == 0)
		return false;
	return true;
}


static int	getType(const std::string &literal)
{
	if (isPseudoLiteral(literal))
		return PSEUDO;
	else if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	else if (isFloatnDoubleLiteral(literal, FLOAT))
		return FLOAT;
	else if (isFloatnDoubleLiteral(literal, DOUBLE))
		return DOUBLE;
	else if (literal.find_first_not_of("0123456789+-") == std::string::npos)
		return INT;
		
	return NONE;
}


void ScalarConverter::convert(const std::string &literal)
{
	int type = getType(literal);
	std::ostringstream output;
	
	switch (type)
	{
		case CHAR:
			convertFromChar(literal, output);
			break;
		case INT:
			convertFromInt(literal, output);
			break;
		case FLOAT:
			convertFromFloat(literal, output);
			break;
		case DOUBLE:
			convertFromDouble(literal, output);
			break;
		case PSEUDO:
			convertFromPseudo(literal, output);
			break;
		default:
			std::cout << "Conversion impossible\n";
			break;
	}
	return ;
}
