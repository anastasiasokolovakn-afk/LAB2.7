#pragma once
#include "Fraction.h"

class Calculator
{
private:
    Fraction first;
    Fraction second;
public:
    Calculator();
    Calculator(const Fraction& f1, const Fraction& f2);
    Calculator(const Calculator& other);

    Fraction GetFirst() const;
    Fraction GetSecond() const;
    bool SetFirst(const Fraction& value);
    bool SetSecond(const Fraction& value);

    Calculator& operator=(const Calculator& other);
    operator std::string() const;
    Calculator& operator++();
    Calculator& operator--();
    Calculator operator++(int);
    Calculator operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Calculator& obj);
    friend std::istream& operator>>(std::istream& in, Calculator& obj);

    Fraction Add() const { return first + second; }
    Fraction Sub() const { return first - second; }
    Fraction Mul() const { return first * second; }
    Fraction Div() const { return first / second; }
    bool Equal() const { return first == second; }
};