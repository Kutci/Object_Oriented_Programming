#include "Laptop.h"
#include <iostream>
#include <stdexcept>

Laptop::Laptop() : Device(), os(OS::Windows), port(Port::ThunderBolt), portCount(0) {}

Laptop::Laptop(const MyString &model, const MyString &brand, unsigned price, OS os, Port port, unsigned portCount)
    : Device(model, brand, price), os(os), port(port), portCount(portCount) {}

void Laptop::print() const
{
    std::cout << "Laptop - Model: " << model << ", Brand: " << brand
              << ", Price: " << price << ", OS: "
              << (os == MacOs ? "MacOs" : os == Linux ? "Linux"
                                                      : "Windows")
              << ", Port Type: " << (port == USB ? "USB" : "Thunderbolt")
              << ", Ports: " << portCount << std::endl;
}

void Laptop::writeToFile(std::ostream &out) const
{
    if (!out)
        throw std::logic_error("Stream cannot be open");
    out << "Laptop" << std::endl;
    out << model << ' ' << brand << ' ' << price << ' ' << static_cast<unsigned>(os) << ' ' << static_cast<unsigned>(port) << ' ' << portCount;
}

void Laptop::readFromFile(std::istream &is)
{
    if (!is)
        throw std::logic_error("Stream cannot open");

    MyString newModel, newBrand;
    unsigned newPrice, newPortCount;
    OS newOS;
    Port newPort;

    unsigned osValue;
    unsigned portValue;
    is >> newModel >> newBrand >> newPrice >> osValue >> portValue >> newPortCount;

    newOS = static_cast<OS>(osValue);
    newPort = static_cast<Port>(portValue);

    model = newModel;
    brand = newBrand;
    price = newPrice;
    portCount = newPortCount;
    os = newOS;
    port = newPort;
}

Device *Laptop::clone() const
{
    return new Laptop(*this);
}