#include "MyString.h"

#include <cstring>

#pragma warning(disable : 4996)

MyString::MyString(const char *string) : length(strlen(string)), cString(new char[length + 1])
{
    strcpy(cString, string);
}

MyString::MyString(const MyString &other) : MyString(other.cString) {}

MyString::~MyString()
{
    delete[] cString;
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        MyString copy(other);
        swap(copy);
    }
    return *this;
}

size_t MyString::getLength() const
{
    return length;
}

const char *MyString::getCString() const
{
    return cString;
}

void MyString::swap(MyString &other)
{
    char *tempCString = cString;
    cString = other.cString;
    other.cString = tempCString;

    unsigned tempLength = length;
    length = other.length;
    other.length = tempLength;
}

std::ostream &operator<<(std::ostream &os, const MyString &string)
{
    return os << string.getCString();
}

std::istream &operator>>(std::istream &is, MyString &string)
{
    char buffer[1024];
    is >> buffer;

    if (is)
    {
        delete[] string.cString;
        string.cString = new char[strlen(buffer) + 1];
        strcpy(string.cString, buffer);
    }

    return is;
}

bool operator==(const MyString &lhs, const MyString &rhs)
{
    return std::strcmp(lhs.getCString(), rhs.getCString()) == 0;
}
