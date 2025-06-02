#include "ConsoleReader.h"

ConsoleReader::ConsoleReader(const MyString &model, const char *id) : DigitalDevice(model, id) {}

void ConsoleReader::readFromConsole(char *buffer, size_t bufferSize) const
{
    if (isOn)
    {
        std::cout << "Enter input: ";
        std::cin.getline(buffer, bufferSize);
        std::cout << "You entered: " << buffer << '\n';
    }
    else
    {
        std::cout << "Device is OFF. Cannot read. \n";
    }
}