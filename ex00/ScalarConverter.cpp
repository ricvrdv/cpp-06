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
void    ScalarConverter::convert( const std::string &literal )
{
    std::cout << literal << std::endl;
}

