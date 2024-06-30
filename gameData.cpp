#include "gameData.h"
#include <vector>
#include <iostream>
#include <fstream>



void updateGameData(const GameData& data)
{
    std::ofstream outFile("Data/gamedata.txt");
    if (outFile.is_open()) {
        outFile << "coins = " << data.coins << '\n';
        outFile << "high-score = " << data.highScore << '\n';
        outFile << "equipedbullet = " << data.equipedbullet << '\n';
        outFile << "redbullet = " << data.redbullet << '\n';
        outFile << "bluebullet = " << data.bluebullet << '\n';
        outFile << "greenbullet = " << data.greenbullet << '\n';
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}

GameData readFromFile() {
    GameData data;
    std::ifstream inFile("Data/gamedata.txt");
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file for reading\n";
        return data;
    }

    std::string line;
    while (getline(inFile, line)) {
        if (line.find("coins = ") == 0) {
            data.coins = std::stoi(line.substr(8));
        }
        else if (line.find("high-score = ") == 0) {
            data.highScore = std::stoul(line.substr(13));
        }
        else if (line.find("equipedbullet = ") == 0) {
            data.equipedbullet = line.substr(16);
        }
        else if (line.find("redbullet = ") == 0) {
            data.redbullet = line.substr(12);
        }
        else if (line.find("bluebullet = ") == 0) {
            data.bluebullet = line.substr(13);
        }
        else if (line.find("greenbullet = ") == 0) {
            data.greenbullet = line.substr(14);
        }
    }
    inFile.close();
    return data;
}

void resetGameData()
{
    std::ofstream outFile("Data/gamedata.txt");
    if (outFile.is_open()) {
        outFile << "coins = " << "0" << '\n';
        outFile << "high-score = " << 0 << '\n';
        outFile << "equipedbullet = " << "red" << '\n';
        outFile << "redbullet = " << "ACQUIRED" << '\n';
        outFile << "bluebullet = " << "NULL" << '\n';
        outFile << "greenbullet = " << "NULL" << '\n';
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}