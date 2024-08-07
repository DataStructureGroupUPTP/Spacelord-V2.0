#include "Game.h"

// All initializers are found here

void Game::initializeLines()
{
	this->difficulty = 1;
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

	this->textures["DEATHBEAM"] = new sf::Texture();
	if (!this->textures["DEATHBEAM"]->loadFromFile("Animations/Deathbeam.png"))
	{
		std::cout << "TEXTURE::DEATH_BEAM::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE3ENEMY1"] = new sf::Texture();
	if (!this->textures["STAGE3ENEMY1"]->loadFromFile("Textures/Stage3e1.png"))
	{
		std::cout << "TEXTURE::STAGE3ENEMY1::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE3ENEMY2"] = new sf::Texture();
	if (!this->textures["STAGE3ENEMY2"]->loadFromFile("Textures/Stage3e2.png"))
	{
		std::cout << "TEXTURE::STAGE3ENEMY2::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE3ENEMY3"] = new sf::Texture();
	if (!this->textures["STAGE3ENEMY3"]->loadFromFile("Textures/Stage3e3.png"))
	{
		std::cout << "TEXTURE::STAGE3ENEMY3::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE3ENEMY4"] = new sf::Texture();
	if (!this->textures["STAGE3ENEMY4"]->loadFromFile("Textures/Stage3e4.png"))
	{
		std::cout << "TEXTURE::STAGE3ENEMY4::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE3ENEMY5"] = new sf::Texture();
	if (!this->textures["STAGE3ENEMY5"]->loadFromFile("Textures/Stage3e5.png"))
	{
		std::cout << "TEXTURE::STAGE3ENEMY5::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE3ENEMY6"] = new sf::Texture();
	if (!this->textures["STAGE3ENEMY6"]->loadFromFile("Textures/Stage3e6.png"))
	{
		std::cout << "TEXTURE::STAGE3ENEMY6::FAILED_TO_LOAD" << "\n";
	}
	this->textures["EMPTYHEALTHBAR"] = new sf::Texture();
	if (!this->textures["EMPTYHEALTHBAR"]->loadFromFile("Textures/emptyhealthbar.png"))
	{
		std::cout << "TEXTURE::EMPTY_HEALTHBAR::FAILED_TO_LOAD" << "\n";
	}
	this->textures["1HPHEALTHBAR"] = new sf::Texture();
	if (!this->textures["1HPHEALTHBAR"]->loadFromFile("Textures/1hphealthbar.png"))
	{
		std::cout << "TEXTURE::1HP_HEALTHBAR::FAILED_TO_LOAD" << "\n";
	}
	this->textures["2HPHEALTHBAR"] = new sf::Texture();
	if (!this->textures["2HPHEALTHBAR"]->loadFromFile("Textures/2hphealthbar.png"))
	{
		std::cout << "TEXTURE::2HP_HEALTHBAR::FAILED_TO_LOAD" << "\n";
	}
	this->textures["3HPHEALTHBAR"] = new sf::Texture();
	if (!this->textures["3HPHEALTHBAR"]->loadFromFile("Textures/3hphealthbar.png"))
	{
		std::cout << "TEXTURE::3HP_HEALTHBAR::FAILED_TO_LOAD" << "\n";
	}
	this->textures["4HPHEALTHBAR"] = new sf::Texture();
	if (!this->textures["4HPHEALTHBAR"]->loadFromFile("Textures/4hphealthbar.png"))
	{
		std::cout << "TEXTURE::2HP_HEALTHBAR::FAILED_TO_LOAD" << "\n";
	}
	this->textures["FULLHEALTHBAR"] = new sf::Texture();
	if (!this->textures["FULLHEALTHBAR"]->loadFromFile("Textures/fullhealthbar.png"))
	{
		std::cout << "TEXTURE::FULL_HEALTHBAR::FAILED_TO_LOAD" << "\n";
	}
	this->textures["SHIELDICON"] = new sf::Texture();
	if (!this->textures["SHIELDICON"]->loadFromFile("Textures/shieldicon.png"))
	{
		std::cout << "TEXTURE::SHIELD_ICON::FAILED_TO_LOAD" << "\n";
	}

	if (!this->earthTexture.loadFromFile("Animations/earth.png"))
	{
		std::cout << "ANIMATION::EARTH::FAILED_TO_LOAD" << "\n";
	}

	if (!this->endBackgroundTexture.loadFromFile("Textures/End.png"))
	{
		std::cout << "TEXTURE::END_BACKGROUND::FAILED_TO_LOAD" << "\n";
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

	if (!this->buySoundBuffer.loadFromFile("Sounds/Buy.mp3"))
	{
		std::cout << "SOUND::BUY_SOUND::FAILED_TO_LOAD";
	}

	this->buySound.setBuffer(this->buySoundBuffer);

	if (!this->noMoneyBuffer.loadFromFile("Sounds/Nomoney.mp3"))
	{
		std::cout << "SOUND::NO_BUY_SOUND::FAILED_TO_LOAD";
	}

	this->noMoneySound.setBuffer(this->noMoneyBuffer);

	if (!this->equipBuffer.loadFromFile("Sounds/Equip.wav"))
	{
		std::cout << "SOUND::EQUIP::FAILED_TO_LOAD";
	}

	this->equipSound.setBuffer(this->equipBuffer);

	if (!this->deathbeamSoundBuffer.loadFromFile("Sounds/deathbeamSound.wav"))
	{
		std::cout << "SOUND::DEATH_BEAM_SOUND::FAILED_TO_LOAD";
	}

	this->deathbeamSound.setBuffer(this->deathbeamSoundBuffer);

	if (!this->difficultySetBuffer.loadFromFile("Sounds/difficultySet.mp3"))
	{
		std::cout << "SOUND::DIFFICULTY_SET:FAILED_TO_LOAD";
	}

	this->difficultySetSound.setBuffer(this->difficultySetBuffer);

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
	this->buySound.setVolume(this->soundfxVolume * 50);
	this->noMoneySound.setVolume(this->soundfxVolume * 25);
	this->equipSound.setVolume(this->soundfxVolume * 15);
	this->deathbeamSound.setVolume(this->soundfxVolume * 15);
	this->difficultySetSound.setVolume(this->soundfxVolume * 15);
	this->boss->setVolumeSFX(soundfxVolume);
}

void Game::initializeMusic()
{
	if (!this->stageMusic.openFromFile("Music/BattleInTheStars.ogg"))
	{
		std::cout << "ERROR::BATTLEINTHESTARS::FAILED_TO_LOAD" << "\n";
	}

	// Play the music
	this->stageMusic.play();

	if (!this->gameOverMusic.openFromFile("Music/Defeated.ogg"))
	{
		std::cout << "ERROR::DEFEATED_THEME::FAILED_TO_LOAD" << "\n";
	}

	if (!this->victoryTune.openFromFile("Music/Victory.ogg"))
	{
		std::cout << "ERROR::VICTORY_THEME::FAILED_TO_LOAD" << "\n";
	}

}

void Game::initializeMusicVolume()
{
	this->stageMusic.setVolume(this->musicVolume * 6); // 30
	this->gameOverMusic.setVolume(this->musicVolume * 12); // 30
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
	this->pointText.setCharacterSize(48);
	this->pointText.setStyle(sf::Text::Bold);
	this->pointText.setFillColor(sf::Color::Black);
	this->pointText.setOutlineColor(sf::Color::White);
	this->pointText.setOutlineThickness(2.5f);
	this->pointText.setPosition(25.f, 15.f);
	this->pointText.setString("ERROR");

	//Initialize point text
	this->coinText.setFont(this->font);
	this->coinText.setCharacterSize(36);
	this->coinText.setStyle(sf::Text::Bold);
	this->coinText.setFillColor(sf::Color::Black);
	this->coinText.setOutlineColor(sf::Color::White);
	this->coinText.setOutlineThickness(2.5f);
	this->coinText.setString("ERROR");
	this->coinText.setPosition(15.f, 740.f);

	// Initialize kill counter text
	this->killCounterText.setFont(this->font);
	this->killCounterText.setCharacterSize(36);
	this->killCounterText.setStyle(sf::Text::Bold);
	this->killCounterText.setFillColor(sf::Color::Black);
	this->killCounterText.setOutlineColor(sf::Color::White);
	this->killCounterText.setOutlineThickness(2.5f);
	this->killCounterText.setString("ERROR");
	this->killCounterText.setPosition(15.f, 700.f);

	// Initialize kill counter text
	this->shieldText.setFont(this->font);
	this->shieldText.setCharacterSize(72);
	this->shieldText.setStyle(sf::Text::Bold);
	this->shieldText.setFillColor(sf::Color::Black);
	this->shieldText.setOutlineColor(sf::Color::White);
	this->shieldText.setOutlineThickness(2.5f);
	this->shieldText.setString("ERROR");
	this->shieldText.setPosition(
		this->shieldIcon.getPosition().x,
		this->shieldIcon.getPosition().y
	);

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

	// Initialize Credits title
	this->creditsTitle.setFont(this->titleFont);
	this->creditsTitle.setCharacterSize(100);
	this->creditsTitle.setFillColor(sf::Color::White);
	this->creditsTitle.setStyle(sf::Text::Italic);
	this->creditsTitle.setOutlineThickness(1);
	this->creditsTitle.setString("Credits");

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
	this->timerText.setStyle(sf::Text::Bold);
	this->timerText.setFillColor(sf::Color::Black);
	this->timerText.setOutlineColor(sf::Color::White);
	this->timerText.setOutlineThickness(2.5f);
	timerText.setPosition(this->window->getSize().x - 85.f, 0.f);
	this->elapsedTime = 0.f;
	this->clock.restart();
	this->minutes = 0;
	this->seconds = 0;

	// Initialize title effect
	this->titlePulseTime = 0.f;
	this->titleScaleFactor = 1.0f;
}

void Game::initializeBackground()
{
	if (!this->stageBackgroundTexture.loadFromFile("Textures/Space5.png"))
	{
		std::cout << "TEXTURE::SPACE5::FAILED_TO_LOAD" << "\n";
	}

	if (!this->stage2BackgroundTexture.loadFromFile("Textures/Space9.png"))
	{
		std::cout << "TEXTURE::SPACE9::FAILED_TO_LOAD" << "\n";
	}

	if (!this->stage3BackgroundTexture.loadFromFile("Textures/Space10.png"))
	{
		std::cout << "TEXTURE::SPACE10::FAILED_TO_LOAD" << "\n";
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
	gameData.normalVictory = readData.normalVictory;
	gameData.equipedbullet = readData.equipedbullet;
	gameData.redbullet = readData.redbullet;
	gameData.bluebullet = readData.bluebullet;
	gameData.greenbullet = readData.greenbullet;
	gameData.yellowbullet = readData.yellowbullet;
	gameData.purplebullet = readData.purplebullet;
	gameData.whitebullet = readData.whitebullet;
	gameData.blackbullet = readData.blackbullet;
	gameData.equipedship = readData.equipedship;
	gameData.normalship = readData.normalship;
	gameData.blueship = readData.blueship;
	gameData.greenship = readData.greenship;
	gameData.yellowship = readData.yellowship;
	gameData.purpleship = readData.purpleship;
	gameData.redship = readData.redship;
	gameData.blackship = readData.blackship;
	gameData.equipedfire = readData.equipedfire;
	gameData.normalfire = readData.normalfire;
	gameData.yellowfire = readData.yellowfire;
	gameData.greenfire = readData.greenfire;
	gameData.whitefire = readData.whitefire;

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
	this->menuMusic.setLoop(true);


	// Initialize title
	this->gameTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->gameTitle.getGlobalBounds().width / 2.f + 335.f,
		this->window->getSize().y / 2.f - this->gameTitle.getGlobalBounds().height / 2.f - 200.f
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

	// Initialize Settings menu item
	this->tutorialText.setFont(this->font);
	this->tutorialText.setCharacterSize(48);
	this->tutorialText.setFillColor(sf::Color::White);
	this->tutorialText.setString("Tutorial");
	this->tutorialText.setPosition(
		this->window->getSize().x / 2.f - this->tutorialText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->tutorialText.getGlobalBounds().height / 2.f + 50.f
	);

	this->creditsText.setFont(this->font);
	this->creditsText.setCharacterSize(48);
	this->creditsText.setFillColor(sf::Color::White);
	this->creditsText.setString("Credits");
	this->creditsText.setPosition(
		this->window->getSize().x / 2.f - this->creditsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->creditsText.getGlobalBounds().height / 2.f + 100.f
	);

	// Initialize Reset menu item
	this->resetText.setFont(this->font);
	this->resetText.setCharacterSize(48);
	this->resetText.setFillColor(sf::Color::White);
	this->resetText.setString("Set Difficulty");
	this->resetText.setPosition(
		this->window->getSize().x / 2.f - this->resetText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->resetText.getGlobalBounds().height / 2.f + 150.f
	);

	// Initialize Quit menu item
	this->quitText.setFont(this->font);
	this->quitText.setCharacterSize(48);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setString("Quit");
	this->quitText.setPosition(
		this->window->getSize().x / 2.f - this->quitText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->quitText.getGlobalBounds().height / 2.f + 200.f
	);

	// Initialize Quit menu item
	this->menuHighScore.setFont(this->font);
	this->menuHighScore.setCharacterSize(48);
	this->menuHighScore.setFillColor(sf::Color::White);
	this->menuHighScore.setString("ERROR");
	this->menuHighScore.setPosition(10.f, 675.f);

	this->quitConfirmationScreenActive = false;
}

void Game::initializeQuitConfirmationMenu()
{
	this->areYouSureQuestion.setFont(this->font);
	this->areYouSureQuestion.setCharacterSize(48);
	this->areYouSureQuestion.setFillColor(sf::Color::White);
	this->areYouSureQuestion.setString("Are you sure you want to quit?");
	this->areYouSureQuestion.setPosition(
		this->window->getSize().x / 2.f - this->areYouSureQuestion.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->areYouSureQuestion.getGlobalBounds().height / 2.f - 160.f
	);

	this->yesCloseApplication.setFont(this->font);
	this->yesCloseApplication.setCharacterSize(48);
	this->yesCloseApplication.setFillColor(sf::Color::White);
	this->yesCloseApplication.setString("Yes");
	this->yesCloseApplication.setPosition(
		this->window->getSize().x / 2.f - this->yesCloseApplication.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->yesCloseApplication.getGlobalBounds().height / 2.f
	);

	this->noKeepPlaying.setFont(this->font);
	this->noKeepPlaying.setCharacterSize(48);
	this->noKeepPlaying.setFillColor(sf::Color::White);
	this->noKeepPlaying.setString("No");
	this->noKeepPlaying.setPosition(
		this->window->getSize().x / 2.f - this->noKeepPlaying.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->noKeepPlaying.getGlobalBounds().height / 2.f + 50.f
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

	// Yellow Bullet select
	if (!this->yellowbullet.loadFromFile("Textures/yellowbulletshop.png"))
	{
		std::cout << "TEXTURE::SHOP_YELLOWBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->yellowbulletSelect.setTexture(&yellowbullet);
	this->yellowbulletSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->yellowbulletSelect.setOutlineThickness(-5.f);
	this->yellowbulletSelect.setPosition(
		this->window->getSize().x / 2.f - this->yellowbulletSelect.getGlobalBounds().width / 2.f + 75.f,
		this->window->getSize().y / 2.f - this->yellowbulletSelect.getGlobalBounds().height / 2.f - 85.f
	);
	
	// Purple Bullet select
	if (!this->purplebullet.loadFromFile("Textures/purplebulletshop.png"))
	{
		std::cout << "TEXTURE::SHOP_PURPLEBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->purplebulletSelect.setTexture(&purplebullet);
	this->purplebulletSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->purplebulletSelect.setOutlineThickness(-5.f);
	this->purplebulletSelect.setPosition(
		this->window->getSize().x / 2.f - this->purplebulletSelect.getGlobalBounds().width / 2.f + 225.f,
		this->window->getSize().y / 2.f - this->purplebulletSelect.getGlobalBounds().height / 2.f - 85.f
	);

	// White Bullet select
	if (!this->whitebullet.loadFromFile("Textures/whitebulletshop.png"))
	{
		std::cout << "TEXTURE::SHOP_WHITEBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->whitebulletSelect.setTexture(&whitebullet);
	this->whitebulletSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->whitebulletSelect.setOutlineThickness(-5.f);
	this->whitebulletSelect.setPosition(
		this->window->getSize().x / 2.f - this->whitebulletSelect.getGlobalBounds().width / 2.f + 375.f,
		this->window->getSize().y / 2.f - this->whitebulletSelect.getGlobalBounds().height / 2.f - 85.f
	);

	// Normal Ship select
	if (!this->normalship.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::SHOP_MAINSHIPFIX::FAILED_TO_LOAD" << "\n";
	}
	this->normalshipSelect.setTexture(&normalship);
	this->normalshipSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->normalshipSelect.setOutlineThickness(-5.f);
	this->normalshipSelect.setPosition(
		this->window->getSize().x / 2.f - this->normalshipSelect.getGlobalBounds().width / 2.f - 375.f,
		this->window->getSize().y / 2.f - this->normalshipSelect.getGlobalBounds().height / 2.f + 65.f
	);

	// Ship 2 select
	if (!this->blueship.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::SHOP_MAINSHIPFIX::FAILED_TO_LOAD" << "\n";
	}
	this->blueshipSelect.setTexture(&blueship);
	this->blueshipSelect.setFillColor(sf::Color(40, 132, 203));
	this->blueshipSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->blueshipSelect.setOutlineThickness(-5.f);
	this->blueshipSelect.setPosition(
		this->window->getSize().x / 2.f - this->blueshipSelect.getGlobalBounds().width / 2.f - 225.f,
		this->window->getSize().y / 2.f - this->blueshipSelect.getGlobalBounds().height / 2.f + 65.f
	);

	// Ship 3 select
	if (!this->greenship.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::SHOP_MAINSHIPFIX::FAILED_TO_LOAD" << "\n";
	}
	this->greenshipSelect.setTexture(&greenship);
	this->greenshipSelect.setFillColor(sf::Color(53, 83, 10));
	this->greenshipSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->greenshipSelect.setOutlineThickness(-5.f);
	this->greenshipSelect.setPosition(
		this->window->getSize().x / 2.f - this->greenshipSelect.getGlobalBounds().width / 2.f - 75.f,
		this->window->getSize().y / 2.f - this->greenshipSelect.getGlobalBounds().height / 2.f + 65.f
	);

	// Ship 4 select
	if (!this->yellowship.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::SHOP_MAINSHIPFIX::FAILED_TO_LOAD" << "\n";
	}
	this->yellowshipSelect.setTexture(&yellowship);
	this->yellowshipSelect.setFillColor(sf::Color(255, 177, 0));
	this->yellowshipSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->yellowshipSelect.setOutlineThickness(-5.f);
	this->yellowshipSelect.setPosition(
		this->window->getSize().x / 2.f - this->yellowshipSelect.getGlobalBounds().width / 2.f + 75.f,
		this->window->getSize().y / 2.f - this->yellowshipSelect.getGlobalBounds().height / 2.f + 65.f
	);

	// Ship 5 select
	if (!this->purpleship.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::SHOP_MAINSHIPFIX::FAILED_TO_LOAD" << "\n";
	}
	this->purpleshipSelect.setTexture(&purpleship);
	this->purpleshipSelect.setFillColor(sf::Color(153, 102, 255));
	this->purpleshipSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->purpleshipSelect.setOutlineThickness(-5.f);
	this->purpleshipSelect.setPosition(
		this->window->getSize().x / 2.f - this->purpleshipSelect.getGlobalBounds().width / 2.f + 225.f,
		this->window->getSize().y / 2.f - this->purpleshipSelect.getGlobalBounds().height / 2.f + 65.f
	);

	// Ship 6 select
	if (!this->redship.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::SHOP_MAINSHIPFIX::FAILED_TO_LOAD" << "\n";
	}
	this->redshipSelect.setTexture(&redship);
	this->redshipSelect.setFillColor(sf::Color(212, 44, 77));
	this->redshipSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->redshipSelect.setOutlineThickness(-5.f);
	this->redshipSelect.setPosition(
		this->window->getSize().x / 2.f - this->redshipSelect.getGlobalBounds().width / 2.f + 375.f,
		this->window->getSize().y / 2.f - this->redshipSelect.getGlobalBounds().height / 2.f + 65.f
	);


	// Fire 1 select
	if (!this->normalfire.loadFromFile("Textures/Fireidleshop.png"))
	{
		std::cout << "TEXTURE::SHOP_FIREIDLE::FAILED_TO_LOAD" << '\n';
	}
	this->normalfireSelect.setTexture(&normalfire);
	this->normalfireSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->normalfireSelect.setOutlineThickness(-5.f);
	this->normalfireSelect.setPosition(
		this->window->getSize().x / 2.f - this->normalfireSelect.getGlobalBounds().width / 2.f - 375.f,
		this->window->getSize().y / 2.f - this->normalfireSelect.getGlobalBounds().height / 2.f + 215.f
	);
	// Fire 2 select
	if (!this->yellowfire.loadFromFile("Textures/Fireidleyellowshop.png"))
	{
		std::cout << "TEXTURE::SHOP_FIREIDLE::FAILED_TO_LOAD" << '\n';
	}
	this->yellowfireSelect.setTexture(&yellowfire);
	this->yellowfireSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->yellowfireSelect.setOutlineThickness(-5.f);
	this->yellowfireSelect.setPosition(
		this->window->getSize().x / 2.f - this->yellowfireSelect.getGlobalBounds().width / 2.f - 225.f,
		this->window->getSize().y / 2.f - this->yellowfireSelect.getGlobalBounds().height / 2.f + 215.f
	);
	// Fire 3 select
	if (!this->greenfire.loadFromFile("Textures/Fireidleshopgreen.png"))
	{
		std::cout << "TEXTURE::SHOP_FIREIDLE::FAILED_TO_LOAD" << '\n';
	}
	this->greenfireSelect.setTexture(&greenfire);
	this->greenfireSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->greenfireSelect.setOutlineThickness(-5.f);
	this->greenfireSelect.setPosition(
		this->window->getSize().x / 2.f - this->greenfireSelect.getGlobalBounds().width / 2.f - 75.f,
		this->window->getSize().y / 2.f - this->greenfireSelect.getGlobalBounds().height / 2.f + 215.f
	);

	// Black ship select
	if (!this->blackship.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::SHOP_MAINSHIPFIX::FAILED_TO_LOAD" << "\n";
	}
	this->blackshipSelect.setTexture(&blackship);
	this->blackshipSelect.setFillColor(sf::Color::Color(65, 65, 65));
	this->blackshipSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->blackshipSelect.setOutlineThickness(-5.f);
	this->blackshipSelect.setPosition(
		this->window->getSize().x / 2.f - this->blackshipSelect.getGlobalBounds().width / 2.f + 75.f,
		this->window->getSize().y / 2.f - this->blackshipSelect.getGlobalBounds().height / 2.f + 215.f
	);

	// Black bullet select
	if (!this->blackbullet.loadFromFile("Textures/blackbulletshop.png"))
	{
		std::cout << "TEXTURE::SHOP_BLACKBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->blackbulletSelect.setTexture(&blackbullet);
	this->blackbulletSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->blackbulletSelect.setOutlineThickness(-5.f);
	this->blackbulletSelect.setPosition(
		this->window->getSize().x / 2.f - this->blackbulletSelect.getGlobalBounds().width / 2.f + 225.f,
		this->window->getSize().y / 2.f - this->blackbulletSelect.getGlobalBounds().height / 2.f + 215.f
	);
	
	// White fire select
	if (!this->whitefire.loadFromFile("Textures/Fireidleshopwhite.png"))
	{
		std::cout << "TEXTURE::SHOP_BLACKBULLET::FAILED_TO_LOAD" << "\n";
	}
	this->whitefireSelect.setTexture(&whitefire);
	this->whitefireSelect.setSize(sf::Vector2f(125.f, 125.f));
	this->whitefireSelect.setOutlineThickness(-5.f);
	this->whitefireSelect.setPosition(
		this->window->getSize().x / 2.f - this->whitefireSelect.getGlobalBounds().width / 2.f + 375.f,
		this->window->getSize().y / 2.f - this->whitefireSelect.getGlobalBounds().height / 2.f + 215.f
	);

	this->shopTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->shopTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->shopTitle.getGlobalBounds().height / 2.f - 350.f
	);

	this->returnfromshopText.setFont(this->font);
	this->returnfromshopText.setCharacterSize(48);
	this->returnfromshopText.setFillColor(sf::Color::White);
	this->returnfromshopText.setString("Return");
	this->returnfromshopText.setPosition(
		this->window->getSize().x / 2.f - this->returnfromshopText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->returnfromshopText.getGlobalBounds().height / 2.f + 300.f
	);

	std::stringstream ss2;
	ss2 << "Money: " << this->gameData.coins << "$";
	this->coinAmount.setString(ss2.str());
	this->coinAmount.setFont(this->font);
	this->coinAmount.setCharacterSize(48);
	this->coinAmount.setFillColor(sf::Color::White);
	this->coinAmount.setPosition(10.f, 725.f);

	this->objectPrice.setFont(this->font);
	this->objectPrice.setCharacterSize(48);
	this->objectPrice.setFillColor(sf::Color::White);
	this->objectPrice.setString("");
	this->objectPrice.setPosition(
		this->window->getSize().x / 2.f - this->objectPrice.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->objectPrice.getGlobalBounds().height / 2.f - 250.f
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

void Game::initializeTutorialMenu()
{
	this->tutorialTitle.setFont(this->titleFont);
	this->tutorialTitle.setCharacterSize(100);
	this->tutorialTitle.setFillColor(sf::Color::White);
	this->tutorialTitle.setStyle(sf::Text::Italic);
	this->tutorialTitle.setOutlineThickness(1);
	this->tutorialTitle.setString("TUTORIAL");
	this->tutorialTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->tutorialTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->tutorialTitle.getGlobalBounds().height / 2.f - 300.f
	);
	this->keybindingsExplanation.setFont(this->font);
	this->keybindingsExplanation.setCharacterSize(34);
	this->keybindingsExplanation.setFillColor(sf::Color::White);
	this->keybindingsExplanation.setString("Left/Right --> Move between lanes\nUp/Down --> Move vertically within a lane\nZ --> Fire bullets\nX --> Activate shield. Using a shield makes you invulnerable for 3 seconds.\nYou can get more shields by reaching the kills threshold in the left corner \nof the screen. \nRed orbs --> Heal for 1 hp, spawns every minute \nPurple orbs --> Damage upgrade \nBlue orbs --> Fire rate upgrade \nYellow orbs --> Bullet speed upgrade & Money\n");
	this->keybindingsExplanation.setPosition(
		this->window->getSize().x / 2.f - this->keybindingsExplanation.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->keybindingsExplanation.getGlobalBounds().height / 2.f
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
	this->scoreAchieved.setFont(this->font);
	this->scoreAchieved.setCharacterSize(48);
	this->scoreAchieved.setFillColor(sf::Color::White);
	this->scoreAchieved.setString("ERROR");
	this->scoreAchieved.setPosition(
		this->window->getSize().x / 2.f - this->mainmenuText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->mainmenuText.getGlobalBounds().height / 2.f + 200.f
	);
	this->lastHighScore.setFont(this->font);
	this->lastHighScore.setCharacterSize(48);
	this->lastHighScore.setFillColor(sf::Color::White);
	this->lastHighScore.setString("ERROR");
	this->lastHighScore.setPosition(
		this->window->getSize().x / 2.f - this->lastHighScore.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->lastHighScore.getGlobalBounds().height / 2.f + 225.f
	);
}

void Game::initializeEndScreen()
{

    // Set up congratulatory text
    this->congratText.setFont(this->font);
    this->congratText.setCharacterSize(100);
    this->congratText.setFillColor(sf::Color::White);
	this->congratText.setOutlineColor(sf::Color::Yellow);
	this->congratText.setOutlineThickness(0.5);
    this->congratText.setString("Congratulations, You Won!");
    this->congratText.setPosition(
        this->window->getSize().x / 2.f - this->congratText.getGlobalBounds().width / 2.f,
        100.f
    );

	this->earthSprite.setTexture(this->earthTexture);
	earthCurrentFrame = 0;
	earthAnimationTimer = 0.f;
	earthAnimationSpeed = 0.1f; // Adjust this value as needed for your animation speed
	earthFrame = sf::IntRect(0, 0, 100, 100); // Start at the first frame
	earthSprite.setTextureRect(earthFrame);

	this->earthSprite.setScale(4.f, 4.f);
	this->earthSprite.setPosition(300.f, 500.f);

	this->endBackground.setTexture(this->endBackgroundTexture);

}

void Game::initializeDifficultyMenu()
{
	this->incognitoFlag = false;

	// Easy difficulty text
	this->easyText.setFont(this->font);
	this->easyText.setCharacterSize(60);
	this->easyText.setFillColor(sf::Color(255, 255, 255, 128)); // Semi-transparent white
	this->easyText.setOutlineColor(sf::Color(0, 255, 0, 128));  // Semi-transparent green
	this->easyText.setOutlineThickness(1.f);
	this->easyText.setString("Easy");
	this->easyText.setPosition(
		this->window->getSize().x / 2.f - this->easyText.getGlobalBounds().width / 2.f,
		200.f
	);

	// Normal difficulty text
	this->normalText.setFont(this->font);
	this->normalText.setCharacterSize(60);
	this->normalText.setFillColor(sf::Color(255, 255, 255, 128)); // Semi-transparent white
	this->normalText.setOutlineColor(sf::Color(255, 255, 0, 128)); // Semi-transparent yellow
	this->normalText.setOutlineThickness(1.f);
	this->normalText.setString("Normal");
	this->normalText.setPosition(
		this->window->getSize().x / 2.f - this->normalText.getGlobalBounds().width / 2.f,
		300.f
	);

	// Hard difficulty text
	this->hardText.setFont(this->font);
	this->hardText.setCharacterSize(60);
	this->hardText.setFillColor(sf::Color(255, 255, 255, 128)); // Semi-transparent white
	this->hardText.setOutlineColor(sf::Color(255, 0, 0, 128));  // Semi-transparent red
	this->hardText.setOutlineThickness(1.f);
	this->hardText.setString("???");
	this->hardText.setPosition(
		this->window->getSize().x / 2.f - this->hardText.getGlobalBounds().width / 2.f,
		400.f
	);

	// Return text
	this->returnText.setFont(this->font);
	this->returnText.setCharacterSize(50);
	this->returnText.setFillColor(sf::Color(255, 255, 255, 128)); // Semi-transparent white
	this->returnText.setOutlineColor(sf::Color(255, 255, 255, 128)); // Semi-transparent white
	this->returnText.setOutlineThickness(1.f);
	this->returnText.setString("Return");
	this->returnText.setPosition(
		this->window->getSize().x / 2.f - this->returnText.getGlobalBounds().width / 2.f,
		500.f
	);

	this->currentText.setFont(this->font);
	this->currentText.setCharacterSize(50);
	this->currentText.setFillColor(sf::Color::White);
	this->currentText.setString("Difficulty: ");
	this->currentText.setPosition(0, 730);


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

void Game::initializeCreditsMenu()
{
	this->creditsTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->creditsTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->creditsTitle.getGlobalBounds().height / 2.f - 350.f
	);

	this->gamedevcreditsText.setFont(this->font);
	this->gamedevcreditsText.setCharacterSize(48);
	this->gamedevcreditsText.setFillColor(sf::Color::White);
	this->gamedevcreditsText.setString("Developed by Sebastian Perez & Alejandro Adorno");
	this->gamedevcreditsText.setPosition(
		this->window->getSize().x / 2.f - this->gamedevcreditsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gamedevcreditsText.getGlobalBounds().height / 2.f - 250.f
	);

	this->listofcredits1Text.setFont(this->font);
	this->listofcredits1Text.setCharacterSize(24);
	this->listofcredits1Text.setFillColor(sf::Color::White);
	this->listofcredits1Text.setString("ASSETS\nVoid Main Ship:\nFoozle, Itch.io\nLaser 2020:\nWenrexa, Itch.io\nPixel Space Background Generator:\nDeep-Fold, Itch.io\nVoid Environment Pack:\nFoozle, Itch.io\nCelestial Objects Pixel Art:\nNorma2D, Itch.io\nSpaceship Shooter Environment:\nAnsimuz, Itch.io\nVoid - Feet Pack 2 - Nairan:\nFoozle, Itch.io\nVoid - Fleet Pack 1 - Kla'ed:\nFoozle, Itch.io\nSOUNDS\nMenu Sound 5:\nApenguin73, Freesound.org\nSword Hit:\nqubodup, Freesound.org");
	this->listofcredits1Text.setPosition(
		this->window->getSize().x / 2.f - this->listofcredits1Text.getGlobalBounds().width / 2.f - 300.f,
		this->window->getSize().y / 2.f - this->listofcredits1Text.getGlobalBounds().height / 2.f + 40.f
	);

	this->listofcredits2Text.setFont(this->font);
	this->listofcredits2Text.setCharacterSize(24);
	this->listofcredits2Text.setFillColor(sf::Color::White);
	this->listofcredits2Text.setString("Bouncing Power Up 1_5:\nJoao_Janz, Freesound.org\nLaser zap:\nPixabay, Pixabay.com\nPistol Shot:\nLeMudCrab, Freesound.org\nExplosion:\nqubodup, Freesound.otg\npauseStart:\nWagna, Freesound.org\nHeal - Rpg:\ncolorsCrimsonTears, Freesound.org\nPowerup 10:\nMATRIXXX_, Freesound.org\nswoosh-2:\nlesaucisson, Freesound.org\nmetal bowl - hit - with wooden spoon 01:\nAnthousai, Freesound.org\nSpace Shooter Music:\nOblidivm, Opengameart.org\nhttps://opengameart.org/content/space-shooter-music");
	this->listofcredits2Text.setPosition(
		this->window->getSize().x / 2.f - this->listofcredits2Text.getGlobalBounds().width / 2.f + 100.f,
		this->window->getSize().y / 2.f - this->listofcredits2Text.getGlobalBounds().height / 2.f + 25.f
	);

	this->listofcredits3Text.setFont(this->font);
	this->listofcredits3Text.setCharacterSize(26);
	this->listofcredits3Text.setFillColor(sf::Color::White);
	this->listofcredits3Text.setString("Spacey 1up/Power up:\nGameAudio, Freesound.org\nBuying Sounds:\nwobesound, Freesound.org\nWrong:\nRaclure, Freesound.org\nGeneric Rifle Cock:\nGameWithBepis, Freesound.org");
	this->listofcredits3Text.setPosition(
		this->window->getSize().x / 2.f - this->listofcredits3Text.getGlobalBounds().width / 2.f + 350.f,
		this->window->getSize().y / 2.f - this->listofcredits3Text.getGlobalBounds().height / 2.f - 122.f
	);

	this->returnfromcreditsText.setFont(this->font);
	this->returnfromcreditsText.setCharacterSize(48);
	this->returnfromcreditsText.setFillColor(sf::Color::Yellow);
	this->returnfromcreditsText.setString("Return");
	this->returnfromcreditsText.setPosition(
		this->window->getSize().x / 2.f - this->returnfromcreditsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->returnfromcreditsText.getGlobalBounds().height / 2.f + 300.f
	);
}

void Game::initializeWindow()
{
	// Size of the window
	this->videoMode.height = 800;
	this->videoMode.width = 1000;

	this->window = new sf::RenderWindow(this->videoMode, "Astral Attack", sf::Style::Close | sf::Style::Titlebar);
	this->view = this->window->getDefaultView();

	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);

}

void Game::initializeStage()
{
	this->timeStamp = 0;
	this->timeStamp2 = 0;
	this->stageTransition = false;
	this->stage1End = false;
	this->stage2End = false;
	this->checkerOne = true;
	this->checkerTwo = true;
	this->checkerThree = true;
	this->checkerFour = true;
	this->checkerFive = true;
	this->checkerSix = true;
	this->checkerSeven = true;
	this->cutscene = false;
	this->Stage = 2;


}

void Game::initializeEnemy()
{
	this->boss = new Boss(125.f, 10.f, 1);
	this->bossIsActive = false;
	this->bossDefeated = false;

	this->bossAttackCooldown = 0.f;
	this->bossAttackCooldownMax = 60.f;
	this->startShooting = false;


	this->spawnTimerMax = 60.f;
	this->spawnTimer = this->spawnTimerMax;

	this->horizontalSpawnTimerMax = 60.f;
	this->horizontalSpawnTimer = 0.f;

	this->meteorSpawnTimerMax = 60.f;
	this->meteorSpawnTimer = 0.f;
	this->tripleMeteorChance = 0;
	this->doubleMeteorChance = 0;

	this->deathBeamSpawnTimerMax = 60.f;
	this->deathBeamSpawnTimer = 0.f;

}

void Game::initializeSpawnRates()
{
	this->enemySpawnRate = 2.0f;
	this->meteorSpawnRate = 0.f;
	this->horizontalEnemySpawnRate = 0.f;
	this->deathBeamSpawnRate = 0.f;

	this->healthItemSpawnRate = 0.0167f;
	this->dpsItemSpawnRate = 0.125f;

}

void Game::initializePlayerHealthBar()
{
	this->playerHealthBar.setTexture(*this->textures["FULLHEALTHBAR"]);
	this->playerHealthBar.setScale(6, 6);
	this->playerHealthBar.setPosition(35, 150);
}

void Game::initializeShieldDisplay()
{
	this->shieldIcon.setTexture(*this->textures["SHIELDICON"]);
	this->shieldIcon.setScale(1.75f, 1.75f);
	this->shieldIcon.setPosition(15, 475);
}

void Game::initializeItems()
{
	this->healthItemSpawnTimerMax  = 60.f;
	this->healthItemSpawnTimer = 0.f;
	this->dpsItemSpawnTimerMax = 60.f;
	this->dpsItemSpawnTimer = 0.f;
}

void Game::initializePlayer()
{
	this->player = new Player(difficulty);
	this->player->setShipColor(gameData.equipedship);
	this->player->setFireColor(gameData.equipedfire);
	this->setBulletColor(gameData.equipedbullet);
}


