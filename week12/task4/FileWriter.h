#pragma once
#include "DigitalDevice.h"

class FileWriter : virtual public DigitalDevice
{
public:
    FileWriter(const MyString &model, const char *id);

    void writeToFile(const char *fileName, const char *data) const;
};