#pragma once

#include "Computer.h"

class GamingConsole : public Computer
{
public:
    GamingConsole(double cpuPower, const char *gpuModel, int power, int ram);

    void printType() const override;
    void listPeripherals() const override;
};