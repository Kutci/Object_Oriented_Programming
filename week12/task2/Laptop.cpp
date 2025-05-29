#include "Laptop.h"

Laptop::Laptop() : Device(), os(OS::Windows), port(Port::USB), portCount(0) {}

Laptop::Laptop(const MyString &model, const MyString &brand, unsigned price, OS os, Port port, unsigned portCount)
    : Device(model, brand, price), os(os), port(port), portCount(portCount) {}

void Laptop::print() const
{
    std::cout << "Laptop - Model: " << model << ", Brand: " << brand
              << ", Price: " << price << ", OS: "
              << (os == MacOs ? "MacOS" : os == Linux ? "Linux"
                                                      : "Windows")
              << ", Port Type: " << (port == USB ? "USB" : "Thunderbolt")
              << ", Ports: " << portCount << std::endl;
}

void Laptop::writeToFile(std::ostream &out) const
{
    if (!out)
        throw std::logic_error("Stream cannot be open");
    out << "Laptop" << std::endl;
    out << model << ' ' << brand << ' ' << price << ' ' << os << ' ' << port << ' ' << portCount << std::endl;
}

void Laptop::readFromFile(std::istream &is)
{
    if (!is)
        throw std::logic_error("stream cannot open");

    MyString newModel, newBrand;
    unsigned newPrice;
    unsigned newPortCount;
    OS newOs;
    Port newPort;

    int osValue;
    int portValue;
    is >> newModel >> newBrand >> newPrice >> osValue >> portValue >> newPortCount;
    newOs = static_cast<OS>(osValue);
    newPort = static_cast<Port>(portValue);

    model = newModel;
    brand = newBrand;
    price = newPrice;
    portCount = newPortCount;
    os = newOs;
    port = newPort;
}

Device *Laptop::clone() const
{
    return new Laptop(*this);
}
