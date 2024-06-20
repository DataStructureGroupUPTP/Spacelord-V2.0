#include "Game.h"

void Game::handleMainMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (this->selectedMenuItem > 0)
		{
			this->menuSound.play();
			this->selectedMenuItem--;
		}
	}
	if (ev.key.code == sf::Keyboard::Down)
	{
		if (this->selectedMenuItem < 4)
		{
			this->menuSound.play();
			this->selectedMenuItem++;
		}
	}
	if (ev.key.code == sf::Keyboard::Return)
	{
		switch (this->selectedMenuItem)
		{
		case 0:
			this->initializeMusic();
			this->gameState = GAMEPLAY;
			this->menuMusic.stop();
			break;
		case 1:
			// Handle shop selection
			break;
		case 2:
			this->prevgameState = this->gameState;
			this->gameState = SETTINGS;
			break;
		case 3:
			// Handle credits selection
			break;
		case 4:
			this->window->close();
			break;
		default:
			break;
		}
	}
}

void Game::handlePauseMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (this->selectedMenuItem > 0)
		{
			this->menuSound.play();
			this->selectedMenuItem--;
		}
	}
	if (ev.key.code == sf::Keyboard::Down)
	{
		if (this->selectedMenuItem < 2)
		{
			this->menuSound.play();
			this->selectedMenuItem++;
		}
	}
	if (ev.key.code == sf::Keyboard::Return)
	{
		switch (this->selectedMenuItem)
		{
		case 0:
			this->gameState = GAMEPLAY;
			this->menuMusic.stop();
			this->stageMusic.play();
			break;
		case 1:
			this->prevgameState = this->gameState;
			this->gameState = SETTINGS;
			break;
		case 2:
			this->reset();
			this->gameState = MAIN_MENU;
			this->stageMusic.stop();
			this->menuMusic.play();
			break;
		default:
			break;
		}
	}
}

void Game::handleGameOverMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Return)
	{
		this->reset();
		this->gameState = MAIN_MENU;
		this->menuMusic.play();
		this->gameOverMusic.stop();
	}
}

void Game::handleSettingsMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (this->selectedMenuItem > 0)
		{
			this->menuSound.play();
			this->selectedMenuItem--;
		}
	}
	if (ev.key.code == sf::Keyboard::Down)
	{
		if (this->selectedMenuItem < 2)
		{
			this->menuSound.play();
			this->selectedMenuItem++;
		}
	}
	switch (this->selectedMenuItem)
	{
	case 0:
		if (ev.key.code == sf::Keyboard::Left)
		{
			musicVolume = std::max(musicVolume - 0.5f, 0.0f);
			updateMusicVolume();
		}
		if (ev.key.code == sf::Keyboard::Right)
		{
			musicVolume = std::min(musicVolume + 0.5f, 10.0f);
			updateMusicVolume();
		}
		break;
	case 1:
		if (ev.key.code == sf::Keyboard::Left)
		{
			soundfxVolume = std::max(soundfxVolume - 0.5f, 0.0f);
			updateSoundFXVolume();
		}
		if (ev.key.code == sf::Keyboard::Right)
		{
			soundfxVolume = std::min(soundfxVolume + 0.5f, 10.0f);
			updateSoundFXVolume();
		}
		break;
	case 2:
		if (ev.key.code == sf::Keyboard::Return)
		{
			this->gameState = this->prevgameState;
			if (this->prevgameState == GAMEPLAY)
			{
				this->stageMusic.play();
			}
		}
		break;
	default:
		break;
	}
}