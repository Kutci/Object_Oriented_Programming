#include <iostream>
#include "PC.h"
#include "GamingConsole.h"
#include "factory.h"
int main()
{
    Computer **arr = new Computer *[3];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = factory();
    }
    arr[1]->printType();
    arr[1]->listPeripherals();

    arr[2]->printType();
    arr[2]->listPeripherals();
    return 0;
}
