#include "Surfboard.h"

void Surfboard::toString() const
{
	cout << "Surfboard: " << name << ", length: " << length << endl;
}

int Surfboard::getLength()
{
	return length;
}
