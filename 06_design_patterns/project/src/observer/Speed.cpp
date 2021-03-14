#include <stdexcept>
#include "observer/Speed.h"

float observer::Speed::get() {
    if(hasFirstValue && hasSecondValue)
        return secondValue - firstValue;

    throw std::runtime_error("firstValue and secondValue have to be set");
}

void observer::Speed::notify(float value) {
    if(!hasFirstValue) {
        firstValue = value;
        hasFirstValue = true;
        return;
    }
    if(!hasSecondValue) {
        secondValue = value;
        hasSecondValue = true;
        return;
    }

    firstValue = secondValue;
    secondValue = value;
}

