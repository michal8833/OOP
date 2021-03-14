#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include "LiquidContainer.h"

class Warehouse;

class Warehouse
{
    friend std::ostream& operator<<(std::ostream& os, const Warehouse& z);

    std::vector<LiquidContainer> liquidContainers;
    double totalVolume;
    double totalOccupiedVolume;

public:
    Warehouse();

    Warehouse& operator=(Warehouse&) = delete;
    void addLiquidContainer(double volume, size_t number = 1);
    double deleteLiquidContainer(size_t number = 1);
    void pourIn(double howMuch);
    double pourOut(double howMuch);
    bool occupiedAtLeast(double min);
    bool occupiedAtMost(double max);

    std::string getLiquidName() { return liquidContainers.front().getLiquidName(); }
    void setLiquidName(std::string liquidName) { liquidContainers.front().setLiquidName(liquidName); }
    size_t getNumberOfLiquidContainers() const { return liquidContainers.size(); }
    double getTotalVolume() const { return totalVolume; }
    double getTotalOccupiedVolume() const { return totalOccupiedVolume; }
};

class Deconstruction : std::exception
{
public:
    Deconstruction() = default;
};

