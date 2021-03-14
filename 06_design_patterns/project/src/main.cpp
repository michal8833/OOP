#include <iostream>

#include "abstract_factory/animals/BirdFactory.h"
#include "abstract_factory/animals/FishFactory.h"

#include "observer/Acceleration.h"
#include "observer/Displacement.h"
#include "observer/Speed.h"

int main()
{
    std::cout << "\tAn example of using an abstract factory pattern:" << std::endl;

    auto birdFactory = std::make_shared<abstractFactory::animals::BirdFactory>(1.8);
    birdFactory->create("raven")->print();
    birdFactory->create("eagle")->print();
    birdFactory->create("sparrow")->print();

    auto fishFactory = std::make_shared<abstractFactory::animals::FishFactory>(2.1);
    fishFactory->create("cod")->print();
    fishFactory->create("salmon")->print();
    fishFactory->create("tuna")->print();

    std::cout << std::endl;
    std::cout << "\tAn example of using an observer pattern:" << std::endl;

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    displacement.set(5);
    displacement.set(8);
    displacement.set(15);

    std::cout << "Speed: " << speed.get() << std::endl;
    std::cout << "Acceleration: " << acceleration.get() << std::endl;

    return 0;
}