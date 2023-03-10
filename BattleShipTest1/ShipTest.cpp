#include "pch.h"
#include "CppUnitTest.h"
#include "..\BattleShip\Ship.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BattleShipTest1
{
	const size_t l = 5;
	Ship shipE = Ship(Way::EAST, l, 0, 0);
	Ship shipN = Ship(Way::EAST, l, 0, 0);
	Ship shipS = Ship(Way::EAST, l, 0, 0);
	Ship shipW = Ship(Way::EAST, l, 0, 0);
	
	TEST_CLASS(ShipTest)
	{
	public:
		TEST_METHOD_INITIALIZE(ShipInitialize) {
			shipE = Ship(Way::EAST, l, 0, 0);
			shipN = Ship(Way::NORTH, l, 0, l-1);
			shipS = Ship(Way::SOUTH, l, 0, 0);
			shipW = Ship(Way::WEST, l, l-1, 0);
		}

		TEST_METHOD(TestGetLength) {
			Assert::AreEqual(l, shipE.getLength());
			Assert::AreEqual(l, shipN.getLength());
			Assert::AreEqual(l, shipS.getLength());
			Assert::AreEqual(l, shipW.getLength());

		}
		TEST_METHOD(TestGetWay) {
			Assert::AreEqual(static_cast<int>(Way::EAST), static_cast<int>(shipE.getWay()));
			Assert::AreEqual(static_cast<int>(Way::NORTH), static_cast<int>(shipN.getWay()));
			Assert::AreEqual(static_cast<int>(Way::SOUTH), static_cast<int>(shipS.getWay()));
			Assert::AreEqual(static_cast<int>(Way::WEST), static_cast<int>(shipW.getWay()));

		}

		TEST_METHOD(TestGetSquares) {
			/* EAST */
			std::vector<Square> squares = shipE.getSquares();
			Assert::AreEqual(l, squares.size());

			for (short i = 0; i < l; i++) {
				Square sq = squares.at(i);
				Assert::AreEqual(i, sq.getX());
				Assert::AreEqual(static_cast<short>(0), sq.getY());
			}

			/* NORTH */
			squares = shipN.getSquares();
			Assert::AreEqual(l, squares.size());

			for (short i = 0; i < l; i++) {
				Square sq = squares.at(i);
				Assert::AreEqual(static_cast<short>(0), sq.getX());
				Assert::AreEqual(static_cast<short>(l - i - 1), sq.getY());
			}

			/* SOUTH */
			squares = shipS.getSquares();
			Assert::AreEqual(l, squares.size());

			for (short i = 0; i < l; i++) {
				Square sq = squares.at(i);
				Assert::AreEqual(static_cast<short>(0), sq.getX());
				Assert::AreEqual(i, sq.getY());
			}

			/* WEST */
			squares = shipW.getSquares();
			Assert::AreEqual(l, squares.size());

			for (short i = 0; i < l; i++) {
				Square sq = squares.at(i);
				Assert::AreEqual(static_cast<short>(l - 1 - i), sq.getX());
				Assert::AreEqual(static_cast<short>(0), sq.getY());
			}
		}

		TEST_METHOD(TestHit) {
			/* EAST */
			// Hit square unavailable for the ship.
			Assert::IsFalse(shipE.hit(10, 10));

			// Hit the ship.
			Assert::IsTrue(shipE.hit(0, 0));
			Assert::IsFalse(shipE.hit(0, 0));
			Assert::IsTrue(shipE.hit(1, 0));
			Assert::IsFalse(shipE.hit(1, 0));
			Assert::IsTrue(shipE.hit(2, 0));
			Assert::IsFalse(shipE.hit(2, 0));
			Assert::IsTrue(shipE.hit(3, 0));
			Assert::IsFalse(shipE.hit(3, 0));
			Assert::IsTrue(shipE.hit(4, 0));
			Assert::IsFalse(shipE.hit(4, 0));

			/* NORTH */
			// Hit square unavailable for the ship.
			Assert::IsFalse(shipN.hit(10, 10));

			// Hit the ship.
			Assert::IsTrue(shipN.hit(0, 4));
			Assert::IsFalse(shipN.hit(0, 4));
			Assert::IsTrue(shipN.hit(0, 3));
			Assert::IsFalse(shipN.hit(0, 3));
			Assert::IsTrue(shipN.hit(0, 2));
			Assert::IsFalse(shipN.hit(0, 2));
			Assert::IsTrue(shipN.hit(0, 1));
			Assert::IsFalse(shipN.hit(0, 1));
			Assert::IsTrue(shipN.hit(0, 0));
			Assert::IsFalse(shipN.hit(0, 0));

			/* SOUTH */
			// Hit square unavailable for the ship.
			Assert::IsFalse(shipS.hit(10, 10));

			// Hit the ship.
			Assert::IsTrue(shipS.hit(0, 0));
			Assert::IsFalse(shipS.hit(0, 0));
			Assert::IsTrue(shipS.hit(0, 1));
			Assert::IsFalse(shipS.hit(0, 1));
			Assert::IsTrue(shipS.hit(0, 2));
			Assert::IsFalse(shipS.hit(0, 2));
			Assert::IsTrue(shipS.hit(0, 3));
			Assert::IsFalse(shipS.hit(0, 3));
			Assert::IsTrue(shipS.hit(0, 4));
			Assert::IsFalse(shipS.hit(0, 4));

			/* WEST */
			// Hit square unavailable for the ship.
			Assert::IsFalse(shipW.hit(10, 10));

			// Hit the ship.
			Assert::IsTrue(shipW.hit(4, 0));
			Assert::IsFalse(shipW.hit(4, 0));
			Assert::IsTrue(shipW.hit(3, 0));
			Assert::IsFalse(shipW.hit(3, 0));
			Assert::IsTrue(shipW.hit(2, 0));
			Assert::IsFalse(shipW.hit(2, 0));
			Assert::IsTrue(shipW.hit(1, 0));
			Assert::IsFalse(shipW.hit(1, 0));
			Assert::IsTrue(shipW.hit(0, 0));
			Assert::IsFalse(shipW.hit(0, 0));

		}
		
		TEST_METHOD(TestHasSunk) {
			Assert::IsFalse(shipE.hasSunk());
			shipE.hit(0,0);
			shipE.hit(1,0);
			shipE.hit(2,0);
			shipE.hit(3,0);
			shipE.hit(4,0);
			Assert::IsTrue(shipE.hasSunk());
		}
	};
}
