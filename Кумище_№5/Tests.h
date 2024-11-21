#pragma once
#include <iostream>
#include <iomanip>
#include "SwimmingObject.h"
#include "Boat.h"
#include "Submarine.h"
#include "Yacht.h"
#include "Surfboard.h"
#include "FishingBoat.h"

class Tests
{
private:
	void countObjectsByType(SwimmingObject** objects, int size);
	int countObjectsByClass(SwimmingObject** objects, int size, int type);
	SwimmingObject** resizeArray(SwimmingObject** arr, int& size);

public:
	void GetTests();
};

