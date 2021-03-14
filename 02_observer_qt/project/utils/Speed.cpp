#include <stdexcept>
#include "Speed.h"

observer::Speed::Speed() {
    hasFirstValue = hasSecondValue = false;
}

float observer::Speed::get() {
    if(hasFirstValue && hasSecondValue)
        return secondValue - firstValue;

    throw std::runtime_error("firstValue and secondValue have to be set");
}

void observer::Speed::receive(float value) {
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

