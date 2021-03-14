#pragma once

#include <set>
#include "Observer.h"
#include "Observable.h"

namespace observer {

    class Displacement : public Observable {
    public:
        void set(float value);

    private:
        float value;
    };
}
