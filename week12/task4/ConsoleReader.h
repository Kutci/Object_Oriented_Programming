#pragma once

#include "DigitalDevice.h"

class ConsoleReader : virtual public DigitalDevice
{
public:
    ConsoleReader(const MyString &model, const char *id);
    void readFromConsole(char *buffer, size_t bufferSize) const;
};