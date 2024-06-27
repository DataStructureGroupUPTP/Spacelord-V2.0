#include "Game.h"

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->currencyText);
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
		this->quitText.setFillColor(sf::Color::Yellow);
		break;
	}

	// Draw menu items
	this->window->draw(this->gameTitle);
	this->window->draw(this->playText);
	this->window->draw(this->shopText);
	this->window->draw(this->settingsText);
	this->window->draw(this->creditsText);
	this->window->draw(this->quitText);
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
