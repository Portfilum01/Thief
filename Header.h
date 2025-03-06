#pragma once
#include <iostream>
using namespace std;

// Game Class
class Game
{
public:
	Game();

	int rooms[3][3];
	int playerPosition;
	bool gameRunning;
	int row;
	int column;

	string playerInput;
	~Game();
	void Run();
};

// Player class
class Player
{
public:
	Player();
	string spellList[];
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

class Ghost : Item
{
public:
	Ghost();
	bool isBanished;

	void Description() override;
	void Use() override;

	~Ghost() override;
};

class Shower : Item
{
public:
	Shower();
	void Description() override;
	void Use() override;

	~Shower() override;
};

class Muffins : Item
{
public:
	Muffins();
	int amountOfMuffins;
	void Description();
	void Use();

	~Muffins() override;
};

class Snowheap : Item
{
public:
	Snowheap();
	bool snowMelted = false;

	void Description();
	void Use();

	~Snowheap() override;
};

class Car : Item
{
public:
	Car();
	bool batteryIsDead;

	void Description();
	void Use();

	~Car() override;
};

// Room base
class Room
{
	// Points to an item
	Item* item;

	//Room constructor for generating a nice room to walk around
	Room(string description, Item* item);
	// Destructor
	~Room();
	// The actual description
	const string description();
};