#include "Board.h"

Board::Board() {}

Board::~Board() {}

std::vector<Ship> Board::getShips() const
{
	return this->ships;
}

bool Board::addShip(Ship _ship)
{
	//if (this->ships.size() < NB_SHIPS) {
	//
	//	// Check the positionning of the ship.
	//	switch (_ship.getWay())
	//	{
	//	default:
	//		break;
	//	}
	//}
	return false;
}

bool Board::hitSquare(short const _x, short const _y)
{
	return false;
}

bool Board::isWarOver()
{
	for (Ship ship : this->ships) {
		if (!ship.hasSunk()) { 
			return false; 
		}
	}

	return true;
}
