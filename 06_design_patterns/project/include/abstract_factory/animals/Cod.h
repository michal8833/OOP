#pragma once

#include "Animal.h"

namespace abstractFactory {
    namespace animals {

        class Cod : public Animal {
        public:
            explicit Cod(double weight);
            void print() override;

        private:
            double weight;
        };
    }
}