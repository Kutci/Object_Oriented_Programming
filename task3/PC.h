#pragma once
#include "Computer.h"
#include <iostream>
class PC : public Computer
{
public:
    PC(double cpuPower, const char *gpuModel, int power, int ram);

    void printType() const override;
    void listPeripherals() const override;
};