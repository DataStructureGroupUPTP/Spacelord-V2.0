#include "Game.h"

void Game::updateDifficulty()
{

	if (elapsedTime >= 30.f && elapsedTime <= 31.f)
	{
		this->meteorSpawnRate = 0.25f;
		this->doubleMeteorChance = 5.f;
		this->tripleMeteorChance = 0.f;
	}

	if(elapsedTime >= 105 && elapsedTime <= 106)
	{
	
	}

}