#pragma once
#include "DigitalDevice.h"

class FileReader : virtual public DigitalDevice
{
public:
    FileReader(const MyString &model, const char *id);
    void readFromFile(const char *fileName) const;
};