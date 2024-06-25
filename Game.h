#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Item.h"
#include "Boss.h"
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

// BOSS DELETE PENDING// BOSS DELETE PENDING// BOSS DELETE PENDING// BOSS DELETE PENDING

enum GameState
{
    MAIN_MENU,
    GAMEPLAY,
    PAUSED,
    SETTINGS,
    GAME_OVER
};


class Game
{
private:
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;

    // Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;
    float bulletSpeed;

    // GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text startText; // New text for the start menu
    sf::Text currencyText;
    sf::Text killCounterText;

    sf::Font titleFont;
    sf::Text gameTitle;
    sf::Text pauseTitle;
    sf::Text settingsTitle;

    // Timer GUI
    sf::Text timerText;
    sf::Clock clock;
    float elapsedTime; // Elapsed time in seconds
    int seconds;
    int minutes;

    //World
    sf::Texture startMenuTexture;
    sf::Sprite startMenuBackground;

    sf::Texture stageBackgroundTexture;
    sf::Sprite stageBackground;
    sf::Sprite stageBackground2;
    float backgroundScrollSpeed;

    // Menu Backgrounds
    sf::Texture gameOverBackgroundTexture;
    sf::Sprite gameOverBackground;

    // Systems
    unsigned points;
    unsigned currency;
    unsigned enemyKillCounter;
    unsigned bombs;

    // Spawnrates
    float enemySpawnRate;
    float meteorSpawnRate;
    float horizontalEnemySpawnRate;
    float healthItemSpawnRate;
    float dpsItemSpawnRate;

    // Player
    Player* player;

    // Player GUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;
    sf::Texture heartTexture;
    sf::Sprite heartSprite;


    // Enemies
    float spawnTimer;
    float spawnTimerMax;
    float horizontalSpawnTimer;
    float horizontalSpawnTimerMax;
    float meteorSpawnTimer;
    float meteorSpawnTimerMax;
    int tripleMeteorChance;
    int doubleMeteorChance;

    std::vector<Enemy*> enemies;

    // Boss
    Boss* boss;
    float bossAttackCooldown;
    float bossAttackCooldownMax;
    bool startShooting;
    bool bossDefeated;

    // Items
    float healthItemSpawnTimer;
    float healthItemSpawnTimerMax;
    float dpsItemSpawnTimer;
    float dpsItemSpawnTimerMax;

    std::vector<Item*> items;

    // Sound Settings
    float soundfxVolume;
    float musicVolume;

    // Sound effects
    sf::SoundBuffer laserBuffer;
    sf::Sound laserSound;

    sf::SoundBuffer menuClick;
    sf::Sound menuSound;

    sf::SoundBuffer playerHitBuffer;
    sf::Sound playerHit;

    sf::SoundBuffer alienHitBuffer;
    sf::Sound alienHit;

    sf::SoundBuffer pauseBuffer;
    sf::Sound pauseSound;

    sf::SoundBuffer healBuffer;
    sf::Sound healSound;

    sf::SoundBuffer powerUpBuffer;
    sf::Sound powerUpSound;

    sf::SoundBuffer swooshBuffer;
    sf::Sound swooshSound;

    sf::SoundBuffer clangBuffer;
    sf::Sound clangHit;

    sf::SoundBuffer criticalBuffer;
    sf::Sound criticalHit;

    sf::SoundBuffer explosionBuffer;
    sf::Sound explosionSound;

    sf::SoundBuffer bossLaserBuffer;
    sf::Sound bossLaser;

    // Music
    sf::Music stageMusic;
    sf::Music menuMusic;
    sf::Music gameOverMusic;
    sf::Music victoryTune;

    // Line Mechanic
    sf::Vertex line1[2];
    sf::Vertex line2[2];
    sf::Vertex line3[2];
    sf::Vertex line4[2];
    int lane;
    int laneRandomizer;
    float lanePos;
    bool leftKeyPressed;
    bool rightKeyPressed;
    float horizontalPos;

    int line1Pos;
    int line2Pos;
    int line3Pos;
    int line4Pos;

    // Game state
    GameState gameState; // New game state variable
    GameState prevgameState;

    // Private functions
    void initialize();
    void initializeWindow();
    void initializeLines();
    void initializeTextures();
    void initializeSounds();
    void initializeMusic();
    void initializeGUI();
    void initializeBackground();
    void initializeSystems();
    void initializeMenuBackgrounds();

    void initializeStartMenu(); // New function for initializing the start menu
    void initializePauseMenu();
    void initializeGameOverMenu();
    void initializeSettingsMenu();

    void initializeEnemy();
    void initializeSpawnRates();
    void initializeItems();
    void initializePlayer();
    void handleMainMenuInput(const sf::Event& ev);
    void handlePauseMenuInput(const sf::Event& ev);
    void handleGameOverMenuInput(const sf::Event& ev);
    void handleSettingsMenuInput(const sf::Event& ev);

    // Main Menu options
    sf::Text playText;
    sf::Text shopText;
    sf::Text settingsText;
    sf::Text creditsText;
    sf::Text quitText;

    // Pause Menu options
    sf::RectangleShape pausesettingsBackground;
    sf::Text resumeText;
    sf::Text pausesettingsText;
    sf::Text mainmenuText;

    // Game Over menu options
    sf::Text gameOverText;

    // Settings Menu options
    sf::Text musicvolumeText;
    sf::RectangleShape musicvolumeBorder;
    sf::RectangleShape musicvolumeIndicator;
    sf::Text soundfxText;
    sf::RectangleShape soundfxvolumeBorder;
    sf::RectangleShape soundfxvolumeIndicator;
    sf::Text backText;

    int selectedMenuItem;

    // Other
    bool bossIsActive;
    float timeStamp;
    bool stageTransition;
    bool stage1End;

public:
    Game();
    virtual ~Game();

    // Functions
    void run();
    void reset();

    void updatePollEvents();
    void updateInput();

    void updateBackground();
    void updateGUI();
    void updateTimer();
    void updateBullets();
    void updateCollision();
    void updateSoundFXVolume();
    void updateMusicVolume();
 
    void updateEnemies();
    void updateItems();
    void updateCombat();
    void updateBoss();

    void updateDifficulty();

    void update();

    void renderGUI();
    void renderWorld();
    void render();
    void renderStartMenu(); // New function for rendering the start menu
    void renderPauseMenu();
    void renderSettingsMenu();
    void renderGameOverMenu();
    void renderGameElements();
};
