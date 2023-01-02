#pragma once
#include <vector>
#include "Ship.h"

class Board
{
private:
	std::vector<Ship> ships;
public:
	const static size_t MAX_LENGTH = 10;
	const static size_t NB_SHIPS = 5;

	/// <summary>
	/// Default constructor of Board.
	/// </summary>
	/// <author>MathysC</author>
	Board();
	
	/// <summary>
	/// Default destructor of Board.
	/// </summary>
	/// <author>MathysC</author>
	~Board();

	/// <summary>
	/// Add a ship to the Board if possible.
	/// The constraints are:
	/// - The maximal size of the vector must be less than `NB_SHIPS`.
	/// - The positionning of the ship can be contained by the Board.
	/// </summary>
	/// <param name="_ship">The ship to add.</param>
	/// <returns></returns>
	bool addShip(Ship _ship);

	/// <summary>
	/// Hit a square on the board at the given coordinates 
	/// </summary>
	/// <param name="_x">X coordinate.</param>
	/// <param name="_y">Y coordinate.</param>
	/// <returns>True if a ship was hit, false otherwise.</returns>
	/// <author>MathysC</author>
	bool hitSquare(short const _x, short const _y);

	/// <summary>
	/// If all ships on the board are sunk. So the war is over.
	/// </summary>
	/// <returns>True if all ships are sunk, false otherwise.</returns>
	/// <author>MathysC</author>
	bool isWarOver();
};

