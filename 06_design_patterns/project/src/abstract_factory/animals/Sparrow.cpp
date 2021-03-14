#include <abstract_factory/animals/Sparrow.h>
#include <iostream>

abstractFactory::animals::Sparrow::Sparrow(double wingspan) : wingspan(wingspan) {}

void abstractFactory::animals::Sparrow::print() {
    std::cout << "abstractFactory::animals::Sparrow{wingspan: " << wingspan << "}" << std::endl;
}
