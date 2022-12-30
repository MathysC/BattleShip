#pragma once
#include <stdexcept>
#include <vector>
#include "Square.h"
enum class Way {
	EAST, 
	NORTH,
	SOUTH,
	WEST,
};

class Ship
{
private:
	Way way;
	size_t length;
	std::vector<Square> squares;

public:
	/// <summary>
	/// Constructor of Ship.
	/// Set the way the ship is facing, in order to create the squares needed with correct coordinates.
	/// </summary>
	/// <param name="_way">The way the ship is facing.</param>
	/// <param name="_l">The length of the ship.</param>
	/// <param name="_x">The x coordinate of the start of the ship.</param>
	/// <param name="_y">The y coordinate of the start of the ship.</param>
	/// <author>MathysC</author>
	Ship(Way const _way, size_t const _l, short const _x, short const _y);

	/// <summary>
	/// Destructor of Ship.
	/// </summary>
	/// <author>MathysC</author>
	~Ship();

	/// <summary>
	/// Hit the ship at the given coordinates.
	/// </summary>
	/// <param name="x">The x coordinate of the hit.</param>
	/// <param name="y">The y coordinate of the hit.</param>
	/// <returns>True if the ship is hit, else false.</returns>
	/// <author>MathysC</author>
	bool hit(short const _x, short const _y);

	/// <summary>
	/// Check if the ship is completely sunk or not.
	/// </summary>
	/// <returns>True if each squares of the Ship are hit, else false if at least one square is not hit yet.</returns>
	/// <author>MathysC</author>
	bool hasSunk() const;
};

