#include "Explosion.h"

Explosion::Explosion(float x, float y, const sf::Vector2f& enemySize) {
    this->texture.loadFromFile("Animations/explosion.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(2.75f, 2.75f);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 16, 16)); // Set the initial frame
    this->sprite.setPosition(x + enemySize.x / 2 - 8*2.75f, y + enemySize.y / 2 - 8); // Center explosion
    this->frame = 0;
    this->finished = false;
    this->animationTimer.restart();
}

void Explosion::update() {
    if (this->animationTimer.getElapsedTime().asSeconds() > 0.1f) {
        this->frame++;
        if (this->frame >= 5) {
            this->finished = true;
        }
        else {
            this->sprite.setTextureRect(sf::IntRect(this->frame * 16, 0, 16, 16));
            this->animationTimer.restart();
        }
    }
}

void Explosion::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

bool Explosion::isFinished() const {
    return this->finished;
}
