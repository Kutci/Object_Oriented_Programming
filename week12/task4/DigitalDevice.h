#pragma once
#include "MyString.h"
class DigitalDevice
{
protected:
    MyString model;
    char id[7];
    bool isOn;

public:
    DigitalDevice(const MyString &model, const char *id);

    void turnOn();
    void turnOff();

    virtual void status() const;

    virtual ~DigitalDevice();
};