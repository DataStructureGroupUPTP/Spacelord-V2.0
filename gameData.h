#pragma once

#include <string>

struct GameData {
    int coins = 0;
    unsigned int highScore = 0;
    int equipedbullet;
    std::string redbullet;
    std::string bluebullet;
    std::string greenbullet; 

    std::string yellowbullet;
    std::string purplebullet;
    std::string whitebullet;
    std::string blackbullet;
    int equipedship;
    std::string normalship;
    std::string blueship;
    std::string greenship;
    std::string yellowship;
    std::string purpleship;
    std::string redship;
    std::string blackship;
    int equipedfire;
    std::string normalfire;
    std::string yellowfire;
    std::string greenfire;
    std::string whitefire;
};

void updateGameData(const GameData& data);
GameData readFromFile();
void resetGameData();

