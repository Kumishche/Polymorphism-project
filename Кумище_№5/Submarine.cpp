#include "Submarine.h"

int Submarine::maxDepth = 0;

Submarine::Submarine(const string& name, int depth) :
	SwimmingObject(name), depth(depth)
{
	if (depth > maxDepth) maxDepth = depth;
}

void Submarine::toString() const
{
	cout << "Submarine: " << name << ", depth: " << depth << endl;
}

int Submarine::getDepth()
{
	return depth;
}

int Submarine::getMaxDepth()
{
	return maxDepth;
}


