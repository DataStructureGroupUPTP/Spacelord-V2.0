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
        outFile << "blackbullet = " << data.blackbullet << '\n';
        outFile << "equipedship = " << data.equipedship << '\n';
        outFile << "normalship = " << data.normalship << '\n';
        outFile << "blueship = " << data.blueship << '\n';
        outFile << "greenship = " << data.greenship << '\n';
        outFile << "yellowship = " << data.yellowship << '\n';
        outFile << "purpleship = " << data.purpleship << '\n';
        outFile << "redship = " << data.redship << '\n';
        outFile << "blackship = " << data.blackship << '\n';
        outFile << "equipedfire = " << data.equipedfire << '\n';
        outFile << "normalfire = " << data.normalfire << '\n';
        outFile << "yellowfire = " << data.yellowfire << '\n';
        outFile << "greenfire = " << data.greenfire << '\n';
        outFile << "whitefire = " << data.whitefire << '\n';
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
            data.equipedbullet = std::stoi(line.substr(16));
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
        else if (line.find("blackbullet = ") == 0) {
                data.blackbullet = line.substr(14);
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
        else if (line.find("blackship = ") == 0) {
                data.blackship = line.substr(12);
            }
        else if (line.find("equipedfire = ") == 0) {
                data.equipedfire = std::stoi(line.substr(14));
            }
        else if (line.find("normalfire = ") == 0) {
                data.normalfire = line.substr(13);
            }
        else if (line.find("yellowfire = ") == 0) {
                data.yellowfire = line.substr(13);
            }
        else if (line.find("greenfire = ") == 0) {
                data.greenfire = line.substr(12);
            }
        else if (line.find("whitefire = ") == 0) {
                data.whitefire = line.substr(12);
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
        outFile << "equipedbullet = " << 0 << '\n';
        outFile << "redbullet = " << "ACQUIRED" << '\n';
        outFile << "bluebullet = " << "NULL" << '\n';
        outFile << "greenbullet = " << "NULL" << '\n';
        outFile << "yellowbullet = " << "NULL" << '\n';
        outFile << "purplebullet = " << "NULL" << '\n';
        outFile << "whitebullet = " << "NULL" << '\n';
        outFile << "blackbullet = " << "NULL" << '\n';
        outFile << "equipedship = " << 0 << '\n';
        outFile << "normalship = " << "ACQUIRED" << '\n';
        outFile << "blueship = " << "NULL" << '\n';
        outFile << "greenship = " << "NULL" << '\n';
        outFile << "yellowship = " << "NULL" << '\n';
        outFile << "purpleship = " << "NULL" << '\n';
        outFile << "redship = " << "NULL" << '\n';
        outFile << "blackship = " << "NULL" << '\n';
        outFile << "equipedfire = " << 0 << '\n';
        outFile << "normalfire = " << "ACQUIRED" << '\n';
        outFile << "yellowfire = " << "NULL" << '\n';
        outFile << "greenfire = " << "NULL" << '\n';
        outFile << "whitefire = " << "NULL" << '\n';

        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}