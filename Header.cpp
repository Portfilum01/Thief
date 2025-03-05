#include "Header.h"

// Base item class. Everything is empty </3.
void Item::Description()
{
	return void();
}

void Item::use()
{
	return void();
}

// Bed item Class

Bed::Bed()
{
	isTidy = false;
}

void Bed::Description()
{
	description =
		"The bed squeaks as you sit up, you look back to see it in its dishevelled state."
		" 'I must've had a nightmare or something... my bed is a mess. Wouldn't take long to clean, I bet.' ";
	return void();
}

void Bed::Use()
{
	isTidy = true;
	description =
		"You spend the next few minutes tidying up your bed. By the end, its much tidier."
		" 'There we are. I'll be seeing you later. Mr Bed.' ";
	return Description();
}