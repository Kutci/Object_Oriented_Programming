#include "DigitalDevice.h"
#include <cstring>
DigitalDevice::DigitalDevice(const MyString &model, const char *id) : model(model), isOn(false)
{
    strcpy(this->id, id);
    this->id[6] = '\0';
}

void DigitalDevice::turnOff()
{
    isOn = false;
}

void DigitalDevice::turnOn()
{
    isOn = true;
}

DigitalDevice::~DigitalDevice() {}
void DigitalDevice::status() const
{
    std::cout << (isOn ? "Device is ON\n" : "Device is OFF\n");
    std::cout << "Model: " << model << "\n";
    std::cout << "\n";
    std::cout << "ID: " << id << "\n";
}