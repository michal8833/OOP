#pragma once

#include <memory>
#include "Animal.h"

namespace abstractFactory {
    namespace animals {

        class AnimalFactory {
        public:
            virtual ~AnimalFactory() = default;
            virtual std::shared_ptr<Animal> create(std::string species) = 0;
        };
    }
}
