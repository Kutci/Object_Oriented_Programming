#include "TechnoShop.h"
#include "Phone.h"
#include "Laptop.h"
#include <fstream>
#include <cstring>
TechnoShop::TechnoShop() : cap(5), count(0)
{
    devices = new Device *[cap];
}

TechnoShop::TechnoShop(const TechnoShop &other)
    : name(other.name), count(other.count), cap(other.cap)
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
    {
        devices[i] = other.devices[i]->clone();
    }
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
        delete devices[i];

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
    for (int i = 0; i < count; i++)
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
                devices[j] = devices[j + 1];

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
    {
        devices[i]->writeToFile(ofs);
    }
}

void TechnoShop::loadFromFile(const char *fileName)
{
    char buffer[256];
    std::ifstream is(fileName);

    MyString newName;
    unsigned n;
    is.getline(buffer, 256);
    newName = buffer;

    is >> n;
    is.ignore();

    TechnoShop tempShop;
    tempShop.name = newName;

    for (int i = 0; i < n; i++)
    {
        do
        {
            is.getline(buffer, 256);
        } while (strlen(buffer) == 0 && !is.eof());

        Device *d = nullptr;

        if (strcmp(buffer, "Phone") == 0)
            d = new Phone();
        if (strcmp(buffer, "Laptop") == 0)
            d = new Laptop();

        if (d)
        {
            d->readFromFile(is);
            tempShop.addDevice(d);
        }
    }

    std::swap(name, tempShop.name);
    std::swap(count, tempShop.count);
    std::swap(cap, tempShop.cap);
    std::swap(devices, tempShop.devices);
}