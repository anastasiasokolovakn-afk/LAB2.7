#include "Calculator.h"
#include <iostream>
#include <sstream>

using namespace std;

Calculator::Calculator() {
}

Calculator::Calculator(const Fraction& f1, const Fraction& f2) {
	SetFirst(f1);
	SetSecond(f2);
}

Calculator::Calculator(const Calculator& other) {
	first = other.first;
	second = other.second;
}

Fraction Calculator::GetFirst() const {
	return first;
}

Fraction Calculator::GetSecond() const {
	return second;
}

bool Calculator::SetFirst(const Fraction& value) {
	first = value;
	return true;
}

bool Calculator::SetSecond(const Fraction& value) {
	second = value;
	return true;
}

Calculator& Calculator::operator=(const Calculator& other) {
	if (this != &other) {
		first = other.first;
		second = other.second;
	}
	return *this;
}

Calculator::operator string() const {
	stringstream sout;
	sout << "ќперанд 1: " << string(first) << "\nќперанд 2: " << string(second);
	return sout.str();
}

Calculator& Calculator::operator++() {
	++first;
	++second;
	return *this;
}

Calculator& Calculator::operator--() {
	--first;
	--second;
	return *this;
}

Calculator Calculator::operator++(int) {
	Calculator temp = *this;
	first++;
	second++;
	return temp;
}

Calculator Calculator::operator--(int) {
	Calculator temp = *this;
	first--;
	second--;
	return temp;
}

ostream& operator<<(ostream& out, const Calculator& obj) {
	out << string(obj);
	return out;
}

istream& operator>>(istream& in, Calculator& obj) {
	cout << "--- ¬вед≥ть перший др≥б ---" << endl;
	in >> obj.first;
	cout << "--- ¬вед≥ть другий др≥б ---" << endl;
	in >> obj.second;
	return in;
}