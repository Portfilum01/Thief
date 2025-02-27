#include <iostream>

class Game 
{
protected:
	int rooms[3][3] = 
	{ 1, 2, 3,
	  4, 5, 6,
	  7, 8, 9, 
	};

public:
	Game();
	~Game();
	void Run();

};

class Item 
{
public:
	std::string description;
	void use();
};