#include "LongLong.h"
#include <sstream>
#include <iostream>

using namespace std;

LongLong::LongLong() {
	high = 0;
	low = 0;
}

LongLong::LongLong(long h, unsigned long l) {
	SetHigh(h);
	SetLow(l);
}

LongLong::LongLong(const LongLong& other) {
	high = other.high;
	low = other.low;
}

long LongLong::GetHigh() const {
	return high;
}

unsigned long LongLong::GetLow() const {
	return low;
}

long long LongLong::ToLongLong() const {
	return ((long long)high << 32) | low;
}

bool LongLong::SetHigh(long value) {
	high = value;
	return true;
}

bool LongLong::SetLow(unsigned long value) {
	low = value;
	return true;
}

LongLong& LongLong::operator=(const LongLong& other) {
	if (this != &other) {
		high = other.high;
		low = other.low;
	}
	return *this;
}

LongLong::operator string() const {
	stringstream sout;
	sout << ToLongLong() << " (старша: " << high << ", молодша: " << low << ")";
	return sout.str();
}

LongLong& LongLong::operator++() {
	low++;
	return *this;
}

LongLong& LongLong::operator--() {
	low--;
	return *this;
}

LongLong LongLong::operator++(int) {
	LongLong temp = *this;
	low++;
	return temp;
}

LongLong LongLong::operator--(int) {
	LongLong temp = *this;
	low--;
	return temp;
}

LongLong operator+(const LongLong& l, const LongLong& r) {
	long long res = l.ToLongLong() + r.ToLongLong();
	return LongLong((long)(res >> 32), (unsigned long)(res & 0xFFFFFFFF));
}

LongLong operator-(const LongLong& l, const LongLong& r) {
	long long res = l.ToLongLong() - r.ToLongLong();
	return LongLong((long)(res >> 32), (unsigned long)(res & 0xFFFFFFFF));
}

LongLong operator*(const LongLong& l, const LongLong& r) {
	long long res = l.ToLongLong() * r.ToLongLong();
	return LongLong((long)(res >> 32), (unsigned long)(res & 0xFFFFFFFF));
}

LongLong operator/(const LongLong& l, const LongLong& r) {
	if (r.ToLongLong() == 0) {
		return LongLong(0, 0);
	}
	long long res = l.ToLongLong() / r.ToLongLong();
	return LongLong((long)(res >> 32), (unsigned long)(res & 0xFFFFFFFF));
}

LongLong operator%(const LongLong& l, const LongLong& r) {
	if (r.ToLongLong() == 0) {
		return LongLong(0, 0);
	}
	long long res = l.ToLongLong() % r.ToLongLong();
	return LongLong((long)(res >> 32), (unsigned long)(res & 0xFFFFFFFF));
}

bool operator==(const LongLong& l, const LongLong& r) {
	return l.ToLongLong() == r.ToLongLong();
}

bool operator!=(const LongLong& l, const LongLong& r) {
	return l.ToLongLong() != r.ToLongLong();
}

bool operator<(const LongLong& l, const LongLong& r) {
	return l.ToLongLong() < r.ToLongLong();
}

bool operator>(const LongLong& l, const LongLong& r) {
	return l.ToLongLong() > r.ToLongLong();
}

ostream& operator<<(ostream& out, const LongLong& obj) {
	out << string(obj);
	return out;
}

istream& operator>>(istream& in, LongLong& obj) {
	long h;
	unsigned long l;
	cout << "¬вед≥ть старшу частину (high): ";
	in >> h;
	cout << "¬вед≥ть молодшу частину (low): ";
	in >> l;
	obj.SetHigh(h);
	obj.SetLow(l);
	return in;
}