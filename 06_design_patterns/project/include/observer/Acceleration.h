#pragma once

#include <set>
#include "Observer.h"

namespace observer {

    class Acceleration : public Observer {
    public:
        float get();
        void notify(float value) override;

    private:
        float firstValue;
        float secondValue;
        float thirdValue;

        bool hasFirstValue;
        bool hasSecondValue;
        bool hasThirdValue;
    };
}