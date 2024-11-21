#include "FishingBoat.h"

int FishingBoat::fishingBoatCount = 0;

FishingBoat::FishingBoat(const string& name, int speed, int capacity) :
	Boat(name, speed), capacity(capacity)
{
	fishingBoatCount++;
}

FishingBoat::~FishingBoat()
{
	fishingBoatCount--;
}

void FishingBoat::toString() const
{
	cout << "FishingBoat: " << name <<
		", speed: " << speed <<
		", capacity: " << capacity << endl;
}

int FishingBoat::getCapacity()
{
	return capacity;
}

int FishingBoat::getFishingBoatCount()
{
	return fishingBoatCount;
}
