#include "gameData.h"

#include <iostream>
#include <fstream>

void writeToFile(const GameData& data) {
    std::ofstream outFile("Data/gamedata.txt");
    if (outFile.is_open()) {
        outFile << "coins = " << data.coins << '\n';
        outFile << "high-score = " << data.highScore << '\n';
        outFile << "item1 = " << data.item1 << '\n';
        outFile << "item2 = " << data.item2 << '\n';
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}

GameData readFromFile() {
    GameData data;
    std::ifstream inFile("Data/gamedata.txt");
    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            if (line.find("coins = ") == 0) {
                data.coins = std::stoi(line.substr(8));
            }
            else if (line.find("high-score = ") == 0) {
                data.highScore = std::stoi(line.substr(13));
            }
            else if (line.find("item1 = ") == 0) {
                data.item1 = line.substr(8);
            }
            else if (line.find("item2 = ") == 0) {
                data.item2 = line.substr(8);
            }
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to open file for reading\n";
    }
    return data;
}