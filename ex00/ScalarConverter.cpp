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
static bool isCharLiteral(const std::string& str) {
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;
    if (str.length() == 4 && str[0] == '\'' && str[3] == '\'' && str[1] == '\\')
        return true;
    return false;
}

static bool isFloatPseudoLiteral(const std::string& str) {
    return str == "nanf" || str == "+inff" || str == "-inff";
}

static bool isDoublePseudoLiteral(const std::string& str) {
    return str == "nan" || str == "+inf" || str == "-inf";
}

static void handleChar(const std::string &str) {
	char	c;

    if (str.length() == 3) {
        c = str[1];
    }
	else if (str.length() == 4) {
        switch (str[2]) {
            case 't':
				c = '\t';
				break;
            case 'n':
				c = '\n';
				break;
            case '\\':
				c = '\\';
				break;
            case '\'':
				c = '\'';
				break;
            case 'r':
				c = '\r';
				break;
            case 'f':
				c = '\f';
				break;
            case 'v':
				c = '\v';
				break;
            default:
                std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
                return;
        }
    }
	else {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

static void handleFloatPseudo(const std::string &str) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << str << '\n';
    std::cout << "double: " << str.substr(0, str.length()-1) << '\n';
}

static void handleDoublePseudo(const std::string &str) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << str << "f\n";
    std::cout << "double: " << str << '\n';
}

static void handleFloat(const std::string &str) {
	
	try {
        float f = std::strtof(str.c_str(), NULL);
        if (std::isnan(f) || std::isinf(f) || f < 0 || f > std::numeric_limits<char>::max())
            std::cout << "char: impossible\n";
        else if (!std::isprint(static_cast<int>(f)))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(f) << "'\n";
        if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(f) << '\n';
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << '\n';
    } catch (...) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}

static void handleDouble(const std::string &str) {
	
	try {
        double d = std::strtod(str.c_str(), NULL);
        if (std::isnan(d) || std::isinf(d) || d < 0 || d > std::numeric_limits<char>::max())
            std::cout << "char: impossible\n";
        else if (!std::isprint(static_cast<int>(d)))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(d) << '\n';
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << '\n';
    } catch (...) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}

static void handleInt(const std::string &str) {
	errno = 0;
    char	*endptr;
    long	val = std::strtol(str.c_str(), &endptr, 10);

    if (errno == ERANGE || *endptr != '\0' || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    int	i = static_cast<int>(val);

    if (i < 0 || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible\n";
    else if (!std::isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(i) << "'\n";

    std::cout << "int: " << i << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f\n";
    std::cout << "double: " << static_cast<double>(i) << '\n';
}

void ScalarConverter::convert(const std::string &literal) {
    if (isCharLiteral(literal))
        handleChar(literal);
    else if (isFloatPseudoLiteral(literal))
        handleFloatPseudo(literal);
    else if (isDoublePseudoLiteral(literal))
        handleDoublePseudo(literal);
    else if (literal.find('f') != std::string::npos)
        handleFloat(literal);
    else if (literal.find('.') != std::string::npos)
        handleDouble(literal);
    else
        handleInt(literal);
}
