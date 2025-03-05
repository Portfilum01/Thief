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
	description = "You also see the window. A small standing table with a potted plant sits idly by it.";
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
	//		 "you extend your hand out, and with a sudden shriek, the phantom fades away. Its presence dampened."
	description = 
		"Having sharpened your mind, you can notice the wispy form that latches to the room with rueful eyes."
		" 'Where are you all coming from...' you'd mumble to yourself.";
	return Description();
}

Shower::Shower()
{
	playerClean = false;
}

void Shower::Description()
{
	description = "The pristine white tiles are encased in glass, might be worth having a quick shower before heading out.";
	return void();
}

void Shower::Use()
{
	playerClean = true;
	description = "You've already showered. It'd be a waste of water doing it again.";
	return Description();
}

Muffins::Muffins()
{
	amountOfMuffins = 4;
}

void Muffins::Description()
{
	description = "besides that, there are some breakfast muffins that you've made for the week. All sat on the table on a plate.";
}

void Muffins::Use()
{
	amountOfMuffins -= 1;
	if (amountOfMuffins <= 0)
		description = "You finished the last muffin, There goes the meal plan you set out for the rest of the week.";
	return Description();
}
