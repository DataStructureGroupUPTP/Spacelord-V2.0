#include "Game.h"

void Game::updateDifficulty()
{

	if (elapsedTime >= 30.f && elapsedTime <= 31.f)
	{
		this->meteorSpawnRate = 0.25f;
		this->doubleMeteorChance = 5.f;
		this->tripleMeteorChance = 0.f;
	}

	if (elapsedTime >= 105.f && elapsedTime <= 106.f)
	{
		this->meteorSpawnRate = 0.f;
		this->dpsItemSpawnRate = 0.f;
		this->enemySpawnRate = 0.f;
	}

	if(elapsedTime >= 108.f && elapsedTime <= 109.f)
	{
		stageMusic.stop();
		bossMusic.play();
		bossIsActive = true;
		this->boss->spawn(sf::Vector2f(700.f,-200.f));
	}

}