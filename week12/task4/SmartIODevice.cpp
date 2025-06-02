#include "SmartIODevice.h"

SmartIODevice::SmartIODevice(const MyString &m, const char *i)
    : DigitalDevice(m, i),
      ConsoleWritter(m, i), ConsoleReader(m, i),
      FileWriter(m, i), FileReader(m, i) {}
