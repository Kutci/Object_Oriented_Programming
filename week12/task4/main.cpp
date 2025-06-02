#include "MyString.h"
#include "SmartIODevice.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"
#include "FileReader.h"
#include "FileWriter.h"

int main()
{
    SmartIODevice dev(MyString("ModelX"), "DVC001");
    dev.turnOn();
    dev.status();

    dev.writeToConsole("Hello, world!");

    char input[100];
    dev.readFromConsole(input, 100);

    dev.writeToFile("output.txt", input);

    std::cout << "\n--- File Contents ---\n";
    dev.readFromFile("output.txt");

    return 0;
}
