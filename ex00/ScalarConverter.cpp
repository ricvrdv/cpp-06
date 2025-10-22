/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:08:03 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/10/13 17:08:12 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Canonical Form members
ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter( ScalarConverter const &other ){ (void)other; }

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &other )
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

// Member function - convert()

static bool isSpecialValue( const std::string &literal ) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff" ||
            literal == "inf" || literal == "inff");
}

static void handleSpecialValue( const std::string &literal ) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
    else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

void    ScalarConverter::convert( const std::string &literal )
{
    if (isSpecialValue(literal)) {
        handleSpecialValue(literal);
        return;
    }
}

