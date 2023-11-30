// Player.cpp

#include "Player.h"

Player::Player(const std::string& playerName, char playerSymbol) : name(playerName), symbol(playerSymbol) {}

std::string Player::getName() const {
    return name;
}

char Player::getSymbol() const {
    return symbol;
}