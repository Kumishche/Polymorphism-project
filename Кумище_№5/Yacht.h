#pragma once
#include "SwimmingObject.h"

class Yacht : public SwimmingObject
{
private:
	int luxuryLevel;
	Yacht();

public:
	Yacht(const string& name, int luxuryLevel) :
		SwimmingObject(name), luxuryLevel(luxuryLevel) {}
	Yacht(const Yacht& yacht) = delete;

	int getLuxuryLevel();
	void toString() const override;
};
