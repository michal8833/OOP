#pragma once

namespace abstractFactory {
    namespace animals {

        class Animal {
        public:
            virtual ~Animal() = default;
            virtual void print() = 0;
        };
    }
}
