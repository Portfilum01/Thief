#pragma once
#include <iostream>
using namespace std;

// Game Class
class Game
{
private:
	int rooms[3][3];

	int* Player;

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

// Room base
class Room
{
	int* item;
	string description;

	Room(string description, Item item);
	~Room();
	const string description();
};

//Derived Rooms


// Items base
class Item
{
public:
	string description;
	void use();
};


//Derived Items
class Bed : public Item
{
public:
	Bed();
	const string Description();
	void Use();
};

class Mess : public Item
{
public:
	Mess();
	const string Description();
	void Use();
};


class Window : public Item
{
public:
	Window();
	const string Description();
	void Use();
};

class Ghost : public Item
{
public:
	Ghost();
	const string Description();
	void Use();
};

class Shower : public Item
{
public:
	Shower();
	const string Description();
	void Use();
};

class CatBowl : public Item
{
public:
	CatBowl();
	const string Description();
	void Use();
};

class Snowheap : public Item
{
public:
	Snowheap();
	const string Description();
	void Use();
};

class Car : public Item
{
public:
	Car();
	const string Description();
	void Use();
};