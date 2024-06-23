#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Boss
{
private:
    sf::Sprite bossSprite;
    sf::Texture bossTexture;
    float health;
    float moveSpeed;
    bool isMovingInLoop;
    sf::Vector2f startPosition;
    sf::Vector2f loopCenter;
    float loopRadius;
    float angle;

    sf::Texture bossFire;
    sf::Sprite fire;

    sf::IntRect fireFrame;
    int currentFrame;
    float animationTimer;
    float animationSpeed;

    void moveInLoop(float deltaTime); // Move in a looping pattern

public:
    Boss(float initialHealth, float initialMoveSpeed);
    ~Boss();

    const sf::FloatRect getBounds() const;
    void spawn(sf::Vector2f position); // Initialize boss at a given position
    void updateAnimation();
    void update(float deltaTime);      // Update boss logic
    void render(sf::RenderTarget& target); // Draw boss to render target

    void takeDamage(float damage); // Reduce boss health
    bool isAlive() const;          // Check if boss is alive
};

