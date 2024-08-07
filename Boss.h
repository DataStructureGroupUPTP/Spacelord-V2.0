#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Boss class declaration
class Boss
{
private:
    // Boss parameters
    sf::Sprite bossSprite;
    sf::Texture bossTexture;
    float health;
    float moveSpeed;
    int type;
    bool isMovingInLoop;
    sf::Vector2f startPosition;
    sf::Vector2f loopCenter;
    float loopRadius;
    float angle;
    bool isDefeated;
    float defeatTimer;

    // Boss animations
    sf::Texture defeatAnimation;
    sf::Texture bossFire;
    sf::Sprite fire;

    sf::IntRect fireFrame;
    int currentFrame;
    float animationTimer;
    float animationSpeed;

    sf::IntRect defeatFrame;
    int defeatCurrentFrame;
    float defeatAnimationTimer;
    float defeatAnimationSpeed;
    sf::Vector2f playerPos;

    // Boss movement
    bool movingDown;
    float Xincrease;
    float Yincrease;

    // Movement states
    void moveInLoop(float deltaTime); // Move in a looping pattern
    void updateDefeatedState(float deltaTime);

    // Boss SFX
    sf::SoundBuffer dirSwapBuffer;
    sf::Sound dirSwapSound;
    float volumeSFX;
    

public:
    // Constructors
    Boss(float initialHealth, float initialMoveSpeed, int type);
    ~Boss();

    // Getters
    const sf::FloatRect getBounds() const;
    const sf::Vector2f& getPos() const;
    const float getHp() const;

    void spawn(sf::Vector2f position, sf::Vector2f loopLocation); // Initialize boss at a given position
    void updateAnimation();
    void update(float deltaTime);      // Update boss logic
    void receivePos(sf::Vector2f pos);
    void setVolumeSFX(float volume);

    void render(sf::RenderTarget& target); // Draw boss to render target

    void takeDamage(float damage); // Reduce boss health
    bool isAlive() const;          // Check if boss is alive
};

