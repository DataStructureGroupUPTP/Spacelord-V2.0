#include "Game.h"

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->coinText);
	this->window->draw(this->killCounterText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	this->window->draw(this->timerText);
	this->window->draw(this->bombsText);
}

void Game::renderWorld()
{

	this->window->draw(this->stageBackground);
	this->window->draw(this->stageBackground2);
}

void Game::renderGameElements()
{
	// Draw game elements
	this->window->draw(this->line1, 2, sf::Lines);
	this->window->draw(this->line2, 2, sf::Lines);
	this->window->draw(this->line3, 2, sf::Lines);
	this->window->draw(this->line4, 2, sf::Lines);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(*this->window);
	}

	for (auto* item : this->items)
	{
		item->render(*this->window);
	}

	this->player->render(*this->window);
	this->renderGUI();
}

void Game::renderExplosion(sf::RenderTarget& target)
{
	for (size_t i = 0; i < this->explosions.size(); ++i) {
		this->explosions[i]->render(target);
	}
}

void Game::renderStartMenu()
{
	this->window->draw(this->startMenuBackground);

	// Reset the color of all menu items
	this->playText.setFillColor(sf::Color::White);
	this->shopText.setFillColor(sf::Color::White);
	this->settingsText.setFillColor(sf::Color::White);
	this->creditsText.setFillColor(sf::Color::White);
	this->quitText.setFillColor(sf::Color::White);
	this->resetText.setFillColor(sf::Color::White);

	// Highlight the selected menu item
	switch (this->selectedMenuItem)
	{
	case 0:
		this->playText.setFillColor(sf::Color::Yellow);
		break;

	case 1:
		this->shopText.setFillColor(sf::Color::Yellow);
		break;

	case 2:
		this->settingsText.setFillColor(sf::Color::Yellow);
		break;

	case 3:
		this->creditsText.setFillColor(sf::Color::Yellow);
		break;
	case 4:
		this->resetText.setFillColor(sf::Color::Yellow);
		break;
	case 5:
		this->quitText.setFillColor(sf::Color::Yellow);
		break;
	}

	// Draw menu items
	this->window->draw(this->resetText);
	this->window->draw(this->gameTitle);
	this->window->draw(this->playText);
	this->window->draw(this->shopText);
	this->window->draw(this->settingsText);
	this->window->draw(this->creditsText);
	this->window->draw(this->quitText);
}

void Game::renderShopMenu()
{
	this->window->draw(this->startMenuBackground);
	this->window->draw(this->pausesettingsBackground);
	this->window->draw(this->shopTitle);
	std::stringstream ss2;
	ss2 << "Money: " << this->gameData.coins << "$";
	this->coinAmount.setString(ss2.str());
	this->window->draw(this->coinAmount);
	this->returnfromshopText.setFillColor(sf::Color::White);
	this->redbulletSelect.setOutlineColor(sf::Color::White);
	this->bluebulletSelect.setOutlineColor(sf::Color::White);
	this->greenbulletSelect.setOutlineColor(sf::Color::White);
	this->yellowbulletSelect.setOutlineColor(sf::Color::White);
	this->purplebulletSelect.setOutlineColor(sf::Color::White);
	this->whitebulletSelect.setOutlineColor(sf::Color::White);
	this->normalshipSelect.setOutlineColor(sf::Color::White);
	this->greenshipSelect.setOutlineColor(sf::Color::White);
	this->blueshipSelect.setOutlineColor(sf::Color::White);
	this->yellowshipSelect.setOutlineColor(sf::Color::White);
	this->purpleshipSelect.setOutlineColor(sf::Color::White);
	this->redshipSelect.setOutlineColor(sf::Color::White);
	this->normalfireSelect.setOutlineColor(sf::Color::White);
	this->yellowfireSelect.setOutlineColor(sf::Color::White);
	this->greenfireSelect.setOutlineColor(sf::Color::White);
	this->blackshipSelect.setOutlineColor(sf::Color::White);
	this->blackbulletSelect.setOutlineColor(sf::Color::White);
	this->whitefireSelect.setOutlineColor(sf::Color::White);
	renderEquiped();

	switch (this->selectedMenuItem)
	{
	case 0:
		switch (this->shopselectedMenuItem)
		{
		case 0:
			this->redbulletSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Acquired");
			break;
		case 1:
			this->bluebulletSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 5000$");
			if (gameData.bluebullet == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 2:
			this->greenbulletSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 5000$");
			if (gameData.greenbullet == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 3:
			this->yellowbulletSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 5000$");
			if (gameData.yellowbullet == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 4:
			this->purplebulletSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 5000$");
			if (gameData.purplebullet == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 5:
			this->whitebulletSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 5000$");
			if (gameData.whitebullet == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		}
		break;
	case 1:
		switch (this->shopselectedMenuItem)
		{
		case 0:
			this->normalshipSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Acquired");
			break;
		case 1:
			this->blueshipSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 10000$");
			if (gameData.blueship == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 2:
			this->greenshipSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 10000$");
			if (gameData.greenship == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 3:
			this->yellowshipSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 10000$");
			if (gameData.yellowship == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 4:
			this->purpleshipSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 10000$");
			if (gameData.purpleship == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 5:
			this->redshipSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 10000$");
			if (gameData.redship == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		}
		break;
	case 2:
		switch (this->shopselectedMenuItem)
		{
		case 0:
			this->normalfireSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Acquired");
			break;
		case 1:
			this->yellowfireSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 5000$");
			if (gameData.yellowfire == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 2:
			this->greenfireSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Price: 5000$");
			if (gameData.greenfire == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 3:
			this->blackshipSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Reach a Score of 500000");
			if (gameData.blackship == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 4:
			this->blackbulletSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Reach a Score of 500000");
			if (gameData.blackbullet == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		case 5:
			this->whitefireSelect.setOutlineColor(sf::Color::Yellow);
			this->objectPrice.setString("Reach a Score of 500000");
			if (gameData.whitefire == "ACQUIRED")
			{
				this->objectPrice.setString("Acquired");
			}
			break;
		}
		break;
	case 3:
		this->returnfromshopText.setFillColor(sf::Color::Yellow);
		break;
	}
	this->objectPrice.setPosition(
		this->window->getSize().x / 2.f - this->objectPrice.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->objectPrice.getGlobalBounds().height / 2.f - 250.f
	);
	this->window->draw(this->objectPrice);
	this->window->draw(this->redbulletSelect);
	this->window->draw(this->bluebulletSelect);
	this->window->draw(this->greenbulletSelect);
	this->window->draw(this->yellowbulletSelect);
	this->window->draw(this->purplebulletSelect);
	this->window->draw(this->whitebulletSelect);
	this->window->draw(this->normalshipSelect);
	this->window->draw(this->greenshipSelect);
	this->window->draw(this->blueshipSelect);
	this->window->draw(this->yellowshipSelect);
	this->window->draw(this->purpleshipSelect);
	this->window->draw(this->redshipSelect);
	this->window->draw(this->normalfireSelect);
	this->window->draw(this->yellowfireSelect);
	this->window->draw(this->greenfireSelect);
	this->window->draw(this->blackshipSelect);
	this->window->draw(this->blackbulletSelect);
	this->window->draw(this->whitefireSelect);
	this->window->draw(this->returnfromshopText);
}

void Game::renderEquiped()
{
	if (gameData.equipedbullet == "red")
	{
		this->redbulletSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedbullet == "blue")
	{
		this->bluebulletSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedbullet == "green")
	{
		this->greenbulletSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedbullet == "yellow")
	{
		this->yellowbulletSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedbullet == "purple")
	{
		this->purplebulletSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedbullet == "white")
	{
		this->whitebulletSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedbullet == "black")
	{
		this->blackbulletSelect.setOutlineColor(sf::Color::Green);
	}

	if (gameData.equipedship == 0)
	{
		this->normalshipSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedship == 1)
	{
		this->blueshipSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedship == 2)
	{
		this->greenshipSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedship == 3)
	{
		this->yellowshipSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedship == 4)
	{
		this->purpleshipSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedship == 5)
	{
		this->redshipSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedship == 6)
	{
		this->blackshipSelect.setOutlineColor(sf::Color::Green);
	}

	if (gameData.equipedfire == 0)
	{
		this->normalfireSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedfire == 1)
	{
		this->yellowfireSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedfire == 2)
	{
		this->greenfireSelect.setOutlineColor(sf::Color::Green);
	}
	else if (gameData.equipedfire == 3)
	{
		this->whitefireSelect.setOutlineColor(sf::Color::Green);
	}
}

void Game::renderPauseMenu()
{
	this->window->draw(this->pausesettingsBackground);
	// Reset the color of all menu items
	this->resumeText.setFillColor(sf::Color::White);
	this->pausesettingsText.setFillColor(sf::Color::White);
	this->mainmenuText.setFillColor(sf::Color::White);

	// Highlight the selected menu item
	switch (this->selectedMenuItem)
	{
	case 0:
		this->resumeText.setFillColor(sf::Color::Yellow);
		break;

	case 1:
		this->pausesettingsText.setFillColor(sf::Color::Yellow);
		break;

	case 2:
		this->mainmenuText.setFillColor(sf::Color::Yellow);
		break;
	}

	// Draw menu items
	this->window->draw(this->pauseTitle);
	this->window->draw(this->resumeText);
	this->window->draw(this->pausesettingsText);
	this->window->draw(this->mainmenuText);
}

void Game::renderGameOverMenu()
{
	this->mainmenuText.setFillColor(sf::Color::Yellow);

	this->window->draw(this->gameOverBackground);
	this->window->draw(this->gameOverText);
	this->window->draw(this->mainmenuText);
}

void Game::renderSettingsMenu()
{
	this->window->draw(this->pausesettingsBackground);
	this->musicvolumeText.setFillColor(sf::Color::White);
	this->soundfxText.setFillColor(sf::Color::White);
	this->backText.setFillColor(sf::Color::White);
	this->musicvolumeBorder.setOutlineColor(sf::Color::White);
	this->musicvolumeIndicator.setFillColor(sf::Color(255, 255, 255, 75));
	this->soundfxvolumeBorder.setOutlineColor(sf::Color::White);
	this->soundfxvolumeIndicator.setFillColor(sf::Color(255, 255, 255, 75));

	// Highlight the selected menu item
	switch (this->selectedMenuItem)
	{
	case 0:
		this->musicvolumeText.setFillColor(sf::Color::Yellow);
		this->musicvolumeBorder.setOutlineColor(sf::Color::Yellow);
		this->musicvolumeIndicator.setFillColor(sf::Color(255, 255, 0, 75));
		break;

	case 1:
		this->soundfxText.setFillColor(sf::Color::Yellow);
		this->soundfxvolumeBorder.setOutlineColor(sf::Color::Yellow);
		this->soundfxvolumeIndicator.setFillColor(sf::Color(255, 255, 0, 75));
		break;
	case 2:
		this->backText.setFillColor(sf::Color::Yellow);
		break;
	}

	// Draw menu items
	this->window->draw(this->settingsTitle);
	this->window->draw(this->musicvolumeText);
	this->window->draw(this->musicvolumeBorder);
	this->window->draw(this->musicvolumeIndicator);
	this->window->draw(this->soundfxText);
	this->window->draw(this->soundfxvolumeBorder);
	this->window->draw(this->soundfxvolumeIndicator);
	this->window->draw(this->backText);
}
