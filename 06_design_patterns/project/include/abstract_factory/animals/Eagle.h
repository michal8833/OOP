#pragma once

#include "Animal.h"

namespace abstractFactory {
    namespace animals {

        class Eagle : public Animal {
        public:
            explicit Eagle(double wingspan);
            void print() override;

        private:
            double wingspan;
        };
    }
}