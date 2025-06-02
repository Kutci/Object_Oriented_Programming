#include "Device.h"

class TechnoShop
{
    MyString name;
    Device **devices;
    unsigned count;
    unsigned cap;

    void resize();
    void free();
    void copyDynamic(const TechnoShop &);

public:
    TechnoShop();
    TechnoShop(const TechnoShop &);
    TechnoShop &operator=(const TechnoShop &);
    TechnoShop(const MyString &);
    ~TechnoShop();

    void addDevice(Device *);
    void addDevice(const Device *);
    void removeDevice(const MyString &, const MyString &brand);
    void saveToFile(const char *) const;
    void loadFromFile(const char *);
    void printAll() const;
};