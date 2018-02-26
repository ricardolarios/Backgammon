//
// Created by Daniel Nachum on 11/8/17.
//

#ifndef BACKGAMMON_PLAYER_H
#define BACKGAMMON_PLAYER_H

#include <string>
#include "../Color/Color.hpp"

using namespace std;

class Player
{
public:
    Player() : m_name(), m_color(), m_points() {};
    // Gets the name of this player.
    const string getName() const;
    // Sets the name of this player.
    void setName(std::string);
    // Gets the m_color of this player.
    const std::string getColor() const;
    // Sets the m_color of this player.
    void setColor(Color);
    // Adds points to the player.
    void addPoints(int);
    // Output function
    void output(/* Pieces pOut not actual yet, Pieces pLeft not actual yet */);
    friend bool operator==(const Player&, const Player&);
    friend bool operator!=(const Player&, const Player&);

private:
    string m_name;
    Color m_color;
    int m_points;
};

#endif //BACKGAMMON_PLAYER_H
