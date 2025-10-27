#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Destructor
Base::~Base() {}

// External Functions
// Returns the instance as a Base pointer
Base    *generate() {
    
    int r = std::rand() % 3;

    if (r == 0) {
        return (new A);
    }
    else if (r == 1) {
        return (new B);
    }
    else {
        return (new C);
    }
}

// Identify type from pointer
void    identify( Base *p ) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    }
    else {
        std::cout << "Unknown\n";
    }
}

// Identify type from reference
void    identify( Base &p ) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return ;
    }
    catch (std::exception &) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    }
    catch (std::exception &) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    }
    catch (std::exception &) {}

    std::cout << "Unknown\n";
}