#pragma once

#include "Animal.h"

namespace abstractFactory {
    namespace animals {

        class Raven : public Animal {
        public:
            explicit Raven(double wingspan);
            void print() override;

        private:
            double wingspan;
        };
    }
}