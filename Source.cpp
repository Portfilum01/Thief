#include <iostream>

class Game {
protected:
	int rooms[5][3] = 
	{ 1, 2, 3,
	  4, 5, 6,
	  7, 8, 9,
	  10, 11, 12,
	  13, 14, 15 
	};

public:
	Game();
	~Game();
	void Run();

};