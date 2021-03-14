#include <abstract_factory/animals/Cod.h>
#include <iostream>

abstractFactory::animals::Cod::Cod(double weight) : weight(weight) {}

void abstractFactory::animals::Cod::print() {
    std::cout << "abstractFactory::animals::Cod{weight: " << weight << "}" << std::endl;
}
