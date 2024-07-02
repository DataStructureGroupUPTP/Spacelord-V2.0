#include "Game.h"

void Game::updateDifficulty()
{
	if (Stage == 1) {

		if (elapsedTime >= 30.f && elapsedTime <= 31.f)
		{
			this->meteorSpawnRate = 0.3f;
			this->doubleMeteorChance = 10;
			this->tripleMeteorChance = 0;
		}

		if (elapsedTime >= 60.f && elapsedTime <= 61.f)
		{
			this->meteorSpawnRate = 0.75f;
			this->doubleMeteorChance = 15;
		}

		if (elapsedTime >= 105.f && elapsedTime <= 106.f)
		{
			this->meteorSpawnRate = 0.f;
			this->dpsItemSpawnRate = 0.f;
			this->enemySpawnRate = 0.f;
			this->backgroundScrollSpeed = 3.0f;
			this->doubleMeteorChance = 5;
		}

		if (elapsedTime >= 110.f && elapsedTime <= 111.f)
		{
			if (!bossIsActive) {
				if (!this->stageMusic.openFromFile("Music/BossMusic.ogg"))
				{
					std::cout << "ERROR::BOSSMUSIC::FAILED_TO_LOAD" << "\n";
				}
				this->stageMusic.play();

				bossIsActive = true;
				this->boss->spawn(sf::Vector2f(560.f, -200.f), sf::Vector2f(600.f, 300.f));
			}
		}

		if (elapsedTime >= 112.f && elapsedTime <= 126.5f)
		{
			this->player->setAttackCooldown(0);
		}

		if (elapsedTime >= 126.5f && elapsedTime <= 128.f)
		{
			startShooting = true;
		}

		if (((elapsedTime >= 158.f && elapsedTime <= 159.f && startShooting) or (this->boss->getHp() <= 50)) && checkerOne)
		{
			this->meteorSpawnRate = 0.35f;
			this->bossAttackCooldownMax = 50.f;

		}

		if (elapsedTime >= 195.f && elapsedTime <= 196.f && startShooting)
		{
			this->meteorSpawnRate = 0.8f;
			this->bossAttackCooldownMax = 30.f;

		}

		if (bossDefeated && checkerOne)
		{
			this->stageMusic.stop();
			this->explosionSound.play();
			this->startShooting = false;
			this->meteorSpawnRate = 0.f;
			this->timeStamp = elapsedTime;
			this->stageTransition = true;
			bossDefeated = false;
			this->points = points + 50000;
			this->gameData.coins = gameData.coins + 500;
			this->enemyKillCounter = enemyKillCounter + 40;
			checkerOne = false;
			this->backgroundScrollSpeed = 2.0f;

		}

		if (elapsedTime >= timeStamp + 5.f && stageTransition)
		{
			this->healthItemSpawnRate = 0.5f;
			this->dpsItemSpawnRate = 1.5f;
			bossIsActive = false;
			stageTransition = false;
			victoryTune.play();
			stage1End = true;
			this->backgroundScrollSpeed = 1.f;
			this->meteorSpawnRate = 0.f;

			if (!this->stageMusic.openFromFile("Music/empty.mp3"))
			{
				std::cout << "ERROR::EMPTY::FAILED_TO_LOAD" << "\n";
			}
			this->stageMusic.play();
		}

		if (elapsedTime >= timeStamp + 10.f && checkerThree && stage1End)
		{
			this->healthItemSpawnRate = 0.f;
			this->dpsItemSpawnRate = 0.f;
			checkerThree = false;
			this->meteorSpawnRate = 0.f;

		}

		if (elapsedTime >= timeStamp + 13.f && checkerTwo && stage1End)
		{
			this->triggerFadeEffect();
			checkerTwo = false;
			this->meteorSpawnRate = 0.f;
			
		}

		if (elapsedTime >= timeStamp + 14.f && stage1End && checkerFour)
		{
			this->backgroundScrollSpeed = 75.f;
			this->meteorSpawnRate = 0.f;

		}

		if (elapsedTime >= timeStamp + 15.f && stage1End && checkerFour)
		{
			this->stageBackground.setTexture(this->stage2BackgroundTexture);
			this->stageBackground2.setTexture(this->stage2BackgroundTexture);
			this->stageBackground2.setPosition(0, this->stageBackground.getGlobalBounds().height);
			this->checkerFour = false;

		}

		if (elapsedTime >= timeStamp + 16.f && stage1End)
		{
			this->backgroundScrollSpeed = 1.5f;
			timeStamp2 = elapsedTime;
			stage1End = false;
			this->meteorSpawnRate = 0.f;
			this->boss = new Boss(300.f, 10.5f, 2);
			bossDefeated = false;
			Stage = 2;
	


		}

		
	}

	if(Stage == 2)
	{
		this->backgroundScrollSpeed = 1.5f;
		if(elapsedTime >= timeStamp2 + 1.f  && elapsedTime <= timeStamp2 + 2.f)
		{
			checkerOne = true;
			checkerTwo = true;
			checkerThree = true;
			checkerFour = true;
			checkerFive = true;
			this->healthItemSpawnRate = 0.0167f;
			this->enemySpawnRate = 0.f;
			this->horizontalEnemySpawnRate = 0.f;
			this->meteorSpawnRate = 0.f;
			this->doubleMeteorChance = 0.f;
			this->tripleMeteorChance = 0.f;
			this->dpsItemSpawnRate = 0.075f;
		}

		if(elapsedTime >= timeStamp2 + 7.f && checkerOne)
		{
			
			this->enemySpawnRate = 1.5f;
			if (!this->stageMusic.openFromFile("Music/WithoutFear.ogg"))
			{
				std::cout << "ERROR::EMPTY::FAILED_TO_LOAD" << "\n";
			}
			this->stageMusic.play();
			checkerOne = false;
			this->meteorSpawnRate = 0.25f;
			this->doubleMeteorChance = 25.f;
			this->tripleMeteorChance = 5.f;
		}

		if (elapsedTime >= timeStamp2 + 37.f && elapsedTime <= timeStamp2 + 38.f)
		{
	
			this->horizontalEnemySpawnRate = 0.3f;
			this->meteorSpawnRate = 0.75f;
		}

		if (elapsedTime >= timeStamp2 + 55.f && checkerTwo)
		{
			this->doubleMeteorChance = 25.f;
			this->horizontalEnemySpawnRate = 0.6f;
			checkerTwo = false;
		}

		if (elapsedTime >= timeStamp2 + 107.f && elapsedTime <= timeStamp2 + 108.f)
		{
			this->meteorSpawnRate = 0.f;
			this->horizontalEnemySpawnRate = 0.f;
			this->enemySpawnRate = 0.f;
			this->dpsItemSpawnRate = 0.f;

		}

		if (elapsedTime >= timeStamp2 + 112.f && checkerThree)
		{
			if (!bossIsActive) {
				if (!this->stageMusic.openFromFile("Music/BossMusic2.ogg"))
				{
					std::cout << "ERROR::BOSSMUSIC::FAILED_TO_LOAD" << "\n";
				}
				this->stageMusic.play();

				bossIsActive = true;
				this->meteorSpawnRate = 0.f;
				this->doubleMeteorChance = 0.f;
				this->tripleMeteorChance = 0.f;

				this->boss->spawn(sf::Vector2f(560.f, 1000.f), sf::Vector2f(400.f, 600.f));
			}
			this->backgroundScrollSpeed = 3.0f;
			this->checkerThree = false;
		}

		if(bossIsActive && this->boss->getHp() <= 290 && !stageTransition)
		{
			this->deathBeamSpawnRate = 0.12f;
			this->horizontalEnemySpawnRate = 0.1f;
		}

		if(bossIsActive && this->boss->getHp() <= 200 && !stageTransition)
		{
			this->horizontalEnemySpawnRate = 0.25f;
		}

		if(bossIsActive && this->boss->getHp() <= 50 && !stageTransition)
		{
			this->horizontalEnemySpawnRate = 0.5f;
		}

		if (bossDefeated && checkerFour)
		{
			this->stageMusic.stop();
			this->explosionSound.play();
			this->meteorSpawnRate = 0.f;
			this->horizontalEnemySpawnRate = 0.f;
			this->deathBeamSpawnRate = 0.f;
			this->timeStamp = elapsedTime;
			this->stageTransition = true;
			bossDefeated = false;
			this->points = points + 100000;
			this->gameData.coins = gameData.coins + 1500;
			this->enemyKillCounter = enemyKillCounter + 80;
			checkerFour = false;
			this->backgroundScrollSpeed = 2.0f;

		}

		if (elapsedTime >= timeStamp + 5.f && stageTransition)
		{
			this->healthItemSpawnRate = 1.f;
			this->dpsItemSpawnRate = 3.f;
			bossIsActive = false;
			stageTransition = false;
			victoryTune.play();
			stage2End = true;
			this->backgroundScrollSpeed = 1.f;
			this->meteorSpawnRate = 0.f;

			if (!this->stageMusic.openFromFile("Music/empty.mp3"))
			{
				std::cout << "ERROR::EMPTY::FAILED_TO_LOAD" << "\n";
			}
			this->stageMusic.play();
		}

		if (elapsedTime >= timeStamp + 10.f && checkerFive && stage2End)
		{
			this->healthItemSpawnRate = 0.f;
			this->dpsItemSpawnRate = 0.f;
			checkerFive = false;
			this->meteorSpawnRate = 0.f;

		}

		if (elapsedTime >= timeStamp + 13.f && checkerSix && stage2End)
		{
			this->triggerFadeEffect();
			checkerSix = false;
			this->meteorSpawnRate = 0.f;

		}

		if (elapsedTime >= timeStamp + 14.f && stage2End && checkerSeven)
		{
			this->backgroundScrollSpeed = 75.f;
			this->meteorSpawnRate = 0.f;

		}

		if (elapsedTime >= timeStamp + 15.f && stage2End && checkerSeven)
		{
			this->stageBackground.setTexture(this->stage2BackgroundTexture);
			this->stageBackground2.setTexture(this->stage2BackgroundTexture);
			this->stageBackground2.setPosition(0, this->stageBackground.getGlobalBounds().height);
			this->checkerFour = false;

		}

		if (elapsedTime >= timeStamp + 16.f && stage2End)
		{
			this->backgroundScrollSpeed = 1.5f;
			timeStamp2 = elapsedTime;
			stage2End = false;
			this->meteorSpawnRate = 0.f;
			Stage = 3;



		}


	}
}

//if (elapsedTime >= 110.f && elapsedTime <= 111.f)
//{
//	if (!bossIsActive) {
//		if (!this->stageMusic.openFromFile("Music/BossMusic.ogg"))
//		{
//			std::cout << "ERROR::BOSSMUSIC::FAILED_TO_LOAD" << "\n";
//		}
//		this->stageMusic.play();
//
//		bossIsActive = true;
//		this->boss->spawn(sf::Vector2f(560.f, -200.f), sf::Vector2f(600.f, 300.f));
//	}
//}