//
// Created by Daniel Nachum on 11/8/17.
//

#include <iostream>
#include "Player.h"

using namespace std;

/**
 * Returns the name of this Player.
 */
const string Player::getName() const {
    return this->m_name;
}

void Player::setName(std::string name) {
    this->m_name = name;
}

const string Player::getColor() const {
    switch (this->m_color) {
        case BLACK:
            return "Black";
        case WHITE:
            return "White";
        default:
            return "N/A";
    }
}

void Player::setColor(Color color) {
    this->m_color = color;
}

void Player::addPoints(int pts) {
    this->m_points += pts;
}

// output function
void Player::output() {
    cout << "Player: " << this->m_name << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Current Score: " << this->m_points << endl;
}

bool operator==(const Player& first, const Player& other) {
    return (first.m_color == other.m_color) && (first.m_name == other.m_name);
    }

bool operator!=(const Player & first, const Player& other) {
    return !(first == other);
}