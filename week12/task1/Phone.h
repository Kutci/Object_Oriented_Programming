#pragma once

#include "Device.h"

enum SecurityLock : char
{
    FaceRecognition,
    FingerPrint
};

class Phone : public Device
{
private:
    unsigned cameraCount;
    SecurityLock lock;

public:
    Phone();
    Phone(const MyString &model, const MyString &brand, unsigned price, unsigned cameraCount, SecurityLock lock);
    void print() const override;
    void writeToFile(std::ostream &os) const override;
    void readFromFile(std::istream &is) override;

    Device *clone() const override;
};