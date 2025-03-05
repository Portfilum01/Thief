#pragma once
#include <iostream>
using namespace std;

// Game Class
class Game
{
private:
	int rooms();

public:
	Game();
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


// Items base
class Item
{
public:
	//A string description
	void description();

	//This is how you'll use the item
	void use();
};


//Derived Items
class Bed : Item
{
public:
	Bed();
	const void Description();
	void Use();
};

class Mess : Item
{
public:
	Mess();
	const void Description();
	void Use();
};


class Window : Item
{
public:
	Window();
	const void Description();
	void Use();
};

class Ghost : Item
{
public:
	Ghost();
	const void Description();
	void Use();
};

class Shower : Item
{
public:
	Shower();
	const void Description();
	void Use();
};

class CatBowl : Item
{
public:
	CatBowl();
	const void Description();
	void Use();
};

class Snowheap : Item
{
public:
	Snowheap();
	const void Description();
	void Use();
};

class Car : Item
{
public:
	Car();
	const void Description();
	void Use();
};

// Room base
class Room
{
	// Points to an item
	int* item;

	//Room constructor for generating a nice room to walk around
	Room(string description, Item* item);
	// Destructor
	~Room();
	// The actual description
	const string description();
};

//Derived Rooms