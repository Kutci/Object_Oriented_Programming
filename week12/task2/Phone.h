#include "Device.h"

enum SecurityLockType
{
    FaceRecognition,
    FingerPrint
};

class Phone : public Device
{
private:
    unsigned cameraCount;
    SecurityLockType lock;

public:
    Phone();
    Phone(const MyString &model, const MyString &brand, unsigned price, unsigned cameraCount, SecurityLockType lock);
    void print() const override;
    void writeToFile(std::ostream &os) const override;
    void readFromFile(std::istream &is) override;

    Device *clone() const override;
};
