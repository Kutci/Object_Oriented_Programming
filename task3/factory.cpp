#include "PC.h"
#include "Laptop.h"
#include "GamingConsole.h"
#include "Computer.h"
#include <random>

class Laptop;
class PC;
class GamingConsole;

Computer *factory()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 2);

    int choice = dist(gen);
    switch (choice)
    {
    case 0:
        return new PC(3.5, "RTX 3070", 650, 16);
    case 1:
        return new Laptop(2.5, "Intel Iris", 500, 8);
    case 2:
        return new GamingConsole(3.2, "AMD RX", 600, 12);
    default:
        return nullptr;
    }
}
