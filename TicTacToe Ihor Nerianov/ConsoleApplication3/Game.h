// Game.h

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game {
private:
    Player playerX;
    Player playerO;
    Board board;
    std::string winnerName; // Variable to store the winner's name
    int rounds;
    int playerXPoints;
    int playerOPoints;

public:
    Game(const std::string& playerXName, const std::string& playerOName);
    void play();
    void displayPointsTable() const;
};

#endif // GAME_H