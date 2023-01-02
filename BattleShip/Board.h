#pragma once
#include <vector>
#include "BoardState.h"
#include "Ship.h"

class Board
{
private:
	BoardState* currentState;
	std::vector<Ship> ships;
public:
	const static unsigned short MAX_LENGTH = 10;
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
	/// If all ships on the board are sunk. So the war is over.
	/// </summary>
	/// <returns>True if all ships are sunk, false otherwise.</returns>
	/// <author>MathysC</author>
	bool isWarOver();

	/// <summary>
	/// Apply the currentState of the Board.
	/// </summary>
	/// <param name="_x">X coordinate.</param>
	/// <param name="_y">Y coordinate.</param>
	/// <author>MathysC</author>
	void applyState(short const _x, short const _y);
};

