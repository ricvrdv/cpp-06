#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    std::srand(std::time(NULL));
    for (int i = 0; i < 5; i++) {
        Base*   instance = generate();
        std::cout << "Pointer version: ";
        identify(instance);

        std::cout << "Reference version: ";
        identify(*instance);

        delete  instance;
        std::cout << "----------------\n";
    }

    std::cout << "\nForced failed cast test:\n";
    Base baseInstance; // This is a pure Base, not A/B/C
    identify(baseInstance); 
    return 0;
}