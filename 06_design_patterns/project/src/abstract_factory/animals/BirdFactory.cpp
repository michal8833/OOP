#include <abstract_factory/animals/BirdFactory.h>

#include <abstract_factory/animals/Sparrow.h>
#include <abstract_factory/animals/Eagle.h>
#include <abstract_factory/animals/Raven.h>

abstractFactory::animals::BirdFactory::BirdFactory(double wingspan) : wingspan(wingspan) {}

std::shared_ptr<abstractFactory::animals::Animal> abstractFactory::animals::BirdFactory::create(std::string species) {
    if(species == "sparrow")
        return std::make_shared<Sparrow>(wingspan);
    if(species == "eagle")
        return std::make_shared<Eagle>(wingspan);
    if(species == "raven")
        return std::make_shared<Raven>(wingspan);

    throw std::runtime_error("Unsupported bird species: " + species);
}
