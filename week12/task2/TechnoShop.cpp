#include "TechnoShop.h"
#include "Phone.h"
#include "Laptop.h"
#include <fstream>
#include <cstring>
TechnoShop::TechnoShop()
{
    cap = 8;
    count = 0;
    devices = new Device *[cap];
}

TechnoShop::TechnoShop(const TechnoShop &other)
{
    copyDynamic(other);
}

TechnoShop::TechnoShop(const MyString &name) : name(name), count(0), cap(5)
{
    devices = new Device *[cap];
}

void TechnoShop::copyDynamic(const TechnoShop &other)
{
    devices = new Device *[other.cap];
    for (int i = 0; i < other.count; i++)
        devices[i] = other.devices[i]->clone();

    count = other.count;
    cap = other.cap;
}

TechnoShop &TechnoShop::operator=(const TechnoShop &other)
{
    if (this != &other)
    {
        free();
        copyDynamic(other);
        cap = other.cap;
        count = other.count;
    }

    return *this;
}

void TechnoShop::free()
{
    for (int i = 0; i < count; i++)
    {
        delete devices[i];
    }

    delete[] devices;
    devices = nullptr;
    count = 0;
}

TechnoShop::~TechnoShop()
{
    free();
}

void TechnoShop::resize()
{
    cap *= 2;
    Device **newArr = new Device *[cap];
    for (int i = 0; i < count; i++)
    {
        newArr[i] = devices[i];
    }

    delete[] devices;
    devices = newArr;
}

void TechnoShop::addDevice(Device *d)
{
    if (!d)
        return;
    if (count == cap)
        resize();

    devices[count++] = d;
}

void TechnoShop::addDevice(const Device *d)
{
    if (!d)
        return;
    if (count == cap)
        resize();

    devices[count++] = d->clone();
}
void TechnoShop::printAll() const
{
    for (int i = 0; i < count; ++i)
        devices[i]->print();
}

void TechnoShop::removeDevice(const MyString &model, const MyString &brand)
{
    for (int i = 0; i < count; i++)
    {
        if (devices[i]->getModel() == model && devices[i]->getBrand() == brand)
        {
            delete devices[i];
            for (int j = i; j < count - 1; j++)
            {
                devices[j] = devices[j + 1];
            }

            --count;
            return;
        }
    }
}

void TechnoShop::saveToFile(const char *fileName) const
{
    std::ofstream ofs(fileName);
    ofs << name << std::endl;
    ofs << count << std::endl;
    for (int i = 0; i < count; i++)
        devices[i]->writeToFile(ofs);
}

void TechnoShop::loadFromFile(const char *fileName)
{
    char buffer[256];
    std::ifstream ifs(fileName);
    if (!ifs)
    {
        std::cout << "Failed to open file: " << fileName << std::endl;
        return;
    }

    MyString newName;
    unsigned n;
    ifs.getline(buffer, 256);
    newName = buffer;

    ifs >> n;
    ifs.ignore();

    TechnoShop tempShop;
    tempShop.name = newName;

    for (unsigned i = 0; i < n; ++i)
    {
        do
        {
            ifs.getline(buffer, 256);
        } while (strlen(buffer) == 0 && !ifs.eof());

        if (ifs.eof())
            break;

        Device *d = nullptr;

        if (strcmp(buffer, "Phone") == 0)
            d = new Phone();
        else if (strcmp(buffer, "Laptop") == 0)
            d = new Laptop();

        if (d)
        {
            d->readFromFile(ifs);
            tempShop.addDevice(d);
        }
    }

    std::swap(name, tempShop.name);
    std::swap(count, tempShop.count);
    std::swap(cap, tempShop.cap);
    std::swap(devices, tempShop.devices);
}