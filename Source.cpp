#include "Header.h"

int main()
{
	{
		Item* item = new Bed();
		item->Use();
		delete item;
	}
	Game theGame;
	theGame.Run();


}