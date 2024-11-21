#pragma once
#include "Boat.h"
using namespace std;

class FishingBoat : public Boat
{
private:
	int capacity;
	static int fishingBoatCount;

public:
	FishingBoat(const string& name, int speed, int capacity);
	~FishingBoat();

	int getCapacity();
	void toString() const override;
	static int getFishingBoatCount();
};