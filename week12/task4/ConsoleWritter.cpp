#include "ConsoleWriter.h"

ConsoleWritter::ConsoleWritter(const MyString &model, const char *id) : DigitalDevice(model, id) {}

void ConsoleWritter::writeToConsole(const char *message) const
{
    if (isOn)
        std::cout << "Console output: " << message << "\n";
    else
        std::cout << "Device is OFF. Cannot write.\n";
}