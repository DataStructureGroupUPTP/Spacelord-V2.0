#include "Game.h"
#include <time.h>

// Main game loop
int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));

	Game instance;

	instance.run();
	
	return 0;
}





