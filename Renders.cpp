#include "Game.h"

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{

	this->window->draw(this->stageBackground);
	this->window->draw(this->stageBackground2);
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
	this->musicvolumeText.setFillColor(sf::Color::White);
	this->soundfxText.setFillColor(sf::Color::White);
	this->backText.setFillColor(sf::Color::White);

	// Highlight the selected menu item
	switch (this->selectedMenuItem)
	{
	case 0:
		this->musicvolumeText.setFillColor(sf::Color::Yellow);
		break;

	case 1:
		this->soundfxText.setFillColor(sf::Color::Yellow);
		break;

	case 2:
		this->backText.setFillColor(sf::Color::Yellow);
		break;
	}

	// Draw menu items
	this->window->draw(this->settingsTitle);
	this->window->draw(this->musicvolumeText);
	this->window->draw(this->soundfxText);
	this->window->draw(this->backText);
}
