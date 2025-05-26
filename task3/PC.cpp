#include "PC.h"
#include <iostream>
PC::PC(double cpuPower, const char *gpuModel, int power, int ram) : Computer(cpuPower, gpuModel, power, ram)
{
    addPeripheral("Mouse");
    addPeripheral("Keyboard");
    addPeripheral("Microphone");
    addPeripheral("Headphones");
}

void PC::printType() const
{
    std::cout << "Type: PC" << std::endl;
}

void PC::listPeripherals() const
{
    std::cout << "Peripherals:" << std::endl;
    for (int i = 0; i < peripheralsCount; ++i)
        std::cout << "- " << peripherals[i] << std::endl;
}