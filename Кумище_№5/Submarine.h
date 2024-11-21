#pragma once
#include "SwimmingObject.h"
using namespace std;

class Submarine : public SwimmingObject
{
private:
	int depth;
	static int maxDepth;

public:
	Submarine(const string& name, int depth);

	int getDepth();
	void toString() const override;
	static int getMaxDepth();
};