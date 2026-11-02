#pragma once
#include <string>
#include <iostream>

class LongLong
{
private:
    long high = 0;
    unsigned long low = 0;
public:
    LongLong();
    LongLong(long high, unsigned long low);
    LongLong(const LongLong& other);

    long GetHigh() const;
    unsigned long GetLow() const;
    long long ToLongLong() const;
    bool SetHigh(long value);
    bool SetLow(unsigned long value);

    LongLong& operator=(const LongLong& other);
    operator std::string() const;
    LongLong& operator++();
    LongLong& operator--();
    LongLong operator++(int);
    LongLong operator--(int);

    friend LongLong operator+(const LongLong& l, const LongLong& r);
    friend LongLong operator-(const LongLong& l, const LongLong& r);
    friend LongLong operator*(const LongLong& l, const LongLong& r);
    friend LongLong operator/(const LongLong& l, const LongLong& r);
    friend LongLong operator%(const LongLong& l, const LongLong& r);

    friend bool operator==(const LongLong& l, const LongLong& r);
    friend bool operator!=(const LongLong& l, const LongLong& r);
    friend bool operator<(const LongLong& l, const LongLong& r);
    friend bool operator>(const LongLong& l, const LongLong& r);

    friend std::ostream& operator<<(std::ostream& out, const LongLong& obj);
    friend std::istream& operator>>(std::istream& in, LongLong& obj);
};