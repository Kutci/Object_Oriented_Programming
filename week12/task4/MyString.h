#pragma once
#include <iostream>
#include <cstdint>

class MyString
{
public:
    MyString(const char *string = "");
    MyString(const MyString &other);
    MyString &operator=(const MyString &other);
    ~MyString();

    size_t getLength() const;
    const char *getCString() const;
    void swap(MyString &);
    friend std::ostream &operator<<(std::ostream &os, const MyString &string);
    friend std::istream &operator>>(std::istream &is, MyString &string);

private:
    size_t length;
    char *cString = nullptr;
};

bool operator==(const MyString &, const MyString &);