#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB2.7/Calculator.h"
#include "../LAB2.7/Fraction.h"
#include "../LAB2.7/LongLong.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestFractionOperators)
		{
			Fraction f1(LongLong(0, 5), 0.5);
			Fraction f2(LongLong(0, 2), 0.2);

			Fraction sum = f1 + f2;
			Assert::AreEqual(7.7, sum.ToDouble(), 0.001);

			++sum;
			Assert::AreEqual(8.7, sum.ToDouble(), 0.001);
		}

		TEST_METHOD(TestCalculatorArithmetic)
		{
			Fraction f1(LongLong(0, 10), 0.0);
			Fraction f2(LongLong(0, 5), 0.0);
			Calculator calc(f1, f2);

			Assert::AreEqual(15.0, calc.Add().ToDouble(), 0.001);
			Assert::AreEqual(2.0, calc.Div().ToDouble(), 0.001);
		}
	};
}