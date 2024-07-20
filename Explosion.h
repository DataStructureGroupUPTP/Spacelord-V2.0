#pragma once

#include <SFML/Graphics.hpp>

// Explosion class declaration
class Explosion {
public:
    Explosion(float x, float y, const sf::Vector2f& enemySize);
    void update();
    void render(sf::RenderTarget& target);
    bool isFinished() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock animationTimer;
    int frame;
    bool finished;
};

