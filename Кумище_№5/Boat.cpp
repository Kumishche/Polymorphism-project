#include "Boat.h"

int Boat::boatCount = 0;

Boat::Boat(const string& name, int speed) : SwimmingObject(name), speed(speed)
{
	boatCount++;
}

Boat::~Boat()
{
	boatCount--;
}

void Boat::toString() const
{
	cout << "Boat: " << name << ", speed: " << speed << endl;
}

int Boat::getSpeed()
{
	return speed;
}

int Boat::getBoatCount()
{
	return boatCount;
}
