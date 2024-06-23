#include "Boss.h"

#include "Boss.h"
#include <iostream>

Boss::Boss(float initialHealth, float initialMoveSpeed)
    : health(initialHealth), moveSpeed(initialMoveSpeed), isMovingInLoop(false), angle(0.f)
{
    if (!bossTexture.loadFromFile("Textures/Boss1.png"))
    {
        std::cerr << "Failed to load boss texture!" << std::endl;
    }

    bossSprite.setTexture(bossTexture);
    bossSprite.setScale(3.0f, 3.0f); // Adjust scale as needed
    bossSprite.rotate(180.f);

    // Initialize other variables
    startPosition = sf::Vector2f(400.f, -250.f); // Start just above the screen
    bossSprite.setPosition(startPosition);
    loopCenter = sf::Vector2f(675.f, 300.f); // Center of the loop
    loopRadius = 200.f; // Radius of the loop
}

Boss::~Boss()
{
    // Destructor
}

void Boss::spawn(sf::Vector2f position)
{
    bossSprite.setPosition(position);
    isMovingInLoop = false; // Start with coming down from the top
}

void Boss::update(float deltaTime)
{
    if (!isMovingInLoop)
    {
        // Move slowly down to the loop center
        sf::Vector2f currentPosition = bossSprite.getPosition();
        sf::Vector2f direction = loopCenter - currentPosition;
        float distance = moveSpeed * deltaTime;
        if (distance >= std::sqrt(direction.x * direction.x + direction.y * direction.y))
        {
            isMovingInLoop = true;
        }
        else
        {
            direction = distance * direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
            bossSprite.move(direction);
        }
    }
    else
    {
        moveInLoop(deltaTime);
    }
}

void Boss::render(sf::RenderTarget& target)
{
    target.draw(bossSprite);
}

void Boss::takeDamage(float damage)
{
    health -= damage;
}

bool Boss::isAlive() const
{
    return health > 0;
}

void Boss::moveInLoop(float deltaTime)
{
    // Move in a circular loop
    angle += 0.5f * deltaTime; // Adjust loop speed as needed

    float x = loopCenter.x + (loopRadius+50) * std::cos(angle);
    float y = loopCenter.y + loopRadius * std::sin(angle);

    bossSprite.setPosition(x, y);
}