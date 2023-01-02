#pragma once
#include "Board.h"
/// More information about State design pattern : https://refactoring.guru/design-patterns/state
/// <summary>
/// BoardState is the common abstract class (interface) for states used by the board to manipulate its components.
/// </summary>
/// <author>MathysC</author>
class BoardState
{
public:
	/// <summary>
	/// Abstract function to treat the BoardState.
	/// Pure virtual function.
	/// </summary>
	/// <param name="_b">The BattleShip Board.</param>
	/// <param name="_x">X coordinate.</param>
	/// <param name="_y">Y coordinate.</param>
	/// <author>MathysC</author>
	virtual void treat(Board _b, short const _x, short const _y) = 0;
	/// More here : https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

};

