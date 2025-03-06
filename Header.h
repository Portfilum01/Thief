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
private:
	string powerList[5];

	Player();
	~Player();
	bool FindSpell(string);
};


//Derived Rooms

// Items base
class Item
{
public:
	virtual ~Item() {};

	//A string description
	virtual void Description();
	string description;

	//This is how you'll use the item
	virtual void Use();
};


//Derived Items
class Bed : public Item
{
public:
	Bed();
	bool isTidy;

	void Description() override;
	void Use() override;
};


class Window : public Item
{
public:
	Window();
	bool isWatered;

	void Description();
	void Use();
};

class Ghost : Item
{
public:
	Ghost();
	bool isBanished;

	void Description();
	void Use();
};

class Shower : Item
{
public:
	Shower();
	bool playerClean;
	void Description();
	void Use();
};

class Muffins : Item
{
public:
	Muffins();
	int amountOfMuffins;
	void Description();
	void Use();
};

class Snowheap : Item
{
public:
	Snowheap();
	bool snowMelted = false;
	void Description();
	void Use();
};

class Car : Item
{
public:
	Car();
	bool batteryIsDead;
	void Description();
	void Use();
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