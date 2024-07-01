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
        outFile << "yellowbullet = " << data.yellowbullet << '\n';
        outFile << "purplebullet = " << data.purplebullet << '\n';
        outFile << "whitebullet = " << data.whitebullet << '\n';
        outFile << "equipedship = " << data.equipedship << '\n';
        outFile << "normalship = " << data.normalship << '\n';
        outFile << "blueship = " << data.blueship << '\n';
        outFile << "greenship = " << data.greenship << '\n';
        outFile << "yellowship = " << data.yellowship << '\n';
        outFile << "purpleship = " << data.purpleship << '\n';
        outFile << "redship = " << data.redship << '\n';
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
        else if (line.find("yellowbullet = ") == 0) {
                data.yellowbullet = line.substr(15);
            }
        else if (line.find("purplebullet = ") == 0) {
                data.purplebullet = line.substr(15);
            }
        else if (line.find("whitebullet = ") == 0) {
                data.whitebullet = line.substr(14);
            }
        else if (line.find("equipedship = ") == 0) {
                data.equipedship = std::stoi(line.substr(14));
            }
        else if (line.find("normalship = ") == 0) {
                data.normalship = line.substr(13);
            }
        else if (line.find("blueship = ") == 0) {
                data.blueship = line.substr(11);
            }
        else if (line.find("greenship = ") == 0) {
                data.greenship = line.substr(12);
            }
        else if (line.find("yellowship = ") == 0) {
                data.yellowship = line.substr(13);
            }
        else if (line.find("purpleship = ") == 0) {
                data.purpleship = line.substr(13);
            }
        else if (line.find("redship = ") == 0) {
                data.redship = line.substr(10);
            }
        }
        inFile.close();
    return data;
}

void resetGameData()
{
    std::ofstream outFile("Data/gamedata.txt");
    if (outFile.is_open()) {
        outFile << "coins = " << "30000" << '\n';
        outFile << "high-score = " << 0 << '\n';
        outFile << "equipedbullet = " << "red" << '\n';
        outFile << "redbullet = " << "ACQUIRED" << '\n';
        outFile << "bluebullet = " << "NULL" << '\n';
        outFile << "greenbullet = " << "NULL" << '\n';
        outFile << "yellowbullet = " << "NULL" << '\n';
        outFile << "purplebullet = " << "NULL" << '\n';
        outFile << "whitebullet = " << "NULL" << '\n';
        outFile << "equipedship = " << 0 << '\n';
        outFile << "normalship = " << "ACQUIRED" << '\n';
        outFile << "blueship = " << "NULL" << '\n';
        outFile << "greenship = " << "NULL" << '\n';
        outFile << "yellowship = " << "NULL" << '\n';
        outFile << "purpleship = " << "NULL" << '\n';
        outFile << "redship = " << "NULL" << '\n';
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}