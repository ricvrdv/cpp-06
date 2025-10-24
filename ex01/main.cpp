#include "Serializer.hpp"
#include "Data.hpp"

int main(){
    
    std::cout << "\n" << GBOLD << "TEST 1" << std::string(40, '=') << RESET << "\n";
    Data    data1;
    data1.setValue(42);

    std::cout << "Original address:\t" << &data1 << "\n";

    uintptr_t   raw1 = Serializer::serialize(&data1);
    std::cout << "Serialized value:\t" << raw1 << "\n";

    Data    *ptr1 = Serializer::deserialize(raw1);
    std::cout << "Deserialized value:\t" << ptr1 << "\n";

    if (ptr1 == &data1) {
        std::cout << GREG << "Deserialized pointer matches original" << RESET << "\n";
    }
    else {
        std::cout << "Deserialization failed.\n";
    }

    std::cout << "\n* Original content: " << data1.getValue() << "\n";
    std::cout << "* Content via deserialized pointer: " << ptr1->getValue() << "\n";
    std::cout << "** Changing content via deserialized pointer **" << std::endl;
    ptr1->setValue(95);
    std::cout << "Content via initial object: " << data1.getValue() << "\n";
    std::cout << "Content via deserialized pointer: " << ptr1->getValue() << "\n";

    std::cout << "\n" << GBOLD << "TEST 2" << std::string(40, '=') << RESET << "\n";
    Data    *data2 = new Data();
    data2->setValue(21);

    std::cout << "Original address:\t" << data2 << "\n";
    
    uintptr_t   raw2 = Serializer::serialize(data2);
    std::cout << "Serialized value:\t" << raw2 << "\n";

    Data    *ptr2 = Serializer::deserialize(raw2);
    std::cout << "Deserialized value:\t" << ptr2 << "\n";

    if (ptr2 == data2) {
        std::cout << GREG << "Deserialized pointer matches original" << RESET << "\n";
    }
    else {
        std::cout << "Deserialization failed.\n";
    }

    std::cout << "\n* Original content: " << data2->getValue() << "\n";
    std::cout << "* Content via deserialized pointer: " << ptr2->getValue() << "\n";
    std::cout << "** Changing content via deserialized pointer **" << std::endl;
    ptr2->setValue(2025);
    std::cout << "Content via initial object: " << data2->getValue() << "\n";
    std::cout << "Content via deserialized pointer: " << ptr2->getValue() << "\n";

    return 0;
}