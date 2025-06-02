#pragma once
#include "MyString.h"

class Device
{
protected:
    MyString model;
    MyString brand;
    unsigned price;

public:
    Device();
    Device(const MyString &model, const MyString &brand, unsigned price);

    virtual ~Device();
    virtual void print() const = 0;
    virtual void writeToFile(std::ostream &os) const = 0;
    virtual void readFromFile(std::istream &is) = 0;
    virtual Device *clone() const = 0;

    const MyString &getModel() const;
    const MyString &getBrand() const;
};