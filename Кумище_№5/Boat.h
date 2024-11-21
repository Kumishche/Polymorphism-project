#pragma once
#include "SwimmingObject.h"
using namespace std;

class Boat : public SwimmingObject
{
protected:
	int speed;
	static int boatCount;

public:
	Boat(const string& name, int speed);
	~Boat();

	int getSpeed();
	void toString() const override;

	static int getBoatCount();
};