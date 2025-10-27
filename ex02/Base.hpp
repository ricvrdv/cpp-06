#ifndef BASE_CPP
# define BASE_CPP

# include <ctime>
# include <cstdlib>
# include <iostream>
# include <exception>

class   Base {
    public:
        virtual ~Base();
};

Base    *generate( void );
void    identify( Base *p );
void    identify( Base &p );

#endif