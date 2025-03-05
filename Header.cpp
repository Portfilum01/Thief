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
	description = "Your bed is much cleaner, now. Its surface smoothed out.";
	return Description();
}

Window::Window()
{
	isWatered = false;
}

void Window::Description()
{
	description = "It's the window. A small standing table with a potted plant sits idly by it.";
	return void();
}

void Window::Use()
{
	cout << "You peer out the window, and you see that your backyard is cloaked in a layer of snow.";
	return Description();
}

Ghost::Ghost()
{
	isBanished = false;
}
void Ghost::Description()
{
	description = "As you enter the room, your ears ring and a chill runs down your spine. Something unnatural is lurking here.";
	return void();
}

void Ghost::Use()
{

