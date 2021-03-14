#pragma once

#include "Animal.h"

namespace abstractFactory {
    namespace animals {

        class Salmon : public Animal {
        public:
            explicit Salmon(double weight);
            void print() override;

        private:
            double weight;
        };
    }
}