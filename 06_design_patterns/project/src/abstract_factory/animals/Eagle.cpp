#include <abstract_factory/animals/Eagle.h>
#include <iostream>


abstractFactory::animals::Eagle::Eagle(double wingspan) : wingspan(wingspan) {}

void abstractFactory::animals::Eagle::print() {
    std::cout << "abstractFactory::animals::Eagle{wingspan: " << wingspan << "}" << std::endl;
}