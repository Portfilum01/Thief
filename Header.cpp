#include <string>
#include <iostream>
#include "Header.h"
using namespace std;

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

// Window Item Class
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

// Ghost Item Class
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

//Shower Item Class
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

// Muffins Item Class
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

// Snowheap Item Class
Snowheap::Snowheap()
{
	snowMelted = false;
}

void Snowheap::Description()
{
	description =
		" 'Huh...' "
		"The porch is somehow covered in snow. It's not a problem, but it's certainly a strange occurence. ";
}

void Snowheap::Use()
{
	snowMelted = true;
	description = "Just a puddle on the floor.";
	return Description();
}

// Car Item Class
Car::Car()
{
	batteryIsDead = true;
}

void Car::Description()
{
	description = 
		"You turn the key, the car's engine chugs for a minute, before you give up. The battery is likely dead."
		"Regardless, if the battery is fixed, then this moment will be over, making way for the next moment. Today might be your last, or maybe one of many BEFORE your last. If you haven't already, make sure you take care of any business you might have in the house.";
}

void Car::Use()
{
	if (batteryIsDead == false)
	{
		description = "You twist the key, and the car sparks to life, the engine hums with anticipation as you pull the hand break down and reverse out of your driveway. For today, you leave morning behind. For today, you leave a version of yourself in the past. And your adventure finshes. Thank you for playing.";
	}
}

//Room::Room(string description, Item* item_in)
//	: item(item_in)
//{
//}


Game::Game()
	: rooms
	{ 
		1, 2, 3,
		4, 5, 6,
		7, 8, 9,
	}
{
	gameRunning = true;
	playerPosition = rooms[1][1];
}

Game::~Game()
{
}

void Game::Run()
{
	while (gameRunning)
	{
		cout << "What should you do next?" << '\n' << endl;
		//cin.ignore();
		getline(cin, playerInput);

		if (playerInput == "move north")
			cout << "moved north" << '\n';
		else if (playerInput == "move east")
			cout << "moved east" << '\n';
		else if (playerInput == "move south")
			cout << "moved south" << '\n';
		else if (playerInput == "move west")
			cout << "moved west" << '\n';
	}
}
