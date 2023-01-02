#pragma once
#include "BoardState.h"

/// <summary>
/// The HitSquare state represent the main action on a BattleShip Board: Hit a square.
/// </summary>
/// <author>MathysC</author>
class HitSquare :
    public BoardState
{
public:
	/// <summary>
	/// Default constructor of HitSquare State.
	/// </summary>
	/// <author>MathysC</author>
	HitSquare();

	/// <summary>
	/// Default destructor of HitSquare State.
	/// </summary>
	/// <author>MathysC</author>
	~HitSquare();


	/// <summary>
	/// Hit a square on the Board at the given coordinates.
	/// </summary>
	/// <param name="_b">The BattleShip Board.</param>
	/// <param name="_x">X coordinate.</param>
	/// <param name="_y">Y coordinate.</param>
	/// <author>MathysC</author>
	void treat(Board _b, short const _x, short const _y);
};

