#pragma once

#include "Computer.h"

class Laptop : public Computer
{
public:
    Laptop(double cpuPower, const char *gpuModel, int power, int ram);
    void printType() const override;
    void listPeripherals() const override;
};