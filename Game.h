#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Item.h"
#include "Boss.h"
#include "Explosion.h"
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <random>
#include "gameData.h"

// BOSS DELETE PENDING// BOSS DELETE PENDING// BOSS DELETE PENDING// BOSS DELETE PENDING

enum GameState
{
    MAIN_MENU,
    GAMEPLAY,
    PAUSED,
    SHOP,
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
    sf::Text coinText;
    sf::Text killCounterText;
    sf::Text bombsText;

    sf::Font titleFont;
    sf::Text gameTitle;
    sf::Text pauseTitle;
    sf::Text settingsTitle;
    sf::Text shopTitle;

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
    sf::Texture stage2BackgroundTexture;
    sf::Sprite stageBackground;
    sf::Sprite stageBackground2;

    float backgroundScrollSpeed;

    // Menu Backgrounds
    sf::Texture gameOverBackgroundTexture;
    sf::Sprite gameOverBackground;

    // Systems
    unsigned points;
    unsigned enemyKillCounter;
    unsigned bombs;
    int lastKillThreshold;

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

    // Explosions
    std::vector<Explosion*> explosions;

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

    sf::SoundBuffer shieldBuffer;
    sf::Sound shield;

    sf::SoundBuffer levelUpBuffer;
    sf::Sound levelup;

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
    void initializeStage();
    void initializeLines();
    void initializeTextures();
    void initializeSounds();
    void initializeMusic();
    void initializeGUI();
    void initializeBackground();
    void initializeSystems();
    void initializeMenuBackgrounds();
    void initializeGameData();

    void initializeStartMenu(); // New function for initializing the start menu
    void initializeShopMenu();
    void initializePauseMenu();
    void initializeGameOverMenu();
    void initializeSettingsMenu();
    void initializeSoundFXVolume();
    void initializeMusicVolume();
    void initializeEnemy();
    void initializeSpawnRates();
    void initializeItems();
    void initializePlayer();
    void handleMainMenuInput(const sf::Event& ev);
    void handleShopMenuInput(const sf::Event& ev);
    void handlePauseMenuInput(const sf::Event& ev);
    void handleGameOverMenuInput(const sf::Event& ev);
    void handleSettingsMenuInput(const sf::Event& ev);

    // Main Menu options
    sf::Text playText;
    sf::Text shopText;
    sf::Text settingsText;
    sf::Text creditsText;
    sf::Text quitText;
    sf::Text resetText;

    // Shop Menu options
    sf::Text returnfromshopText;
    sf::RectangleShape redbulletSelect;
    sf::Texture redbullet;
    sf::RectangleShape bluebulletSelect;
    sf::Texture bluebullet;
    sf::RectangleShape greenbulletSelect;
    sf::Texture greenbullet;
    sf::RectangleShape yellowbulletSelect;
    sf::Texture yellowbullet;
    sf::RectangleShape purplebulletSelect;
    sf::Texture purplebullet;
    sf::RectangleShape whitebulletSelect;
    sf::Texture whitebullet;
    sf::RectangleShape ship1Select;
    sf::RectangleShape ship2Select;
    sf::RectangleShape ship3Select;
    sf::RectangleShape ship4Select;
    sf::RectangleShape ship5Select;
    sf::RectangleShape ship6Select;
    sf::RectangleShape fire1Select;
    sf::RectangleShape fire2Select;
    sf::RectangleShape fire3Select;
    sf::RectangleShape fire4Select;
    sf::RectangleShape fire5Select;
    sf::RectangleShape fire6Select;

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
    int shopselectedMenuItem = 0;

    // Other
    bool bossIsActive;
    bool checkerOne;
    bool checkerTwo;
    bool checkerThree;
    bool checkerFour;
    bool checkerFive;

    // Stages
    bool stageTransition;
    bool stage1End;
    unsigned Stage;
    float timeStamp;
    float timeStamp2;

    // Game Data
    GameData gameData;

    // Fade effect

    enum FadeState { NONE, FADING_OUT, BLACK_SCREEN, FADING_IN };
    FadeState fadeState;
    sf::RectangleShape fadeOverlay;
    float fadeAlpha;
    sf::Clock fadeClock;
    void initializeFadeEffects();
   


public:
    Game();
    virtual ~Game();

    // Functions
    void run();
    void reset();
    void triggerFadeEffect();

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
    void updateFadeEffect();
    void updateExplosionEffect();

    void update();

    void renderGUI();
    void renderWorld();
    void render();
    void renderStartMenu(); // New function for rendering the start menu
    void renderShopMenu();
    void renderEquiped();
    void renderPauseMenu();
    void renderequiped();
    void renderSettingsMenu();
    void renderGameOverMenu();
    void renderGameElements();
    void renderExplosion(sf::RenderTarget& target);
};
