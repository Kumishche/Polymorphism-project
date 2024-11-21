#pragma once
#include "SwimmingObject.h"
using namespace std;

class Surfboard : private SwimmingObject
{
private:
	int length;

public:
	static int static_var;
	Surfboard(const string& name, double length) :
		SwimmingObject(name), length(length) {}
	
	using SwimmingObject::getName;
	int getLength();
	void toString() const override;
};