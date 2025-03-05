#include "Header.h"

// Base item class. Everything is empty </3.
void Item::description()
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
	isTidy = false;
}

void Bed::Description()
{
	description = "I'll miss you today, my comfy... cozy bed... Looks a bit messy though. Could do with a clean.";
	return void();
}

void Bed::Use()
{
	isTidy = true;
	description = "There, all tidy... 'thank you past me!' well, you're very welcome, future me.";
	return Description();
}
