#pragma once

#include <string>

struct GameData {
    int coins = 0;
    unsigned int highScore = 0;
    std::string equipedbullet;
    std::string redbullet;
    std::string bluebullet;
    std::string greenbullet;
};

void updateGameData(const GameData& data);
GameData readFromFile();
void resetGameData();

