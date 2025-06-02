#pragma once

#include "DigitalDevice.h"

class ConsoleWritter : virtual public DigitalDevice
{
public:
    ConsoleWritter(const MyString &model, const char *id);

    void writeToConsole(const char *message) const;
};