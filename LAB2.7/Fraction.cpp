#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

Fraction::Fraction() {
	frac = 0.0;
}

Fraction::Fraction(const LongLong& w, double f) {
	SetWhole(w);
	if (!SetFrac(f)) {
		frac = 0.0;
	}
}

Fraction::Fraction(const Fraction& other) {
	whole = other.whole;
	frac = other.frac;
}

LongLong Fraction::GetWhole() const {
	return whole;
}

double Fraction::GetFrac() const {
	return frac;
}

double Fraction::ToDouble() const {
	double w = (double)whole.ToLongLong();
	if (w < 0) {
		return w - frac;
	}
	else {
		return w + frac;
	}
}

bool Fraction::SetWhole(const LongLong& value) {
	whole = value;
	return true;
}

bool Fraction::SetFrac(double value) {
	if (value >= 0.0 && value < 1.0) {
		frac = value;
		return true;
	}
	else {
		return false;
	}
}

Fraction Fraction::MakeFraction(double value) {
	long long w = (long long)value;
	double f = abs(value - w);
	return Fraction(LongLong((long)(w >> 32), (unsigned long)(w & 0xFFFFFFFF)), f);
}

Fraction& Fraction::operator=(const Fraction& other) {
	if (this != &other) {
		whole = other.whole;
		frac = other.frac;
	}
	return *this;
}

Fraction::operator string() const {
	stringstream sout;
	sout << ToDouble() << " (ціла: " << string(whole) << ", дробова: " << frac << ")";
	return sout.str();
}

Fraction& Fraction::operator++() {
	++whole;
	return *this;
}

Fraction& Fraction::operator--() {
	--whole;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	whole++;
	return temp;
}

Fraction Fraction::operator--(int) {
	Fraction temp = *this;
	whole--;
	return temp;
}

Fraction operator+(const Fraction& l, const Fraction& r) {
	return Fraction::MakeFraction(l.ToDouble() + r.ToDouble());
}

Fraction operator-(const Fraction& l, const Fraction& r) {
	return Fraction::MakeFraction(l.ToDouble() - r.ToDouble());
}

Fraction operator*(const Fraction& l, const Fraction& r) {
	return Fraction::MakeFraction(l.ToDouble() * r.ToDouble());
}

Fraction operator/(const Fraction& l, const Fraction& r) {
	if (r.ToDouble() == 0.0) {
		return Fraction(LongLong(0, 0), 0.0);
	}
	return Fraction::MakeFraction(l.ToDouble() / r.ToDouble());
}

bool operator==(const Fraction& l, const Fraction& r) {
	return l.ToDouble() == r.ToDouble();
}

bool operator<(const Fraction& l, const Fraction& r) {
	return l.ToDouble() < r.ToDouble();
}

bool operator>(const Fraction& l, const Fraction& r) {
	return l.ToDouble() > r.ToDouble();
}

ostream& operator<<(ostream& out, const Fraction& obj) {
	out << string(obj);
	return out;
}

istream& operator>>(istream& in, Fraction& obj) {
	LongLong w;
	double f;
	cout << "Введення цілої частини (LongLong):" << endl;
	in >> w;
	do {
		cout << "Введіть дробову частину (від 0.0 до 1.0): ";
		in >> f;
	} while (!obj.SetFrac(f));
	obj.SetWhole(w);
	return in;
}