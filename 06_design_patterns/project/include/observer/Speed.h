#pragma once

#include <set>
#include "Observer.h"

namespace observer {

    class Speed : public Observer {
    public:
        float get();
        void notify(float value) override;

    private:
        float firstValue;
        float secondValue;

        bool hasFirstValue;
        bool hasSecondValue;
    };
}