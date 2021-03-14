#pragma once

#include "Animal.h"

namespace abstractFactory {
    namespace animals {

        class Sparrow : public Animal {
        public:
            explicit Sparrow(double wingspan);
            void print() override;

        private:
            double wingspan;
        };
    }
}