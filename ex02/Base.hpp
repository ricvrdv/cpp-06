#ifndef BASE_CPP
# define BASE_CPP

class   Base {
    public:

        virtual ~Base();
};

Base    *generate( void );
void    identify( Base *p );
void    identify( Base &p );

#endif