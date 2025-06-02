#pragma once
#include <iostream>
#include <cstdint>

class MyString
{
public:
    MyString(const char *string = "");
    MyString(const MyString &other);
    ~MyString();

    MyString &operator=(const MyString &other);

    size_t getLength() const;
    const char *getCString() const;
    void swap(MyString &other);
    friend std::istream &operator>>(std::istream &is, MyString &str);
    friend std::ostream &operator<<(std::ostream &os, const MyString &string);

private:
    size_t length;
    char *cString = nullptr;
};

bool operator==(const MyString &lhs, const MyString &rhs);