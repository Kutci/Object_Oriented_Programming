#include "Laptop.h"
#include <iostream>
Laptop::Laptop(double cpuPower, const char *gpuModel, int power, int ram) : Computer(cpuPower, gpuModel, power, ram)
{
    addPeripheral("Mouse");
    addPeripheral("Microphone");
}

void Laptop::printType() const
{
    std::cout << "Type: Laptop" << std::endl;
}

void Laptop::listPeripherals() const
{
    std::cout << "Peripherals:" << std::endl;
    for (int i = 0; i < peripheralsCount; ++i)
        std::cout << "- " << peripherals[i] << std::endl;
}