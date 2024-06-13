#include "Game.h"
#include <time.h>

int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));

	Game instance;

	instance.run();

}