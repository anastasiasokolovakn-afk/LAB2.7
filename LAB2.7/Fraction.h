#pragma once
#include "LongLong.h"

using namespace std;

class Fraction
{
private:
    LongLong whole;
    double frac = 0.0;
public:
    Fraction();
    Fraction(const LongLong& whole, double frac);
    Fraction(const Fraction& other);

    LongLong GetWhole() const;
    double GetFrac() const;
    double ToDouble() const;
    bool SetWhole(const LongLong& value);
    bool SetFrac(double value);

    static Fraction MakeFraction(double value);

    Fraction& operator=(const Fraction& other);
    operator string() const;
    Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    friend Fraction operator+(const Fraction& l, const Fraction& r);
    friend Fraction operator-(const Fraction& l, const Fraction& r);
    friend Fraction operator*(const Fraction& l, const Fraction& r);
    friend Fraction operator/(const Fraction& l, const Fraction& r);

    friend bool operator==(const Fraction& l, const Fraction& r);
    friend bool operator<(const Fraction& l, const Fraction& r);
    friend bool operator>(const Fraction& l, const Fraction& r);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);
    friend std::istream& operator>>(std::istream& in, Fraction& obj);
};