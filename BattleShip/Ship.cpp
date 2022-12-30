#include <assert.h>
#include "Ship.h"

Ship::Ship(Way const _way, size_t const _l, short const _x, short const _y):
	way(_way), length(_l)
{
	assert(_l > 0);
	switch (_way)
	{
	case Way::EAST: {
		for (short current_x = _x; current_x < _x + _l; current_x++) {
			this->squares.push_back(Square(current_x, _y));
		}
		break;
	}
	case Way::NORTH: {
		for (short current_y = _y; current_y > _y - _l; current_y--) {
			this->squares.push_back(Square(_x, current_y));
		}
		break;
	}
	case Way::SOUTH: {
		for (short current_y = _y; current_y < _y + _l; current_y++) {
			this->squares.push_back(Square(_x, current_y));
		}
		break;
	}
	case Way::WEST: {
		for (short current_x = _x; current_x > _x - _l; current_x--) {
			this->squares.push_back(Square(current_x, _y));
		}
		break;
	}
	default:
		throw std::invalid_argument("'_way' argument isn’t supported.");
		break;
	}
}

Ship::~Ship() {}

bool Ship::hit(short const _x, short const _y)
{
	// If the ship has already sunk, it cannot be hit anymore.
	if (this->hasSunk()) { 
		return false; 
	}

	// Get the starting point of the ship.
	Square start = this->squares.at(0);
	bool hit = false;
	switch (this->way)
	{
	case Way::EAST: {
		if ((_y == start.getY()) &&
			(_x >= start.getX() && _x <= start.getX() + this->length)) {
			this->squares.at(_x).setHit(true);
			hit = true;
		}
		break;
	}
	case Way::NORTH: {
		if ((_x == start.getX()) &&
			(_y >= start.getY() - this->length && _y <= start.getY())) {
			this->squares.at(_y).setHit(true);
			hit = true;
		}
		break;
	}
	case Way::SOUTH: {
		if ((_x == start.getX()) &&
			(_y >= start.getY() && _y <= start.getY() + this->length)) {
			this->squares.at(_y).setHit(true);
			hit = true;
		}
		break;
	}
	case Way::WEST: {
		if ((_y == start.getY()) &&
			(_x >= start.getX() - this->length && _x <= start.getX())) {
			this->squares.at(_x).setHit(true);
			hit = true;
		}
		break;
	}
	default:
		throw std::invalid_argument("'way' argument isn’t supported.");
		break;
	}

	return hit;
}

bool Ship::hasSunk() const
{
	for (Square square : this->squares) {
		if (!square.isHit()) {
			return false;
		}
	}

	return true;
}
