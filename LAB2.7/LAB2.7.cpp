#include <iostream>
#include <Windows.h>
#include "Calculator.h"

using namespace std;

#pragma pack(push, 1)
class CalculatorPacked {
private:
    Fraction first;
    Fraction second;
};
#pragma pack(pop)

int main() {

    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    cout << "=== ÄÅÌÎÍÑÒÐÀÖ²ß ÊÎÍÑÒÐÓÊÒÎÐ²Â ÒÀ ÏÅÐÅÂÀÍÒÀÆÅÍÍß ===" << endl;
    Fraction f1(LongLong(0, 10), 0.5); 
    Fraction f2(LongLong(0, 5), 0.2);

    Calculator calc(f1, f2);
    cout << calc << endl;

    cout << "\nÐåçóëüòàòè àðèôìåòè÷íèõ îïåðàö³é:" << endl;
    cout << "Äîäàâàííÿ: " << calc.Add() << endl;
    cout << "Â³äí³ìàííÿ: " << calc.Sub() << endl;
    cout << "Ìíîæåííÿ: " << calc.Mul() << endl;

    cout << "\n²íêðåìåíò (ïðåô³êñíèé) äëÿ êàëüêóëÿòîðà:" << endl;
    cout << ++calc << endl;

    cout << "\n=== ÂÂÅÄÅÍÍß ÒÀ ÌÀÑÈÂ ÎÁ'ªÊÒ²Â ===" << endl;
    const int SIZE = 2;
    Calculator calcArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "\nÇàïîâíåííÿ êàëüêóëÿòîðà #" << (i + 1) << ":" << endl;
        cin >> calcArray[i];
    }
    for (int i = 0; i < SIZE; i++) {
        cout << "\nÊàëüêóëÿòîð [" << (i + 1) << "]:\n" << calcArray[i] << endl;
    }

    cout << "\n=== ÐÎÇÌ²Ð ÏÀÌ'ßÒ² (#pragma pack) ===" << endl;
    cout << "Ðîçì³ð Calculator: " << sizeof(Calculator) << " áàéò" << endl;
    cout << "Ðîçì³ð óïàêîâàíîãî CalculatorPacked: " << sizeof(CalculatorPacked) << " áàéò" << endl;

    return 0;
}