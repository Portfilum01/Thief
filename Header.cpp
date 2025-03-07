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
	description = "You peer out the window, and you see that your backyard is cloaked in a layer of snow.";
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
		" 'Thats... a lot of snow. ' ";
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
	: spellList
{
	"Banish", "Heatwave", "Levitate", "Project", "Surge", "Telepathy", "Torrent"
}
{
}

// Making the binary search function
int BinarySearcher(string list[], string result, int sizeOfArray)
{
	int firstElement = 0;
	int lastElement = sizeOfArray - 1;
	int results = -1;
	while (firstElement <= lastElement)
	{
		int middleElement = (lastElement + firstElement) / 2;

		if (result == list[middleElement])
			results = 0;

		if (results == 0)
			return middleElement;

		if (result < list[middleElement])
			lastElement = middleElement - 1;
			
			
		if (result > list[middleElement])
			firstElement = middleElement + 1;
	}
	return -1;
}

bool Player::FindSpell(string spell)
{
	int result = BinarySearcher(spellList, spell, 7);
	if (result == -1)
		return -1;
	else if (result == 0)
		return result;
}

Player::~Player()
{
}

// Rooms

Room::Room(const string& description, Item* item_in)
	: item(item_in)
{
	if(item_in != nullptr)
	{
		item_in->Use();
		item_in->Description();
	}
}

const string Room::description()
{
	return string();
}

Room::~Room()
{
}



Game::Game()
//Defines the rooms that are available to roam in.
	: rooms
{
		Room("Your room, it's a bit bland, a bookshelf sits opposite from your bed which sits against the window. Next to your bed is a desk with a computer.", &bed),Room("The hallway, some plush carpet stretches along its length.", &window), Room("Snow blankets the grass, and birds sing their songs. Also, I'm freezing.", nullptr),
		Room("The bathroom is small, tiled with white marble.", &shower), Room("The living room, just a couch, and a tv with a coffee table.", &ghost), Room("The Kitchen, where all my eating happens. The dinning table is also here.", &muffins),
		Room("You step into the car, the end of your morning draws close.", &car), Room("The car is in view, this morning is just about done, you'd think.", nullptr), Room("The doorway, accompanied with railing alongside the porch.", &snowheap)
}
// Some useful variables to help move around the house and also start the game.
{
	gameRunning = true;
	row = 0;
	column = 0;
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
	Room& playerPosition = rooms[column][row];
	while (gameRunning)
	{
		cout << "What should you do next?" << '\n' << endl;
		//cin.ignore();
		getline(cin, playerInput);
		
		// Checks for movement
		if (playerInput == "move north")
		{
			// Blocks anyone in room 4 (the bathroom) from going north to the bedroom, etc etc.
			if (column == 0)
				cout << "A boundary, it blocks my path." << '\n';
			//Otherwise, moves the character
			else
				column -= 1;
		}
		// This is repeated for each direction, however east and west dont need them since theyve only got one room where you can't move that certain direction in.
		else if (playerInput == "move east")
		{
			if (row == 2)
				cout << "A boundary, it blocks my path." << '\n';
			else
				row += 1;
		}

		else if (playerInput == "move south")
		{
			if (column == 2)
				cout << "A boundary, it blocks my path." << '\n';
			else
				column += 1;
		}

		else if (playerInput == "move west")
		{
			if (row == 0)
				cout << "A boundary, it blocks my path." << '\n';
			else
				row -= 1;
		}

		//Checks for spell information
		else if (playerInput == "abilities")
			cout << "Levitate, " << "Telepathy, " << "Heatwave, " << "Surge, " << "Torrent, " << "Banish, " << "Project" << endl;

		//Every spell is checked in the 
		else if (playerInput == "levitate")
		{
			Player castingLevitate;
			castingLevitate.FindSpell("levitate");
			cout << "You hover slightly above the floor, an ultimate display of power! I guess." << endl;
		}

		else if (playerInput == "telepathy")
		{
			Player castingLevitate;
			castingLevitate.FindSpell("telepathy");
			cout << "You... cannot hear anyone." << endl;
		}

		else if (playerInput == "heatwave")
		{
			Player castingLevitate;
			castingLevitate.FindSpell("heatwave");
			cout << "A wave of heat emits from your palms, could be useful later since it just snowed." << endl;
		}

		else if (playerInput == "surge")
		{
			Player castingLevitate;
			castingLevitate.FindSpell("surge");
			cout << "A current of electricity crackles through your fingertips." << endl;
		}

		else if (playerInput == "torrent")
		{
			Player castingLevitate;
			castingLevitate.FindSpell("torrent");
			cout << "Water drips from your hands, and now the floor is wet." << endl;
		}

		else if (playerInput == "banish")
		{
			Player castingLevitate;
			castingLevitate.FindSpell("banish");
			cout << "It would be useful in the presence of spectres or ne'erdowells, but you're not really in either's presence." << endl;
		}

		else if (playerInput == "project")
		{
			Player castingLevitate;
			castingLevitate.FindSpell("project");
			cout << "Now is probably not the best time for astral projection" << endl;
		}
		// If none of the above, does nothing
		else
			cout << "No valid input detected" << endl;

		// Updates playerPosition and prints spatial information
		//playerPosition = rooms[column][row];
		cout << " " << row << " " << column << " " << endl;
	}
}

Game::~Game()
{
}