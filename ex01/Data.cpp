#include "Data.hpp"

// Default Constructor
Data::Data() : value_(0) {}

// Copy Constructor
Data::Data( const Data &other ) : value_(other.value_) {}

// Copy Assignment Operator
Data    &Data::operator=( const Data &other ) {
    if (this != &other)
        this->value_ = other.value_;
    return *this;
}

// Destructor
Data::~Data() {}

// Getter
int Data::getValue() {
    return this->value_;
}

// Setter
void    Data::setValue( int value ) {
    this->value_ = value;
}