#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# define GBOLD "\033[1;32m"
# define GREG "\033[0;32m"
# define RESET "\033[0m"

# include <stdint.h>
# include <iostream>
# include <string>

class Data;

class   Serializer {
    private:

        Serializer();
        Serializer( const Serializer &other );
        Serializer  &operator=( const Serializer &other );
        ~Serializer();

    public:

        static uintptr_t   serialize( Data *ptr );
        static Data    *deserialize( uintptr_t raw );

};

#endif