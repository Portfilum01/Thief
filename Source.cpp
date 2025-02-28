#include <iostream>
using namespace std;

class Game 
{
private:
	int rooms[3][3] = 
	{ 1, 2, 3,
	  4, 5, 6,
	  7, 8, 9, 
	};
	
	/*playerCharacter*;*/

public:
	Game();
	~Game();
	void Run();

};

class Player
{
private:
	string powerList[5] = { "Levitate", "Thermal Transfer", "Surge", "Aquagenesis", "Expel" };
};

class Item 
{
public:
	string description;
	void use();
};

int main()
{
	return 0;
}