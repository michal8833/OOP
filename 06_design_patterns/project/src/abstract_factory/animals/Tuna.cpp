#include <abstract_factory/animals/Tuna.h>
#include <iostream>

abstractFactory::animals::Tuna::Tuna(double weight) : weight(weight) {}

void abstractFactory::animals::Tuna::print() {
    std::cout << "abstractFactory::animals::Tuna{weight: " << weight << "}" << std::endl;
}
