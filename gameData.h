#pragma once

#include <string>

struct GameData {
    int coins = 0;
    int highScore = 0;
    std::string item1 = "not";
    std::string item2 = "not";
};

void writeToFile(const GameData& data);
GameData readFromFile();

