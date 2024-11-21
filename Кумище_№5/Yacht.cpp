#include "Yacht.h"

void Yacht::toString() const
{
	cout << "Yacht: " << name << ", luxury: " << luxuryLevel << endl;
}

int Yacht::getLuxuryLevel()
{
	return luxuryLevel;
}
