#include "Phone.h"
#include <stdexcept>

Phone::Phone() : Device(), cameraCount(0), lock(SecurityLockType::FaceRecognition) {}

Phone::Phone(const MyString &model, const MyString &brand, unsigned price, unsigned cameraCount, SecurityLockType lock)
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
        throw std::logic_error("Stream cannot be open");
    os << "Phone" << std::endl;
    os << model << ' ' << brand << ' ' << price << ' ' << cameraCount << ' ' << lock << std::endl;
}

void Phone::readFromFile(std::istream &is)
{
    MyString newModel, newBrand;
    unsigned newPrice, newCameraCount;
    int lockValue;
    is >> newModel >> newBrand >> newPrice >> newCameraCount >> lockValue;

    if (!is)
        throw std::logic_error("Invalid phone data format");

    model = newModel;
    brand = newBrand;
    price = newPrice;
    cameraCount = newCameraCount;
    lock = static_cast<SecurityLockType>(lockValue);
}

Device *Phone::clone() const
{
    return new Phone(*this);
}