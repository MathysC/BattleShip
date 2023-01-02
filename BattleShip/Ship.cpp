#include <assert.h>
#include "Ship.h"

Ship::Ship(Way const _way, size_t const _l, short const _x, short const _y):
	way(_way), length(_l)
{
	assert(_l > 0);
	switch (_way)
	{
	case Way::EAST: { // x -> x + length && same y
		for (short current_x = _x; current_x < _x + _l; current_x++) {
			this->squares.push_back(Square(current_x, _y));
		}
		break;
	}
	case Way::NORTH: { // same x && y -> y - length
		for (short current_y = _y; current_y < _y - _l; current_y--) {
			this->squares.push_back(Square(_x, current_y));
		}
		break;
	}
	case Way::SOUTH: { // same x && y -> y + length
		for (short current_y = _y; current_y < _y + _l; current_y++) {
			this->squares.push_back(Square(_x, current_y));
		}
		break;
	}
	case Way::WEST: { // x -> x - l -> same y
		for (short current_x = _x; current_x < _x - _l; current_x--) {
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

size_t Ship::getLength() const
{
	return this->length;
}
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
		short _end_x = start.getX() + this->length;
		if (_y == start.getY() &&
			(_x >= start.getX() && 
				_x < _end_x)) {
			hit = !this->squares.at(_x).isHit(); // If already hit then return false.
			this->squares.at(_x).setHit(true);
		}
		break;
	}
	case Way::NORTH: {
		short _end_y = start.getY() - this->length;
		if (_x == start.getX() && 
			(_y > _end_y && 
				_y <= start.getY())) {

			// at = opposite value because the ship is facing the y-axis in the opposite direction
			short _at = this->length - 1 - _y;
			hit = !this->squares.at(_at).isHit(); // If already hit then return false.
			this->squares.at(_at).setHit(true);
		}
		break;
	}
	case Way::SOUTH: {
		short _end_y = start.getY() + this->length;
		if (_x == start.getX() &&
			(_y >= start.getY() && 
				_y < _end_y)) {
			hit = !this->squares.at(_y).isHit(); // If already hit then return false.
			this->squares.at(_y).setHit(true);
		}
		break;
	}
	case Way::WEST: {
		short _end_x = start.getX() - this->length;
		if (_y == start.getY() &&
			(_x > _end_x && 
				_x <= start.getX())) {
			
			// at = opposite value because the ship is facing the x-axis in the opposite direction
			short _at = this->length - 1 - _x;
			hit = !this->squares.at(_at).isHit(); // If already hit then return false.
			this->squares.at(_at).setHit(true);
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
