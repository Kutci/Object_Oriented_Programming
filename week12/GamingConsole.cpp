#include "GamingConsole.h"
#include <iostream>
GamingConsole::GamingConsole(double cpuPower, const char *gpuModel, int power, int ram) : Computer(cpuPower, gpuModel, power, ram)
{
    addPeripheral("Headphones");
    addPeripheral("Camera");
    addPeripheral("Microphone");
}

void GamingConsole::printType() const
{
    std::cout << "Type: GamingConsole" << std::endl;
}

void GamingConsole::listPeripherals() const
{
    std::cout << "Peripherals:" << std::endl;
    for (int i = 0; i < peripheralsCount; ++i)
        std::cout << "- " << peripherals[i] << std::endl;
}