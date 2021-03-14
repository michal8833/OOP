#pragma once

#include <memory>
#include "AnimalFactory.h"

namespace abstractFactory {
    namespace animals {

        class BirdFactory : public AnimalFactory {
        public:
            explicit BirdFactory(double wingspan);
            std::shared_ptr<Animal> create(std::string species) override;

        private:
            double wingspan;
        };
    }
}
