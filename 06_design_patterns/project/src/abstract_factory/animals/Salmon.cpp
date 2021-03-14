#include <abstract_factory/animals/Salmon.h>
#include <iostream>

abstractFactory::animals::Salmon::Salmon(double weight) : weight(weight) {}

void abstractFactory::animals::Salmon::print() {
    std::cout << "abstractFactory::animals::Salmon{weight: " << weight << "}" << std::endl;
}
