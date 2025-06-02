#include "FileReader.h"
#include <fstream>
FileReader::FileReader(const MyString &model, const char *id) : DigitalDevice(model, id) {}

void FileReader::readFromFile(const char *fileName) const
{
    if (!isOn)
    {
        std::cout << "Device is OFF. Cannot read file.\n";
        return;
    }

    std::ifstream is(fileName); // отваряне на файл за четене
    if (!is)
    {
        std::cout << "Cannot open file for reading.\n";
        return;
    }

    char buffer[256];
    while (is.getline(buffer, sizeof(buffer)))
    {
        std::cout << buffer << '\n';
    }

    is.close(); // не е задължително, но е добра практика
}