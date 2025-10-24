#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class   Data {
    private:
        int value_;

    public:

        Data();
        Data( const Data &other );
        Data    &operator=( const Data &other );
        ~Data();

        int     getValue();
        void    setValue( int value );
};

#endif