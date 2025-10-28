#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <cmath>
# include <cctype>
# include <cstdlib>
# include <cerrno>

class   ScalarConverter
{
    private:

        ScalarConverter();
        ScalarConverter( ScalarConverter const &other );
        ScalarConverter &operator=( ScalarConverter const &other );
        ~ScalarConverter();

    public:

        static void convert( const std::string &literal );
};

#endif