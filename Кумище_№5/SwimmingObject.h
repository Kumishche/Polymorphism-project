#pragma once
#include <iostream>
using namespace std;

class SwimmingObject
{
protected:
	string name;

public:
	SwimmingObject();
	SwimmingObject(const string& name) : name(name) {}

	string getName();
	virtual void toString() const = 0;
};