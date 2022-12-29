#include "pch.h"
#include "CppUnitTest.h"
#include "..\BattleShip\Square.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BattleShipTest1
{
	TEST_CLASS(SquareTest)
	{
	public:
		TEST_METHOD(TestGetX) {
			short x = 0;
			short y = 10;
			Square square = Square(x, y);
			
			Assert::AreEqual(x, square.getX());
			Assert::AreNotEqual(square.getX(), square.getY());
		}

		TEST_METHOD(TestGetY) {
			short x = 0;
			short y = 10;
			Square square = Square(x, y);

			Assert::AreEqual(y, square.getY());
			Assert::AreNotEqual(square.getX(), square.getY());
		}

		TEST_METHOD(TestIsHit)
		{
			Square square = Square(0, 0);
			Assert::IsFalse(square.isHit());
		}

		TEST_METHOD(TestSetHit)
		{
			Square square = Square(0, 0);
			square.setHit(true);
			Assert::IsTrue(square.isHit()); 
			square.setHit(false);
			Assert::IsFalse(square.isHit());
		}
	};
}
