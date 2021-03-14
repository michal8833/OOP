#include "Warehouse.h"

Warehouse::Warehouse() : totalVolume(0), totalOccupiedVolume(0) {}

void Warehouse::addLiquidContainer(double volume, size_t number ) {
    for(unsigned int i=0; i < number; i++)
        liquidContainers.push_back(LiquidContainer(volume));

    totalVolume += volume * number;
}

double Warehouse::deleteLiquidContainer(size_t number ) {
    double totalDeletedVolume = 0;

    for(unsigned int i=0; i < number; i++) {
        double temp = liquidContainers.back().getOccupiedVolume();
        if(fabs(temp) < EPS) {
            liquidContainers.pop_back();
            totalDeletedVolume += temp;
        }
        else {
            throw Deconstruction();
        }
    }

    totalVolume -= totalDeletedVolume;

    return totalDeletedVolume;
}

void Warehouse::pourIn(double howMuch) {
    if(totalVolume - totalOccupiedVolume > howMuch)
        totalOccupiedVolume += howMuch;
    else
        totalOccupiedVolume = totalVolume;

    for(int p=0; p < liquidContainers.size(); p++) {
        try {
            liquidContainers[p].pourIn(howMuch);
            return;
        }
        catch(Overflow& o) {
            if(p == liquidContainers.size() - 1) // the last container
                throw;

            howMuch= o.getOverflow();
        }
    }
}

double Warehouse::pourOut(double howMuch) {
    double totalPoured=0;

    if(fabs(totalOccupiedVolume) < EPS)
        return 0;

    for(int p= liquidContainers.size() - 1; p >= 0; p--) {
        if(fabs(liquidContainers[p].getOccupiedVolume()) < EPS)
            continue;

        double poured = liquidContainers[p].pourOut(howMuch);
        howMuch -= poured;
        totalPoured += poured;
    }

    totalOccupiedVolume -= totalPoured;
    return totalPoured;
}

bool Warehouse::occupiedAtLeast(double min) {
    return totalOccupiedVolume >= min;
}

bool Warehouse::occupiedAtMost(double max) {
    return totalVolume - totalOccupiedVolume >= max;
}

std::ostream& operator<<(std::ostream& os, const Warehouse& z) {
    unsigned counter = 0;

    for(const LiquidContainer &liquidContainer : z.liquidContainers) {
        os << "\tKontener nr " << ++counter << ":\n";
        os << "Objetosc: " << liquidContainer.getVolume() << " ";
        os << "Zajeta objetosc: " << liquidContainer.getOccupiedVolume() << "\n";
    }

    return os;
}
