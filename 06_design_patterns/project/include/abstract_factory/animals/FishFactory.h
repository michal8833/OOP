#pragma once

#include <memory>
#include "AnimalFactory.h"

namespace abstractFactory {
    namespace animals {

        class FishFactory : public AnimalFactory {
        public:
            explicit FishFactory(double weight);
            std::shared_ptr<Animal> create(std::string species) override;

        private:
            double weight;
        };
    }
}
