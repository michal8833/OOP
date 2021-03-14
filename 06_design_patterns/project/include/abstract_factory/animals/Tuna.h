#pragma once

#include "Animal.h"

namespace abstractFactory {
    namespace animals {

        class Tuna : public Animal {
        public:
            explicit Tuna(double weight);
            void print() override;

        private:
            double weight;
        };
    }
}