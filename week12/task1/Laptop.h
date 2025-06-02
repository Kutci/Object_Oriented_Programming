#pragma once
#include "Device.h"

enum OS : char
{
    MacOs,
    Linux,
    Windows
};

enum Port : char
{
    USB,
    ThunderBolt
};

class Laptop : public Device
{
private:
    OS os;
    Port port;
    unsigned portCount;

public:
    Laptop();
    Laptop(const MyString &model, const MyString &brand, unsigned price, OS os, Port port, unsigned portCount);

    void print() const override;
    void writeToFile(std::ostream &os) const override;
    void readFromFile(std::istream &is) override;
    Device *clone() const override;
};