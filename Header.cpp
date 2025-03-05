#include "Header.h"

// Base item class. Everything is empty </3.
const void Item::description()
{
	return void();
}

void Item::use()
{
	return void();
}

// Bed item class

Bed::Bed()
{
	bool isTidy = false;
}

const void Bed::Description()
{
	string description = "I'll miss you today, my comfy... cozy bed... Looks a bit messy though. Could do with a clean";
	return void();
}

void Bed::Use()
{
	isTidy = true;
}
