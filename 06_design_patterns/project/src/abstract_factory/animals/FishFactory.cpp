#include <abstract_factory/animals/FishFactory.h>

#include <abstract_factory/animals/Cod.h>
#include <abstract_factory/animals/Salmon.h>
#include <abstract_factory/animals/Tuna.h>

abstractFactory::animals::FishFactory::FishFactory(double weight) : weight(weight) {}

std::shared_ptr<abstractFactory::animals::Animal> abstractFactory::animals::FishFactory::create(std::string species) {
    if(species == "cod")
        return std::make_shared<Cod>(weight);
    if(species == "salmon")
        return std::make_shared<Salmon>(weight);
    if(species == "tuna")
        return std::make_shared<Tuna>(weight);

    throw std::runtime_error("Unsupported fish species: " + species);
}
