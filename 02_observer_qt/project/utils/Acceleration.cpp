#include <stdexcept>
#include "Acceleration.h"

observer::Acceleration::Acceleration() {
    hasFirstValue = hasSecondValue = hasThirdValue = false;
}

float observer::Acceleration::get() {
    if(hasFirstValue && hasSecondValue && hasThirdValue)
        return (thirdValue - secondValue) - (secondValue - firstValue);

    throw std::runtime_error("firstValue, secondValue and thirdValue have to be set");
}

void observer::Acceleration::receive(float value) {
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
    if(!hasThirdValue) {
        thirdValue = value;
        hasThirdValue = true;
        return;
    }

    firstValue = secondValue;
    secondValue = thirdValue;
    thirdValue = value;
}
