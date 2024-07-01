#pragma once

#include <string>

struct GameData {
    int coins = 0;
    unsigned int highScore = 0;
    std::string equipedbullet;
    std::string redbullet;
    std::string bluebullet;
    std::string greenbullet;
    std::string yellowbullet;
    std::string purplebullet;
    std::string whitebullet;
    int equipedship;
    std::string normalship;
    std::string blueship;
    std::string greenship;
    std::string yellowship;
    std::string purpleship;
    std::string redship;
};

void updateGameData(const GameData& data);
GameData readFromFile();
void resetGameData();

