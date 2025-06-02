#include "Device.h"

Device::Device() : model(), brand(), price(0) {}

Device::Device(const MyString &model, const MyString &brand, unsigned price) : model(model), brand(brand), price(price) {}

Device::~Device()
{
}

const MyString &Device::getBrand() const
{
    return brand;
}

const MyString &Device::getModel() const
{
    return model;
}