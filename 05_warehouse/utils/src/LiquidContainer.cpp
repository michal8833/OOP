#include "LiquidContainer.h"

LiquidContainer::LiquidContainer(double volume) : volume(volume), occupiedVolume(0), liquidName("none") {}

void LiquidContainer::pourIn(double howMuch) {
    if(occupiedVolume + howMuch > volume) {
        double overflow = occupiedVolume + howMuch - volume;
        occupiedVolume=volume;
        throw Overflow(overflow);
    }
    else
        occupiedVolume+=howMuch;
}

double LiquidContainer::pourOut(double howMuch) {
    if(howMuch > occupiedVolume) {
        double temp = occupiedVolume;
        occupiedVolume = 0;
        return temp;
    }
    else {
        occupiedVolume -= howMuch;
        return howMuch;
    }
}

void LiquidContainer::setLiquidName(std::string liquidName) {
    if(fabs(occupiedVolume) < EPS) {
        this->liquidName = liquidName;
    }
    else {
        throw "Zmiana nazwy plynu niedozwolona.";
    }
}

bool LiquidContainer::occupiedAtLeast(double min) {
    return occupiedVolume >= min;
}

bool LiquidContainer::occupiedAtMost(double max) {
    return max <= (volume - occupiedVolume);

}

std::ostream& operator<<(std::ostream& os, const LiquidContainer& p) {
    os << "Objetosc: " << p.volume << std::endl;
    os << "Zajeta objetosc: " << p.occupiedVolume << std::endl;
    os << "Nazwa plynu: " << p.liquidName << std::endl;

    return os;
}
