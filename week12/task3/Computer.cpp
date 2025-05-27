#include "Computer.h"
#include <cstring>
Computer::Computer(double cpuPower, const char *gpuModel, int power, int ram) : cpuPower(cpuPower), power(power), ram(ram), peripheralsCount(0)
{
    setGpuModel(gpuModel);
}

void Computer::setCpuPower(double cpuPower)
{
    this->cpuPower = cpuPower;
}

void Computer::setGpuModel(const char *gpuModel)
{
    if (!gpuModel)
    {
        throw;
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
}

Computer::Computer(const Computer &other) : cpuPower(other.cpuPower), power(other.power), ram(other.ram)
{
    copyDynamic(other);
}

Computer &Computer::operator=(const Computer &other)
{
    if (this != &other)
    {
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
}

Computer::~Computer()
{
    free();
}

void Computer::addPeripheral(const char *name)
{
    int size = strlen(name);
    if (peripheralsCount < 5 && name && size < 32)
    {
        strcpy(peripherals[peripheralsCount], name);
        peripheralsCount++;
    }
}
