#include "TechnoShop.h"
#include "Phone.h"
#include "Laptop.h"
#include <iostream>

int main()
{
    TechnoShop shop("Tech Paradise");

    Device *d1 = new Phone("Galaxy", "Samsung", 1800, 4, SecurityLock::FaceRecognition);
    Device *d2 = new Laptop("MacBook", "Apple", 2500, OS::MacOs, Port::USB, 2);

    shop.addDevice(d1);
    shop.addDevice(d2);

    std::cout << "--- Original Devices ---" << std::endl;
    shop.printAll();

    shop.saveToFile("shop_data.txt");

    TechnoShop loadedShop;
    loadedShop.loadFromFile("shop_data.txt");

    std::cout << "--- Loaded from File ---" << std::endl;
    loadedShop.printAll();

    loadedShop.removeDevice("Galaxy", "Samsung");

    std::cout << "--- After Removal ---" << std::endl;
    loadedShop.printAll();

    TechnoShop newShop = shop;
    std::cout << "--- Operator =---" << std::endl;

    newShop.printAll();

    TechnoShop startUp(shop);
    std::cout << "--- Copy constructor ---" << std::endl;

    startUp.printAll();

    return 0;
}
