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
	bedFixed = false;
}

void Bed::Description()
{
	if(bedFixed == false)
	{
		description =
			"The bed squeaks as you sit up, you look back to see it in its dishevelled state."
			" 'I must've had a nightmare or something... my bed is a mess. Wouldn't take long to clean, I bet.' ";
	}

	else if (bedFixed == true)
	{
		description = "Your bed is much cleaner, now. Its surface smoothed out.";
	}
	return void();
}

void Bed::Use()
{
	bedFixed = true;
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
	if(isWatered == false)
	{
		description = "You also see the window. A small standing table with a potted plant sits idly by it. Looks a bit thirsty.";
	}

	else if (isWatered == true)
	{
		description = "With a bit of a drink, it seems a bit more... lively.";
	}
	return void();
}

void Window::Use()
{
	isWatered = true;
	return Description();
}

Window::~Window()
{
}

// Ghost Item Class
Ghost::Ghost()
{
	isVisible = false;
}

void Ghost::Description()
{
	if (isVisible == false)
	{
		description = "As you enter the room, your ears ring and a chill runs down your spine. Something unnatural is lurking here.";
	}
	else if (isVisible == true)
	{
		description =
			"Having sharpened your mind, you can notice the wispy form that latches to the room with rueful eyes."
			" 'Where are you all coming from...' you'd mumble to yourself.";
	}
	return void();
}


void Ghost::Use()
{
	isVisible = true;
	return Description();
}

Ghost::~Ghost()
{
}

//Shower Item Class
Shower::Shower()
{
	hasShowered = false;
}

void Shower::Description()
{
	if (hasShowered == false)
	{
		description = "The pristine white tiles are encased in glass panes, might be worth having a quick shower before heading out.";
	}
	if (hasShowered == true)
	{
		description = "You've already showered. It'd be a waste of water doing it again.";
	}
	return void();
}

void Shower::Use()
{
	hasShowered = true;
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
	if (amountOfMuffins == 4)
	{
		description = "besides that, there are some breakfast muffins that you've made for the week. All sat on the table on a plate.";
	}
	if (amountOfMuffins > 0 || amountOfMuffins < 4)
	{
		description = "you've already had a muffin, theres a few left.";
	}
	if (amountOfMuffins == 0)
	{
		description = " 'Ah... my gluttony knows no bounds...' ";
	}
}

void Muffins::Use()
{
	amountOfMuffins -= 1;
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
	if(snowMelted == false)
	{
		description =
			" 'Huh... my porch is... covered.' "
			" 'Thats... a lot of snow. ' ";
	}
	else if (snowMelted == true)
	{
		description = "Melted with your mind, nothing but a sad puddle now.";
	}
}

void Snowheap::Use()
{
	snowMelted = true;
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
	if(batteryIsDead == true)
	{
		description =
			"You turn the key, the car's engine chugs for a minute, before you give up. The battery is likely dead."
			"You recall the time you felt a SURGE of electricity from your mind fry your phone. ";
	}
	else if (batteryIsDead == false)
	{
		description =
			"You twist the, the engine purrs as it comes to life. You reverse out of your house, and head to class."
			"Thanks for playing!";
	}
}

void Car::Use()
{
	batteryIsDead = false;
	return Description();
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
	bool results = false;
	while (firstElement <= lastElement)
	{
		int middleElement = (lastElement + firstElement) / 2;

		if (result == list[middleElement])
			results = true;

		if (result < list[middleElement])
			lastElement = middleElement - 1;
			
			
		if (result > list[middleElement])
			firstElement = middleElement + 1;
	}
	return -1;
}

bool Player::FindSpell(string spell)
{
	bool result = BinarySearcher(spellList, spell, 7);
	if (result = false)
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
		item_in->Description();
		itemDescription = item_in->description;
	}

	roomDescription = description;
	
}

void Room::PrintDescription()
{
	cout << roomDescription << endl;

	if (item != nullptr)
	{
		cout << item->description << endl;;
	}
}

Room::~Room()
{
}


Game::Game()
//Defines the rooms that are available to roam in.
	: rooms
{
		Room("Your room, it's a bit bland, a bookshelf sits opposite from your bed which sits against the window. Next to your bed is a desk with a computer. Besides that, your door leads out to the hallway eastward.", &bed),Room("The hallway, some plush carpet stretches along its length. Leads down south.", &window), Room("Snow blankets the grass, and birds sing their songs. Also, I'm freezing. The door is behind you, west.", nullptr),
		Room("The bathroom is small, tiled with white marble. The exit behind you leads east", &shower), Room("The living room, just a couch, and a tv with a coffee table. Westward is the bathroom, Northward is the hallway, Eastward is the kitchen", &ghost), Room("The Kitchen, where all my eating happens. The dinning table is also here. Westward is the Living room, Northward is the backyard, southward your front yard.", &muffins),
		Room("You step into the car, the end of your morning draws close. You can go back by heading east.", &car), Room("The car is in view, this morning is just about done, you'd think. The path leads either west or east.", nullptr), Room("The doorway, accompanied with railing alongside the porch. You can head west to get to your car, or you can head north to go back inside.", &snowheap)
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
	
	while (gameRunning)
	{
		
		Room& playerPosition = rooms[column][row];
		playerPosition.PrintDescription();

		cout << "What should you do next?" << '\n' << endl;
		//cin.ignore();
		getline(cin, playerInput);
		
		// Checks for movement
		if (playerInput == "move north" || playerInput == "north")
		{
			// Blocks anyone in room 4 (the bathroom) from going north to the bedroom, etc etc.
			if (column == 0)
				cout << "A boundary, it blocks my path." << '\n';
			//Otherwise, moves the character
			else
				column -= 1;
		}
		// This is repeated for each direction, however east and west dont need them since theyve only got one room where you can't move that certain direction in.
		else if (playerInput == "move east" || playerInput == "east")
		{
			if (row == 2)
				cout << "A boundary, it blocks my path." << '\n';
			else
				row += 1;
		}

		else if (playerInput == "move south" || playerInput == "south")
		{
			if (column == 2)
				cout << "A boundary, it blocks my path." << '\n';
			else
				column += 1;
		}

		else if (playerInput == "move west" || playerInput == "west")
		{
			if (row == 0)
				cout << "A boundary, it blocks my path." << '\n';
			else
				row -= 1;
		}

		// Checks if the player uses an object


		else if (playerInput == "use" || playerInput == "interact")
		{
			playerPosition.item->Use();
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