#include "Game.h"

void Game::initializeLines()
{
	
	this->lane = 4;
	this->rightKeyPressed = false;
	this->leftKeyPressed = false;
	this->laneRandomizer = 1;
	this->lanePos = 200;

	this->line1Pos = 200;
	this->line2Pos = 400;
	this->line3Pos = 600;
	this->line4Pos = 800;

	this->line1[0] = sf::Vertex(sf::Vector2f(200, 0), sf::Color::White);
	this->line1[1] = sf::Vertex(sf::Vector2f(200, 1000), sf::Color::White);

	this->line2[0] = sf::Vertex(sf::Vector2f(400, 0), sf::Color::White);
	this->line2[1] = sf::Vertex(sf::Vector2f(400, 1000), sf::Color::White);

	this->line3[0] = sf::Vertex(sf::Vector2f(600, 0), sf::Color::White);
	this->line3[1] = sf::Vertex(sf::Vector2f(600, 1000), sf::Color::White);

	this->line4[0] = sf::Vertex(sf::Vector2f(800, 0), sf::Color::White);
	this->line4[1] = sf::Vertex(sf::Vector2f(800, 1000), sf::Color::White);
}

void Game::initializeTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/Redbulletrfix.png"))
	{
		std::cout << "TEXTURE::BULLET::FAILED_TO_LOAD" << "\n";
	}

	this->textures["GREENALIEN"] = new sf::Texture();
	if (!this->textures["GREENALIEN"]->loadFromFile("Textures/Greenalienfix.png"))
	{
		std::cout << "TEXTURE::GREEN_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BLUEALIEN"] = new sf::Texture();
	if (!this->textures["BLUEALIEN"]->loadFromFile("Textures/Bluealienfix.png"))
	{
		std::cout << "TEXTURE::BLUE_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["YELLOWALIEN"] = new sf::Texture();
	if (!this->textures["YELLOWALIEN"]->loadFromFile("Textures/Yellowalienfix.png"))
	{
		std::cout << "TEXTURE::YELLOW_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["HEALTH"] = new sf::Texture();
	if (!this->textures["HEALTH"]->loadFromFile("Textures/Heart.png"))
	{
		std::cout << "TEXTURE::HEART::FAILED_TO_LOAD" << "\n";
	}

	this->textures["REDBALL"] = new sf::Texture();
	if(!this->textures["REDBALL"]->loadFromFile("Textures/Ball1.png"))
	{
		std::cout << "TEXTURE::BALL1::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BLUEBALL"] = new sf::Texture();
	if (!this->textures["BLUEBALL"]->loadFromFile("Textures/Ball2.png"))
	{
		std::cout << "TEXTURE::BALL2::FAILED_TO_LOAD" << "\n";
	}

	this->textures["YELLOWBALL"] = new sf::Texture();
	if (!this->textures["YELLOWBALL"]->loadFromFile("Textures/Ball3.png"))
	{
		std::cout << "TEXTURE::BALL3::FAILED_TO_LOAD" << "\n";
	}

	this->textures["PURPLEBALL"] = new sf::Texture();
	if (!this->textures["PURPLEBALL"]->loadFromFile("Textures/Ball4.png"))
	{
		std::cout << "TEXTURE::BALL4::FAILED_TO_LOAD" << "\n";
	}

	this->textures["METEOR"] = new sf::Texture();
	if (!this->textures["METEOR"]->loadFromFile("Textures/Meteor.png"))
	{
		std::cout << "TEXTURE::METEOR::FAILED_TO_LOAD" << "\n";
	}

	this->textures["SMALLENEMY"] = new sf::Texture();
	if (!this->textures["SMALLENEMY"]->loadFromFile("Textures/Smallenemyf1.png"))
	{
		std::cout << "TEXTURE::SMALL_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["MEDIUMENEMY"] = new sf::Texture();
	if (!this->textures["MEDIUMENEMY"]->loadFromFile("Textures/Mediumenemyf1.png"))
	{
		std::cout << "TEXTURE::MEDIUM_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BIGENEMY"] = new sf::Texture();
	if (!this->textures["BIGENEMY"]->loadFromFile("Textures/Bigenemyf1.png"))
	{
		std::cout << "TEXTURE::BIG_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BOSSBULLET"] = new sf::Texture();
	if (!this->textures["BOSSBULLET"]->loadFromFile("Textures/Bossbullet.png"))
	{
		std::cout << "TEXTURE::BOSS_BULLET::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY1"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY1"]->loadFromFile("Textures/Stage2e1.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY1::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY2"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY2"]->loadFromFile("Textures/Stage2e2.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY2::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY3"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY3"]->loadFromFile("Textures/Stage2e3.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY3::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY4"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY4"]->loadFromFile("Textures/Stage2e4.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY4::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY5"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY5"]->loadFromFile("Textures/Stage2e5.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY5::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY6"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY6"]->loadFromFile("Textures/Stage2e6.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY6::FAILED_TO_LOAD" << "\n";
	}
}

void Game::initializeSounds()
{
	this->soundfxVolume = 5.f;
	this->musicVolume = 5.f;

	if (!this->laserBuffer.loadFromFile("Sounds/Shiplaser.wav"))
	{
		std::cout << "SOUND::SHIPLASER::FAILED_TO_LOAD" << "\n";
	}
	this->laserSound.setBuffer(this->laserBuffer);

	if (!this->menuClick.loadFromFile("Sounds/Menu.wav"))
	{
		std::cout << "SOUND::MENU::FAILED_TO_LOAD" << "\n";
	}

	this->menuSound.setBuffer(this->menuClick);

	if (!this->playerHitBuffer.loadFromFile("Sounds/Playerhit.flac"))
	{
		std::cout << "SOUND::PLAYER_HIT::FAILED_TO_LOAD" << "\n";
	}

	this->playerHit.setBuffer(this->playerHitBuffer);

	if (!this->alienHitBuffer.loadFromFile("Sounds/Enemyhit.wav"))
	{
		std::cout << "SOUND::ALIEN_HIT::FAILED_TO_LOAD" << "\n";
	}

	this->alienHit.setBuffer(this->alienHitBuffer);

	if (!this->pauseBuffer.loadFromFile("Sounds/PauseSound.wav"))
	{
		std::cout << "SOUND::MENU::PAUSE::FAILED_TO_LOAD" << "\n";
	}

	this->pauseSound.setBuffer(this->pauseBuffer);

	if(!this->healBuffer.loadFromFile("Sounds/heal.wav"))
	{
		std::cout << "SOUND::HEAL::FAILED_TO_LOAD";
	}

	this->healSound.setBuffer(this->healBuffer);

	if(!this->powerUpBuffer.loadFromFile("Sounds/Powerup1.wav"))
	{
		std::cout << "SOUND::POWERUP1::FAILED_TO_LOAD";
	}

	this->powerUpSound.setBuffer(this->powerUpBuffer);

	if (!this->swooshBuffer.loadFromFile("Sounds/Swoosh.mp3"))
	{
		std::cout << "SOUND::SWOOSH::FAILED_TO_LOAD";
	}

	this->swooshSound.setBuffer(this->swooshBuffer);

	if (!this->clangBuffer.loadFromFile("Sounds/Bosshit.wav"))
	{
		std::cout << "SOUND::BOSS_HIT::FAILED_TO_LOAD";
	}

	this->clangHit.setBuffer(this->clangBuffer);

	if (!this->criticalBuffer.loadFromFile("Sounds/CriticalHit.wav"))
	{
		std::cout << "SOUND::CRITICAL_HIT::FAILED_TO_LOAD";
	}

	this->criticalHit.setBuffer(this->criticalBuffer);

	if (!this->explosionBuffer.loadFromFile("Sounds/ExplosionEnd.mp3"))
	{
		std::cout << "SOUND::EXPLOSION::FAILED_TO_LOAD";
	}

	this->explosionSound.setBuffer(this->explosionBuffer);

	if (!this->bossLaserBuffer.loadFromFile("Sounds/Bosslaser.mp3"))
	{
		std::cout << "SOUND::BOSS_LASER::FAILED_TO_LOAD";
	}

	this->bossLaser.setBuffer(this->bossLaserBuffer);

	if (!this->shieldBuffer.loadFromFile("Sounds/ShieldSound.wav"))
	{
		std::cout << "SOUND::SHIELD::FAILED_TO_LOAD";
	}

	this->shield.setBuffer(this->shieldBuffer);

	if (!this->levelUpBuffer.loadFromFile("Sounds/killPower.wav"))
	{
		std::cout << "SOUND::KILL_LEVEL_UP::FAILED_TO_LOAD";
	}

	this->levelup.setBuffer(this->levelUpBuffer);
}

void Game::initializeSoundFXVolume()
{
	this->laserSound.setVolume(this->soundfxVolume * 3.0f); // 12.5
	this->levelup.setVolume(this->soundfxVolume * 25);
	this->shield.setVolume(this->soundfxVolume * 50);
	this->bossLaser.setVolume(this->soundfxVolume * 3);
	this->explosionSound.setVolume(this->soundfxVolume * 15);
	this->criticalHit.setVolume(this->soundfxVolume * 15);
	this->clangHit.setVolume(this->soundfxVolume * 15);
	this->healSound.setVolume(this->soundfxVolume * 5);
	this->powerUpSound.setVolume(this->soundfxVolume * 5);
	this->swooshSound.setVolume(this->soundfxVolume * 50);
	this->pauseSound.setVolume(this->soundfxVolume * 10); // 50
	this->alienHit.setVolume(this->soundfxVolume * 6); // 30
	this->playerHit.setVolume(this->soundfxVolume * 7); // 35
	this->menuSound.setVolume(this->soundfxVolume * 10); // 50
}

void Game::initializeMusic()
{
	if (!this->stageMusic.openFromFile("Music/BattleInTheStars.ogg"))
	{
		std::cout << "ERROR::BATTLEINTHESTARS::FAILED_TO_LOAD" << "\n";
	}

	// Play the music
	this->stageMusic.play();

	if (!this->gameOverMusic.openFromFile("Music/Yellow.mp3"))
	{
		std::cout << "ERROR::YELLOW_GAME_OVER_THEME::FAILED_TO_LOAD" << "\n";
	}

	if (!this->victoryTune.openFromFile("Music/Victory.ogg"))
	{
		std::cout << "ERROR::VICTORY_THEME::FAILED_TO_LOAD" << "\n";
	}

}

void Game::initializeMusicVolume()
{
	this->stageMusic.setVolume(this->musicVolume * 6); // 30
	this->gameOverMusic.setVolume(this->musicVolume * 6); // 30
	this->victoryTune.setVolume(this->musicVolume * 6); // 30
	this->menuMusic.setVolume(this->musicVolume * 6); // 30
}

void Game::initializeGUI()
{
	// Load Fonts
	if (!this->font.loadFromFile("Fonts/Pixellettersfull.ttf"))
	{
		std::cout << "FONT::PIXELLETTERSFULL::FAILED_TO_LOAD" << "\n";
	}

	if (!this->titleFont.loadFromFile("Fonts/Debrosee.ttf"))
	{
		std::cout << "FONT::DEBROSEE::FAILED_TO_LOAD" << "\n";
	}

	//Initialize point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("ERROR");

	//Initialize point text
	this->coinText.setFont(this->font);
	this->coinText.setCharacterSize(36);
	this->coinText.setFillColor(sf::Color::White);
	this->coinText.setString("ERROR");
	this->coinText.setPosition(0.f, 750.f);

	// Initialize kill counter text
	this->killCounterText.setFont(this->font);
	this->killCounterText.setCharacterSize(36);
	this->killCounterText.setFillColor(sf::Color::White);
	this->killCounterText.setString("ERROR");
	this->killCounterText.setPosition(0.f, 720.f);

	// Initialize kill counter text
	this->bombsText.setFont(this->font);
	this->bombsText.setCharacterSize(36);
	this->bombsText.setFillColor(sf::Color::White);
	this->bombsText.setString("ERROR");
	this->bombsText.setPosition(0.f, 80.f);

	// Initialize game title
	this->gameTitle.setFont(this->titleFont);
	this->gameTitle.setCharacterSize(100);
	this->gameTitle.setFillColor(sf::Color::White);
	this->gameTitle.setStyle(sf::Text::Italic);
	this->gameTitle.setOutlineThickness(1);
	this->gameTitle.setString("ASTRAL ATTACK");

	// Initialize Pause title
	this->pauseTitle.setFont(this->titleFont);
	this->pauseTitle.setCharacterSize(100);
	this->pauseTitle.setFillColor(sf::Color::White);
	this->pauseTitle.setStyle(sf::Text::Italic);
	this->pauseTitle.setOutlineThickness(1);
	this->pauseTitle.setString("PAUSED");

	// Initialize Shop title
	this->shopTitle.setFont(this->titleFont);
	this->shopTitle.setCharacterSize(100);
	this->shopTitle.setFillColor(sf::Color::White);
	this->shopTitle.setStyle(sf::Text::Italic);
	this->shopTitle.setOutlineThickness(1);
	this->shopTitle.setString("SHOP");

	// Initialize Settings title
	this->settingsTitle.setFont(this->titleFont);
	this->settingsTitle.setCharacterSize(100);
	this->settingsTitle.setFillColor(sf::Color::White);
	this->settingsTitle.setStyle(sf::Text::Italic);
	this->settingsTitle.setOutlineThickness(1);
	this->settingsTitle.setString("SETTINGS");

	// Initialize game over title
	this->gameOverText.setFont(this->titleFont);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setStyle(sf::Text::Italic);
	this->gameOverText.setOutlineThickness(1);
	this->gameOverText.setString("GAME OVER");

	// Initialize health bar
	this->playerHpBar.setSize(sf::Vector2f(150.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 60.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	// Initialize timer
	this->timerText.setFont(this->font);
	this->timerText.setCharacterSize(36);
	this->timerText.setFillColor(sf::Color::White);
	timerText.setPosition(this->window->getSize().x - 75.f, 0.f);
	this->elapsedTime = 0.f;
	this->clock.restart();
	this->minutes = 0;
	this->seconds = 0;
}

void Game::initializeBackground()
{
	if (!this->stageBackgroundTexture.loadFromFile("Textures/Space1.png"))
	{
		std::cout << "TEXTURE::SPACE1::FAILED_TO_LOAD" << "\n";
	}

	if (!this->stage2BackgroundTexture.loadFromFile("Textures/Space4.png"))
	{
		std::cout << "TEXTURE::SPACE2::FAILED_TO_LOAD" << "\n";
	}

	this->stageBackground.setTexture(this->stageBackgroundTexture);
	this->stageBackground2.setTexture(this->stageBackgroundTexture);

	this->stageBackground.setPosition(0, 0);

	this->stageBackground2.setPosition(0, this->stageBackground.getGlobalBounds().height);

	this->backgroundScrollSpeed = 1.f;

	int randomBackground = rand() % 5 + 1;

	switch (randomBackground)
	{
	case 1:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu3.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->startMenuBackground.setTexture(this->startMenuTexture);
		this->gameTitle.setOutlineColor(sf::Color(255, 165, 0));
		break;

	case 2:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu1.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Cyan);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 3:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu4.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Magenta);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 4:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu2.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Green);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 5:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu5.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Yellow);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	}

}

void Game::initializeSystems()
{
	this->bulletSpeed = 5.f;

	this->points = 0;

	this->enemyKillCounter = 0;
	this->bombs = 1;
	this->lastKillThreshold = 0;
}

void Game::initializeFadeEffects()
{
	fadeState = NONE;
	fadeAlpha = 0.f;
	fadeOverlay.setSize(sf::Vector2f(this->window->getSize()));
	fadeOverlay.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(fadeAlpha)));
}

void Game::initializeMenuBackgrounds()
{
	if (!this->gameOverBackgroundTexture.loadFromFile("Textures/GameOver.png"))
	{
		std::cout << "TEXTURE::GAME_OVER_BACKGROUND::FAILED_TO_LOAD" << "\n";
	}

	this->gameOverBackground.setTexture(this->gameOverBackgroundTexture);

}

void Game::initializeGameData()
{
	GameData readData = readFromFile();
	gameData.coins = readData.coins;
	gameData.highScore = readData.highScore;
	gameData.equipedbullet = readData.equipedbullet;
	gameData.redbullet = readData.redbullet;
	gameData.bluebullet = readData.bluebullet;
	gameData.greenbullet = readData.greenbullet;
}

void Game::initializeStartMenu()
{
	// Initialize music
	if (!this->menuMusic.openFromFile("Music/SkyFire.ogg"))
	{
		std::cout << "ERROR::SKYFIRE::FAILED_TO_LOAD" << "\n";
	}
	// Play the music
	this->menuMusic.play();


	// Initialize title
	this->gameTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->gameTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameTitle.getGlobalBounds().height / 2.f - 250.f
	);


	// Initialize Play menu item
	this->playText.setFont(this->font);
	this->playText.setCharacterSize(48);
	this->playText.setFillColor(sf::Color::White);
	this->playText.setString("Play");
	this->playText.setPosition(
		this->window->getSize().x / 2.f - this->playText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->playText.getGlobalBounds().height / 2.f - 100.f
	);

	// Initialize Shop menu item
	this->shopText.setFont(this->font);
	this->shopText.setCharacterSize(48);
	this->shopText.setFillColor(sf::Color::White);
	this->shopText.setString("Shop");
	this->shopText.setPosition(
		this->window->getSize().x / 2.f - this->shopText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->shopText.getGlobalBounds().height / 2.f - 50.f
	);

	// Initialize Settings menu item
	this->settingsText.setFont(this->font);
	this->settingsText.setCharacterSize(48);
	this->settingsText.setFillColor(sf::Color::White);
	this->settingsText.setString("Settings");
	this->settingsText.setPosition(
		this->window->getSize().x / 2.f - this->settingsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->settingsText.getGlobalBounds().height / 2.f
	);

	this->creditsText.setFont(this->font);
	this->creditsText.setCharacterSize(48);
	this->creditsText.setFillColor(sf::Color::White);
	this->creditsText.setString("Credits");
	this->creditsText.setPosition(
		this->window->getSize().x / 2.f - this->creditsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->creditsText.getGlobalBounds().height / 2.f + 50.f
	);

	// Initialize Reset menu item
	this->resetText.setFont(this->font);
	this->resetText.setCharacterSize(48);
	this->resetText.setFillColor(sf::Color::White);
	this->resetText.setString("Reset Progress & Purchases");
	this->resetText.setPosition(
		this->window->getSize().x / 2.f - this->resetText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->resetText.getGlobalBounds().height / 2.f + 100.f
	);

	// Initialize Quit menu item
	this->quitText.setFont(this->font);
	this->quitText.setCharacterSize(48);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setString("Quit");
	this->quitText.setPosition(
		this->window->getSize().x / 2.f - this->quitText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->quitText.getGlobalBounds().height / 2.f + 150.f
	);
}

void Game::initializeShopMenu()
{
	// Red Bullet Select
	if (!this->redbullet.loadFromFile("Textures/redbulletshop.png"))
	{
		std::cout << "TEXTURE::SHOP_REDBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->redbulletSelect.setTexture(&redbullet);
	this->redbulletSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->redbulletSelect.setOutlineThickness(-5.f);
	this->redbulletSelect.setPosition(
		this->window->getSize().x / 2.f - this->redbulletSelect.getGlobalBounds().width / 2.f - 375.f,
		this->window->getSize().y / 2.f - this->redbulletSelect.getGlobalBounds().height / 2.f - 85.f
	);

	// Blue Bullet select
	if (!this->bluebullet.loadFromFile("Textures/bluebulletshop.png"))
	{
		std::cout << "TEXTURE::SHOP_BLUEBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->bluebulletSelect.setTexture(&bluebullet);
	this->bluebulletSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->bluebulletSelect.setOutlineThickness(-5.f);
	this->bluebulletSelect.setPosition(
		this->window->getSize().x / 2.f - this->bluebulletSelect.getGlobalBounds().width / 2.f - 225,
		this->window->getSize().y / 2.f - this->bluebulletSelect.getGlobalBounds().height / 2.f - 85.f
	);

	// Green Bullet select
	if (!this->greenbullet.loadFromFile("Textures/greenbulletshop.png"))
	{
		std::cout << "TEXTURE::SHOP_GREENBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->greenbulletSelect.setTexture(&greenbullet);
	this->greenbulletSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->greenbulletSelect.setOutlineThickness(-5.f);
	this->greenbulletSelect.setPosition(
		this->window->getSize().x / 2.f - this->greenbulletSelect.getGlobalBounds().width / 2.f - 75,
		this->window->getSize().y / 2.f - this->greenbulletSelect.getGlobalBounds().height / 2.f - 85.f
	);

	// Bullet 4 select
	this->bullet4Select.setSize(sf::Vector2f(125.f, 125.f));
	this->bullet4Select.setOutlineThickness(-5.f);
	this->bullet4Select.setPosition(
		this->window->getSize().x / 2.f - this->bullet4Select.getGlobalBounds().width / 2.f + 75.f,
		this->window->getSize().y / 2.f - this->bullet4Select.getGlobalBounds().height / 2.f - 85.f
	);
	this->bullet4Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Bullet 5 select
	this->bullet5Select.setSize(sf::Vector2f(125.f, 125.f));
	this->bullet5Select.setOutlineThickness(-5.f);
	this->bullet5Select.setPosition(
		this->window->getSize().x / 2.f - this->bullet5Select.getGlobalBounds().width / 2.f + 225.f,
		this->window->getSize().y / 2.f - this->bullet5Select.getGlobalBounds().height / 2.f - 85.f
	);
	this->bullet5Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Bullet 6 select
	this->bullet6Select.setSize(sf::Vector2f(125.f, 125.f));
	this->bullet6Select.setOutlineThickness(-5.f);
	this->bullet6Select.setPosition(
		this->window->getSize().x / 2.f - this->bullet6Select.getGlobalBounds().width / 2.f + 375.f,
		this->window->getSize().y / 2.f - this->bullet6Select.getGlobalBounds().height / 2.f - 85.f
	);
	this->bullet6Select.setFillColor(sf::Color(255, 255, 255, 75));

	// Ship 1 select
	this->ship1Select.setSize(sf::Vector2f(125.f, 125.f));
	this->ship1Select.setOutlineThickness(-5.f);
	this->ship1Select.setPosition(
		this->window->getSize().x / 2.f - this->ship1Select.getGlobalBounds().width / 2.f - 375.f,
		this->window->getSize().y / 2.f - this->ship1Select.getGlobalBounds().height / 2.f + 65.f
	);
	this->ship1Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Ship 2 select
	this->ship2Select.setSize(sf::Vector2f(125.f, 125.f));
	this->ship2Select.setOutlineThickness(-5.f);
	this->ship2Select.setPosition(
		this->window->getSize().x / 2.f - this->ship2Select.getGlobalBounds().width / 2.f - 225.f,
		this->window->getSize().y / 2.f - this->ship2Select.getGlobalBounds().height / 2.f + 65.f
	);
	this->ship2Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Ship 3 select
	this->ship3Select.setSize(sf::Vector2f(125.f, 125.f));
	this->ship3Select.setOutlineThickness(-5.f);
	this->ship3Select.setPosition(
		this->window->getSize().x / 2.f - this->ship3Select.getGlobalBounds().width / 2.f - 75.f,
		this->window->getSize().y / 2.f - this->ship3Select.getGlobalBounds().height / 2.f + 65.f
	);
	this->ship3Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Ship 4 select
	this->ship4Select.setSize(sf::Vector2f(125.f, 125.f));
	this->ship4Select.setOutlineThickness(-5.f);
	this->ship4Select.setPosition(
		this->window->getSize().x / 2.f - this->ship4Select.getGlobalBounds().width / 2.f + 75.f,
		this->window->getSize().y / 2.f - this->ship4Select.getGlobalBounds().height / 2.f + 65.f
	);
	this->ship4Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Ship 5 select
	this->ship5Select.setSize(sf::Vector2f(125.f, 125.f));
	this->ship5Select.setOutlineThickness(-5.f);
	this->ship5Select.setPosition(
		this->window->getSize().x / 2.f - this->ship5Select.getGlobalBounds().width / 2.f + 225.f,
		this->window->getSize().y / 2.f - this->ship5Select.getGlobalBounds().height / 2.f + 65.f
	);
	this->ship5Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Ship 6 select
	this->ship6Select.setSize(sf::Vector2f(125.f, 125.f));
	this->ship6Select.setOutlineThickness(-5.f);
	this->ship6Select.setPosition(
		this->window->getSize().x / 2.f - this->ship6Select.getGlobalBounds().width / 2.f + 375.f,
		this->window->getSize().y / 2.f - this->ship6Select.getGlobalBounds().height / 2.f + 65.f
	);
	this->ship6Select.setFillColor(sf::Color(255, 255, 255, 75));

	// Fire 1 select
	this->fire1Select.setSize(sf::Vector2f(125.f, 125.f));
	this->fire1Select.setOutlineThickness(-5.f);
	this->fire1Select.setPosition(
		this->window->getSize().x / 2.f - this->fire1Select.getGlobalBounds().width / 2.f - 375.f,
		this->window->getSize().y / 2.f - this->fire1Select.getGlobalBounds().height / 2.f + 215.f
	);
	this->fire1Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Fire 2 select
	this->fire2Select.setSize(sf::Vector2f(125.f, 125.f));
	this->fire2Select.setOutlineThickness(-5.f);
	this->fire2Select.setPosition(
		this->window->getSize().x / 2.f - this->fire2Select.getGlobalBounds().width / 2.f - 225.f,
		this->window->getSize().y / 2.f - this->fire2Select.getGlobalBounds().height / 2.f + 215.f
	);
	this->fire2Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Fire 3 select
	this->fire3Select.setSize(sf::Vector2f(125.f, 125.f));
	this->fire3Select.setOutlineThickness(-5.f);
	this->fire3Select.setPosition(
		this->window->getSize().x / 2.f - this->fire3Select.getGlobalBounds().width / 2.f - 75.f,
		this->window->getSize().y / 2.f - this->fire3Select.getGlobalBounds().height / 2.f + 215.f
	);
	this->fire3Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Fire 4 select
	this->fire4Select.setSize(sf::Vector2f(125.f, 125.f));
	this->fire4Select.setOutlineThickness(-5.f);
	this->fire4Select.setPosition(
		this->window->getSize().x / 2.f - this->fire4Select.getGlobalBounds().width / 2.f + 75.f,
		this->window->getSize().y / 2.f - this->fire4Select.getGlobalBounds().height / 2.f + 215.f
	);
	this->fire4Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Fire 5 select
	this->fire5Select.setSize(sf::Vector2f(125.f, 125.f));
	this->fire5Select.setOutlineThickness(-5.f);
	this->fire5Select.setPosition(
		this->window->getSize().x / 2.f - this->fire5Select.getGlobalBounds().width / 2.f + 225.f,
		this->window->getSize().y / 2.f - this->fire5Select.getGlobalBounds().height / 2.f + 215.f
	);
	this->fire5Select.setFillColor(sf::Color(255, 255, 255, 75));
	// Fire 6 select
	this->fire6Select.setSize(sf::Vector2f(125.f, 125.f));
	this->fire6Select.setOutlineThickness(-5.f);
	this->fire6Select.setPosition(
		this->window->getSize().x / 2.f - this->fire6Select.getGlobalBounds().width / 2.f + 375.f,
		this->window->getSize().y / 2.f - this->fire6Select.getGlobalBounds().height / 2.f + 215.f
	);
	this->fire6Select.setFillColor(sf::Color(255, 255, 255, 75));


	this->shopTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->shopTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->shopTitle.getGlobalBounds().height / 2.f - 250.f
	);
	this->returnfromshopText.setFont(this->font);
	this->returnfromshopText.setCharacterSize(48);
	this->returnfromshopText.setFillColor(sf::Color::White);
	this->returnfromshopText.setString("Return");
	this->returnfromshopText.setPosition(
		this->window->getSize().x / 2.f - this->returnfromshopText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->returnfromshopText.getGlobalBounds().height / 2.f + 300.f
	);
}

void Game::initializePauseMenu()
{
	this->pausesettingsBackground.setSize(sf::Vector2f(1000.f, 800.f));
	this->pausesettingsBackground.setFillColor(sf::Color(0, 0, 0, 150));

	this->pauseTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->pauseTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->pauseTitle.getGlobalBounds().height / 2.f - 250.f
	);
	// Initialize Resume menu item
	this->resumeText.setFont(this->font);
	this->resumeText.setCharacterSize(48);
	this->resumeText.setFillColor(sf::Color::White);
	this->resumeText.setString("Resume");
	this->resumeText.setPosition(
		this->window->getSize().x / 2.f - this->resumeText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->resumeText.getGlobalBounds().height / 2.f - 100.f
	);
	// Initialize Pause Settings menu item
	this->pausesettingsText.setFont(this->font);
	this->pausesettingsText.setCharacterSize(48);
	this->pausesettingsText.setFillColor(sf::Color::White);
	this->pausesettingsText.setString("Settings");
	this->pausesettingsText.setPosition(
		this->window->getSize().x / 2.f - this->pausesettingsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->pausesettingsText.getGlobalBounds().height / 2.f - 50.f
	);
	// Initialize Back to Main Menu menu item
	this->mainmenuText.setFont(this->font);
	this->mainmenuText.setCharacterSize(48);
	this->mainmenuText.setFillColor(sf::Color::White);
	this->mainmenuText.setString("Back to Main Menu");
	this->mainmenuText.setPosition(
		this->window->getSize().x / 2.f - this->mainmenuText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->mainmenuText.getGlobalBounds().height / 2.f
	);
}

void Game::initializeGameOverMenu()
{
	this->gameOverText.setPosition
	(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f - 250.f
	);

	// Initialize Back to Main Menu menu item
	this->mainmenuText.setFont(this->font);
	this->mainmenuText.setCharacterSize(48);
	this->mainmenuText.setFillColor(sf::Color::White);
	this->mainmenuText.setString("Back to Main Menu");
	this->mainmenuText.setPosition(
		this->window->getSize().x / 2.f - this->mainmenuText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->mainmenuText.getGlobalBounds().height / 2.f
	);
}

void Game::initializeSettingsMenu()
{
	updateMusicVolume();
	updateSoundFXVolume();

	this->settingsTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->settingsTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->settingsTitle.getGlobalBounds().height / 2.f - 250.f
	);
	// Initialize Music Volume menu item
	this->musicvolumeText.setFont(this->font);
	this->musicvolumeText.setCharacterSize(48);
	this->musicvolumeText.setFillColor(sf::Color::White);
	this->musicvolumeText.setString("Music Volume");
	this->musicvolumeText.setPosition(
		this->window->getSize().x / 2.f - this->musicvolumeText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->musicvolumeText.getGlobalBounds().height / 2.f - 100.f
	);

	// Initialize Sound FX menu item
	this->soundfxText.setFont(this->font);
	this->soundfxText.setCharacterSize(48);
	this->soundfxText.setFillColor(sf::Color::White);
	this->soundfxText.setString("Sound FX");
	this->soundfxText.setPosition(
		this->window->getSize().x / 2.f - this->soundfxText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->soundfxText.getGlobalBounds().height / 2.f
	);


	// Initialize Music volume border bar
	this->musicvolumeBorder.setSize(sf::Vector2f(300.f, 35.f));
	this->musicvolumeBorder.setOutlineThickness(-5.f);
	this->musicvolumeBorder.setFillColor(sf::Color::Transparent);
	this->musicvolumeBorder.setPosition(
		this->window->getSize().x / 2.f - this->musicvolumeBorder.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->musicvolumeBorder.getGlobalBounds().height / 2.f - 25.f
	);


	// Initialize Music volume indicator bar
	this->musicvolumeIndicator.setSize(sf::Vector2f(300.f, 35.f));
	this->musicvolumeIndicator.setFillColor(sf::Color(255, 255, 255, 75));
	this->musicvolumeIndicator.setPosition(
		this->window->getSize().x / 2.f - this->musicvolumeIndicator.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->musicvolumeIndicator.getGlobalBounds().height / 2.f - 25.f
	);
	float musicvolumePercent = static_cast<float>(this->musicVolume / static_cast<float>(10));
	this->musicvolumeIndicator.setSize(sf::Vector2f(300.f * musicvolumePercent, this->musicvolumeIndicator.getSize().y));

	// Initialize Sound FX volume border bar
	this->soundfxvolumeBorder.setSize(sf::Vector2f(300.f, 35.f));
	this->soundfxvolumeBorder.setOutlineThickness(-5.f);
	this->soundfxvolumeBorder.setFillColor(sf::Color::Transparent);
	this->soundfxvolumeBorder.setPosition(
		this->window->getSize().x / 2.f - this->soundfxvolumeBorder.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->soundfxvolumeBorder.getGlobalBounds().height / 2.f + 75.f
	);
	// Initialize Sound FX volume indicator bar
	this->soundfxvolumeIndicator.setSize(sf::Vector2f(300.f, 35.f));
	this->soundfxvolumeIndicator.setFillColor(sf::Color(255, 255, 255, 75));
	this->soundfxvolumeIndicator.setPosition(
		this->window->getSize().x / 2.f - this->soundfxvolumeIndicator.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->soundfxvolumeIndicator.getGlobalBounds().height / 2.f + 75.f
	);
	float soundfxvolumePercent = static_cast<float>(this->soundfxVolume / static_cast<float>(10));
	this->soundfxvolumeIndicator.setSize(sf::Vector2f(300.f * soundfxvolumePercent, this->soundfxvolumeIndicator.getSize().y));

	// Initialize Back to Main Menu menu item
	this->backText.setFont(this->font);
	this->backText.setCharacterSize(48);
	this->backText.setFillColor(sf::Color::White);
	this->backText.setString("Back");
	this->backText.setPosition(
		this->window->getSize().x / 2.f - this->backText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->backText.getGlobalBounds().height / 2.f + 100.f
	);
}

void Game::initializeWindow()
{
	// Size of the window
	this->videoMode.height = 800;
	this->videoMode.width = 1000;

	this->window = new sf::RenderWindow(this->videoMode, "Astral Attack", sf::Style::Default | sf::Style::Titlebar);

	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initializeStage()
{
	this->timeStamp = 0;
	this->timeStamp2 = 0;
	this->stageTransition = false;
	this->stage1End = false;
	this->checkerOne = true;
	this->checkerTwo = true;
	this->checkerThree = true;
	this->checkerFour = true;
	this->checkerFive = true;
	this->Stage = 1;


}

void Game::initializeEnemy()
{
	this->boss = new Boss(125.f, 10.f);
	this->bossIsActive = false;
	this->bossAttackCooldown = 0.f;
	this->bossAttackCooldownMax = 60.f;
	this->startShooting = false;
	this->bossDefeated = false;

	this->spawnTimerMax = 60.f;
	this->spawnTimer = this->spawnTimerMax;

	this->horizontalSpawnTimerMax = 60.f;
	this->horizontalSpawnTimer = 0.f;

	this->meteorSpawnTimerMax = 60.f;
	this->meteorSpawnTimer = 0.f;
	this->tripleMeteorChance = 0;
	this->doubleMeteorChance = 0;

}

void Game::initializeSpawnRates()
{
	this->enemySpawnRate = 2.0f;
	this->meteorSpawnRate = 0.f;
	this->horizontalEnemySpawnRate = 0.f;
	this->healthItemSpawnRate = 0.0167f;
	this->dpsItemSpawnRate = 0.125f;
}

void Game::initializeItems()
{
	this->healthItemSpawnTimerMax = 60.f;
	this->healthItemSpawnTimer = 0.f;
	this->dpsItemSpawnTimerMax = 60.f;
	this->dpsItemSpawnTimer = 0.f;
}

void Game::initializePlayer()
{
	this->player = new Player;

}
