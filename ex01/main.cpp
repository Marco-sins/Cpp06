#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *data = new (Data);
    Data *tests;
    uintptr_t test;

    data[0].n = 1;
    data[0].c = 'a';
    std::cout << data->n << std::endl;
    std::cout << data->c << std::endl;

    std::cout << "Data " << data << std::endl;
    test = Serializer::serialize(data);
    std::cout << "Serialized to uint " << test << std::endl;
    tests = Serializer::deserialize(test);
    std::cout << "Deserialized to data " << tests << std::endl;
    
    std::cout << tests->n << std::endl;
    std::cout << tests->c << std::endl;
    
    return 0;
}
