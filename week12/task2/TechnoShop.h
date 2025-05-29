#include "Device.h"

class TechnoShop
{
    MyString name;
    Device **devices = nullptr;
    unsigned count;
    unsigned cap;

    void resize();
    void free();
    void copyDynamic(const TechnoShop &other);

public:
    TechnoShop();
    TechnoShop(const TechnoShop &other);
    TechnoShop &operator=(const TechnoShop &other);
    TechnoShop(const MyString &);
    ~TechnoShop();

    void addDevice(Device *);
    void addDevice(const Device *);
    void removeDevice(const MyString &, const MyString &);
    void saveToFile(const char *) const;
    void loadFromFile(const char *);
    void printAll() const;
};