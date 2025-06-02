#pragma once
#include "DigitalDevice.h"
#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "FileReader.h"
#include "FileWriter.h"
class SmartIODevice : public ConsoleWritter, public ConsoleReader, public FileWriter, public FileReader
{
public:
    SmartIODevice(const MyString &model, const char *id);
};