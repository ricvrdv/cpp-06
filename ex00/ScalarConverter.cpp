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

static void	printCharConversion(double value) {
	if (value >= std::numeric_limits<char>::min() &&
		value <= std::numeric_limits<char>::max()) {
		char	c = static_cast<char>(value);
		if (std::isprint(c)) {
			std::cout << "char: '" << c << "'\n";
		}
		else {
			std::cout << "char: Non displayable\n";
		}
	}
	else {
		std::cout << "char: impossible\n";
	}
}

static void	printIntConversion(double value) {
	if (value >= std::numeric_limits<int>::min() &&
		value <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(value) << "\n";
	}
	else {
		std::cout << "int: impossible\n";
	}
}

static void	printFloatConversion(double value) {
	float	floatVal = static_cast<float>(value);
	std::cout << "float: " << floatVal;
	if (floatVal == static_cast<long>(floatVal)) {
		std::cout << ".0";
	}
	std::cout << "f\n";
}

static void	printDoubleConversion(double value) {
	std::cout << "double: " << value;
	if (value == static_cast<long>(value)) {
		std::cout << ".0";
	}
	std::cout << "\n";
}

static bool isCharLiteral( const std::string &literal ) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        return true;
    } else {
        return false;
    }
}

static void handleCharLiteral( const std::string &literal ) {
    char	c = literal[1];

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

static bool	isIntLiteral( const std::string &literal ) {
	char	*endPtr;
	errno = 0;
	long	intVal = std::strtol(literal.c_str(), &endPtr, 10);
	if (errno == ERANGE || intVal > std::numeric_limits<int>::max() ||
		intVal < std::numeric_limits<int>::min()) {
		return false;
	}
	return (*endPtr == '\0');
}

static void	handleIntLiteral( const std::string &literal ) {
	char	*endPtr;
	long	intVal = std::strtol(literal.c_str(), &endPtr, 10);

	printCharConversion(static_cast<double>(intVal));
	printIntConversion(static_cast<double>(intVal));
	printFloatConversion(static_cast<double>(intVal));
	printDoubleConversion(static_cast<double>(intVal));
}

static bool	isFloatOrDouble( const std::string &literal ) {
	char	*endPtr;
	errno = 0;
	double	doubleVal = std::strtod(literal.c_str(), &endPtr);

	if (errno == ERANGE) {
		return false;
	}
	if (*endPtr == 'f' && *(endPtr + 1) == '\0') {
		if (doubleVal > std::numeric_limits<float>::max() ||
			doubleVal < -std::numeric_limits<float>::max()){
			return false;
		}
		return true;
	}
	else if (*endPtr == '\0') {
		return true;
	}
	return false;

}

static void	handleFloatOrDouble( const std::string &literal ) {
	char	*endPtr;
	double	doubleVal = std::strtod(literal.c_str(), &endPtr);

	printCharConversion(doubleVal);
    printIntConversion(doubleVal);
    printFloatConversion(doubleVal);
    printDoubleConversion(doubleVal);
}

static void	handleInvalidLiteral() {
	std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

void    ScalarConverter::convert( const std::string &literal )
{
    if (isSpecialValue(literal)) {
        handleSpecialValue(literal);
        return;
    }

    if (isCharLiteral(literal)) {
        handleCharLiteral(literal);
        return;
    }

	if (isIntLiteral(literal)) {
		handleIntLiteral(literal);
		return;
	}

	if (isFloatOrDouble(literal)) {
		handleFloatOrDouble(literal);
		return;
	}

	handleInvalidLiteral();
}

