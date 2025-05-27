#pragma once

class Computer
{
protected:
    double cpuPower;
    char *gpuModel = nullptr;
    int power;
    int ram;
    char *peripherals[5];
    int peripheralsCount;

public:
    Computer(double cpuPower, const char *gpuModel, int power, int ram);
    Computer(const Computer &other);
    Computer &operator=(const Computer &);
    virtual ~Computer();

    void setCpuPower(double);
    void setGpuModel(const char *);
    void setPower(int);
    void setRam(int);

    void addPeripheral(const char *);

    void swap(Computer &other);

    virtual void printType() const = 0;
    virtual void listPeripherals() const = 0;

private:
    void free();
    void copyDynamic(const Computer &);
};