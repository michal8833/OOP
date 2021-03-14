#include "Displacement.h"

void observer::Displacement::set(float value) {
    this->value = value;
    emit send(value);
}
