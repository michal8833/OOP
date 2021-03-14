#include <abstract_factory/animals/Raven.h>
#include <iostream>

abstractFactory::animals::Raven::Raven(double wingspan) : wingspan(wingspan) {}

void abstractFactory::animals::Raven::print() {
    std::cout << "abstractFactory::animals::Raven{wingspan: " << wingspan << "}" << std::endl;
}