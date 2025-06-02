#include "MyString.h"
#include <cstring>
MyString::MyString(const char *string) : length(strlen(string)), cString(new char[length])
{
    strcpy(cString, string);
}

MyString::MyString(const MyString &other) : MyString(other.cString) {}

MyString::~MyString()
{
    delete[] cString;
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
    std::swap(cString, other.cString);
    std::swap(length, other.length);
}

std::ostream &operator<<(std::ostream &os, const MyString &string)
{
    return os << string.getCString();
}

std::istream &operator>>(std::istream &is, MyString &string)
{
    char buffer[256];
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
    return strcmp(lhs.getCString(), rhs.getCString()) == 0;
}