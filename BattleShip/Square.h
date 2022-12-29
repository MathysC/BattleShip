#pragma once
/// <summary>
/// The square class represents a tuple of coordinates on the board.
/// The square contains the `hit` information. Whether this square was drawn by a player or not.
/// </summary>
class Square
{
private:
	short x;
	short y;
	bool hit;
public:

	/// <summary>
	/// Default constructor of Square.
	/// </summary>
	/// <param name="_x">X coordinate.</param>
	/// <param name="_y">Y coordinate.</param>
	/// <author>MathysC</author>
	Square(short const _x, short const _y);

	/// <summary>
	/// Destructor of Square.
	/// </summary>
	/// <author>MathysC</author>
	~Square();

	/// <returns>The x coordinate to get.</returns>
	/// <author>MathysC</author>
	short getX() const;
	
	/// <returns>The y coordinate to get.</returns>
	/// <author>MathysC</author>
	short getY() const;
	
	/// <returns> the hit value of the square to get.</returns>
	/// <author>MathysC</author>
	bool isHit() const;

	/// <summary>
	/// Set the hit value of the Square.
	/// </summary>
	/// <param name="_h">The new hit value.</param>
	/// <author>MathysC</author>
	void setHit(bool const _h);
};

