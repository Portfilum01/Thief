#pragma once
#include <iostream>
using namespace std;

// Player class
class Player
{
public:
	Player();
	string spellList[7];
	bool FindSpell(string spell);
	~Player();
};


//Derived Rooms

// Items base
class Item
{
public:

	Item();
	//A string description
	virtual void Description();
	string description;

	virtual void Use();

	virtual ~Item();

};


//Derived Items
class Bed : public Item
{
public:

	Bed();
	bool bedFixed;
	void Description() override;
	void Use() override;

	~Bed() override;
};


class Window : public Item
{
public:
	Window();
	bool isWatered;

	void Description() override;
	void Use() override;

	~Window() override;
};

class Ghost : public Item
{
public:
	Ghost();
	bool isVisible;

	void Description() override;
	void Use() override;

	~Ghost() override;
};

class Shower : public Item
{
public:
	Shower();
	bool hasShowered;
	void Description() override;
	void Use() override;

	~Shower() override;
};

class Muffins : public Item
{
public:
	Muffins();
	int amountOfMuffins;
	void Description() override;
	void Use() override;

	~Muffins() override;
};

class Snowheap : public Item
{
public:
	Snowheap();
	bool snowMelted = false;

	void Description() override;
	void Use() override;

	~Snowheap() override;
};

class Car : public Item
{
public:
	Car();
	bool batteryIsDead;

	void Description() override;
	void Use() override;

	~Car() override;
};

// Room base
class Room
{
public:
	// Points to an item
	Item* item;
	string roomDescription;
	string itemDescription;

	//Room constructor for generating a nice room to walk around
	Room(const string& description, Item* item);

	// The actual description
	void PrintDescription();

	// Destructor
	~Room();
};

// Game Class
class Game
{
public:
	Game();

	Bed bed;
	Window window;
	Ghost ghost;
	Shower shower;
	Muffins muffins;
	Snowheap snowheap;
	Car car;

	Room rooms[3][3];
	bool gameRunning;
	int row;
	int column;

	string playerInput;
	~Game();
	void Run();
};