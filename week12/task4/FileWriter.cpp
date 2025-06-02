#include "FileWriter.h"
#include <fstream>
FileWriter::FileWriter(const MyString &model, const char *id) : DigitalDevice(model, id) {}

void FileWriter::writeToFile(const char *fileName, const char *content) const
{
    if (!isOn)
    {
        std::cout << "Device is OFF. Cannot write to file.\n";
        return;
    }

    std::ofstream out(fileName); // Отваря се в текстов режим
    if (!out)
    {
        std::cout << "Failed to open file for writing.\n";
        return;
    }

    out << content;
    std::cout << "Data written to file.\n";
}