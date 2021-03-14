#include <iostream>
#include <cmath>
#include <exception>

class Warehouse;

#define EPS 1e-14

class LiquidContainer
{
    friend std::ostream& operator<<(std::ostream& os, const LiquidContainer& p);

    double volume;
    double occupiedVolume;
    std::string liquidName;

public:
    explicit LiquidContainer(double volume);

    LiquidContainer& operator=(LiquidContainer&) = delete;
    void pourIn(double howMuch);
    double pourOut(double howMuch);
    bool occupiedAtLeast(double min);
    bool occupiedAtMost(double max);

    double getVolume() const { return volume; }
    double getOccupiedVolume() const { return occupiedVolume; }
    std::string getLiquidName() { return liquidName; }
    void setLiquidName(std::string liquidName);
};

class Overflow : std::exception
{
    double overflow;

public:
    explicit Overflow(double overflow) : overflow(overflow) {}

    double getOverflow() const {return overflow;}
};
