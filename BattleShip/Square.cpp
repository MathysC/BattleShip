#include "Square.h"

Square::Square(short const _x, short const _y) :x(_x), y(_y){
	this->hit = false;
}

Square::~Square() {}

short Square::getX() const {
	return this->x; 
}

short Square::getY() const { 
	return this->y; 
}

bool Square::isHit() const { 
	return this->hit; 
}

void Square::setHit(bool const _h) { 
	this->hit = _h; 
}
