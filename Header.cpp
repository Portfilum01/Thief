#include <string>
#include <iostream>
#include "Header.h"
using namespace std;

Item::Item()
{
}

// Base item class. Everything is empty </3.
void Item::Description()
{
}

void Item::Use()
{
}

Item::~Item()
{
}

// Bed item Class

Bed::Bed()
{
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
	description = "Your bed is much cleaner, now. Its surface smoothed out.";
	return Description();
}

Bed::~Bed()
{
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

Window::~Window()
{
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

Ghost::~Ghost()
{
}

//Shower Item Class
Shower::Shower()
{
}

void Shower::Description()
{
	description = "The pristine white tiles are encased in glass panes, might be worth having a quick shower before heading out.";
	return void();
}

void Shower::Use()
{
	description = "You've already showered. It'd be a waste of water doing it again.";
	return Description();
}

Shower::~Shower()
{
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

Muffins::~Muffins()
{
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
		"The porch is somehow covered in snow. It's not a problem, but it's certainly strange. ";
}

void Snowheap::Use()
{
	snowMelted = true;
	description = "Just a puddle on the floor.";
	return Description();
}

Snowheap::~Snowheap()
{
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
		"You recall the time you felt a SURGE of electricity from your mind fry your phone. ";
}

void Car::Use()
{
	if (batteryIsDead == false)
	{
		description = 
			"You twist the, the engine purrs as it comes to life. You reverse out of your house, and head to class."
			"Thanks for playing!";
	}
}

Car::~Car()
{
}

// Player
Player::Player()
// Mah spells!
{
	spellList[7] = "Levitate", "Hear Thoughts", "Heatwave", "Surge", "Torrent", "Banish", "Project";
}

//bool Player::FindSpell(string spell)
//{
//	if (spell == spellList[4]);
//
//}

Player::~Player()
{
}

// Rooms

Room::Room(string description, Item* item_in)
	: item(item_in)
{
}


Game::Game()
//Defines the rooms that are available.
	: rooms
	{ 
		1, 2, 3,
		4, 5, 6,
		7, 8, 9,
	}
{
	// Some useful variables to help move around the house and also start the game.
	gameRunning = true;
	row = 0;
	column = 0;
	playerPosition = rooms[column][row];
}

Game::~Game()
{
}

// A quick tool to allow me to block certain rooms from other rooms, such as from the bedroom to the bathroom (1 to 4).
bool IfSpace(int pos, int* blockedRooms, int arrayLength)
{
	// Checks to see if the pos (players position) is in a room where you cant move to a different room from.
	for (int i = 0; i < arrayLength; i++)
	{
		if (pos == blockedRooms[i])
			return true;
	}
	return false;
}

void Game::Run()
{
	while (gameRunning)
	{
		cout << "What should you do next?" << '\n' << endl;
		//cin.ignore();
		getline(cin, playerInput);
		
		// Checks for movement
		if (playerInput == "move north")
		{
			// Blocks anyone in room 4 (the bathroom) from going north to the bedroom, etc etc.
			int blockedRooms[3] = { 4, 7, 8 };
			if (column == 0 || IfSpace(playerPosition, blockedRooms, 3))
				cout << "A boundary, it blocks my path." << '\n';
			//Otherwise, moves the character
			else
				column -= 1;
		}
		// This is repeated for each direction, however east and west dont need them since theyve only got one room where you can't move that certain direction in.
		else if (playerInput == "move east")
		{
			if (row == 2 || playerPosition == 2)
				cout << "A boundary, it blocks my path." << '\n';
			else
				row += 1;
		}

		else if (playerInput == "move south")
		{
			int blockedRooms[3] = { 1, 4, 5 };
			if (column == 2 || IfSpace(playerPosition, blockedRooms, 3))
				cout << "A boundary, it blocks my path." << '\n';
			else
				column += 1;
		}

		else if (playerInput == "move west")
		{
			if (row == 0 || playerPosition == 3)
				cout << "A boundary, it blocks my path." << '\n';
			else
				row -= 1;
		}

		//Checks for spell information
		else if (playerInput == "abilities")
			cout << "Levitate, " << "Hear Thoughts, " << "Heatwave, " << "Surge, " << "Torrent, " << "Banish, " << "Project" << endl;

		// If none of the above, does nothing
		else
			cout << "No valid input detected" << endl;

		// Updates playerPosition and prints spatial information
		playerPosition = rooms[column][row];
		cout << playerPosition << " " << row << " " << column << " " << endl;
	}
}

