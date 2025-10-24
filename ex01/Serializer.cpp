#include "Serializer.hpp"

// Default Constructor
Serializer::Serializer() {}

// Copy Constructor
Serializer::Serializer( const Serializer &other ) { (void)other; }

// Copy Assignment Operator
Serializer& Serializer::operator=( const Serializer &other ) {
    (void)other;
    return *this;
}

// Destructor
Serializer::~Serializer() {}

// static Member Functions
uintptr_t   Serializer::serialize( Data *ptr ) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *Serializer::deserialize( uintptr_t raw ) {
    return reinterpret_cast<Data*>(raw);
}
