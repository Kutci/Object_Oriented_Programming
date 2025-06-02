#include "Phone.h"
#include <iostream>
#include <stdexcept>
Phone::Phone() : Device(), cameraCount(0), lock(SecurityLock::FaceRecognition) {}

Phone::Phone(const MyString &model, const MyString &brand, unsigned price, unsigned cameraCount, SecurityLock lock)
    : Device(model, brand, price), cameraCount(cameraCount), lock(lock) {}

void Phone::print() const
{
    std::cout << "Phone - Model: " << model << ", Brand: " << brand
              << ", Price: " << price << ", Cameras: " << cameraCount
              << ", Lock Type: " << (lock == FaceRecognition ? "FaceRecognition" : "FingerPrint") << std::endl;
}

void Phone::writeToFile(std::ostream &os) const
{
    if (!os)
    {
        throw std::logic_error("Stream cannot be opne");
    }

    os << "Phone" << std::endl;
    os << model << ' ' << brand << ' ' << price << ' ' << cameraCount << ' ' << static_cast<unsigned>(lock) << '\n';
}

void Phone::readFromFile(std::istream &is)
{
    MyString newModel, newBrand;
    unsigned newPrice, newCameraCount;
    unsigned lockValue;
    is >> newModel >> newBrand >> newPrice >> newCameraCount >> lockValue;

    if (!is)
        throw std::logic_error("Invalid phone data");

    model = newModel;
    brand = newBrand;
    price = newPrice;
    cameraCount = newCameraCount;
    lock = static_cast<SecurityLock>(lockValue);
}

Device *Phone::clone() const
{
    return new Phone(*this);
}