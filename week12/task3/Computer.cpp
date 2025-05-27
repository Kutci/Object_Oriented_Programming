#include "Computer.h"
#include <cstring>
#include <stdexcept>
Computer::Computer(double cpuPower, const char *gpuModel, int power, int ram) : cpuPower(cpuPower), power(power), ram(ram), peripheralsCount(0)
{
    setGpuModel(gpuModel);
    for (int i = 0; i < 5; ++i)
        peripherals[i] = nullptr;
}

void Computer::setCpuPower(double cpuPower)
{
    this->cpuPower = cpuPower;
}

void Computer::setGpuModel(const char *gpuModel)
{
    if (!gpuModel)
    {
        throw std::invalid_argument("gpuModel is null");
    }
    char *newGpuModel = new char[strlen(gpuModel) + 1];
    strcpy(newGpuModel, gpuModel);

    delete[] this->gpuModel;
    this->gpuModel = newGpuModel;
}

void Computer::setPower(int power)
{
    this->power = power;
}

void Computer::setRam(int ram)
{
    this->ram = ram;
}

void Computer::copyDynamic(const Computer &other)
{
    setGpuModel(other.gpuModel);
    peripheralsCount = other.peripheralsCount;
    for (int i = 0; i < peripheralsCount; ++i)
    {
        peripherals[i] = new char[strlen(other.peripherals[i]) + 1];
        strcpy(peripherals[i], other.peripherals[i]);
    }
    for (int i = peripheralsCount; i < 5; ++i)
        peripherals[i] = nullptr;
}

Computer::Computer(const Computer &other) : cpuPower(other.cpuPower), power(other.power), ram(other.ram)
{
    copyDynamic(other);
}

Computer &Computer::operator=(const Computer &other)
{
    if (this != &other)
    {
        free();
        copyDynamic(other);
        cpuPower = other.cpuPower;
        power = other.power;
        ram = other.ram;
    }

    return *this;
}

void Computer::free()
{
    delete[] gpuModel;
    gpuModel = nullptr;

    for (int i = 0; i < peripheralsCount; ++i)
    {
        delete[] peripherals[i];
        peripherals[i] = nullptr;
    }
    peripheralsCount = 0;
}

Computer::~Computer()
{
    free();
}

void Computer::addPeripheral(const char *name)
{
    if (peripheralsCount < 5 && name)
    {
        peripherals[peripheralsCount] = new char[strlen(name) + 1];
        strcpy(peripherals[peripheralsCount], name);
        peripheralsCount++;
    }
}
