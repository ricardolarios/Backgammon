//
// Created by Rikki on 11/8/2017.
//

#ifndef BACKGAMMON_DICE_H
#define BACKGAMMON_DICE_H

#include <vector>
#include <iostream>

/**
 * A Class to represent a Die to be rolled.
 */
class Dice
{
public:
    // Constructs a die, sets initial value to 1.
    Dice() : m_current_value(1), m_used(false) {};

    // Constructer for a die when returnNewDice is run and two extra dice are added for the player.
    Dice(int doubleValue);
    // Rolls this die, generating a random int that corresponds to the pips of the Die.
    // Mutates this dice so that the current value is what was rolled
    void roll();
    // Returns the current value of this Die.
    int getValue();
    // Takes in the other dice and checks if their values are the same
    bool compareDice(Dice second);
    // Returns another two dice if compareDice returned true
    std::vector<Dice> returnNewDice();
    std::string toString();
    void setUsed(bool);
    bool isUsed();

private:
    int m_current_value;
    bool m_used;

};

#endif //BACKGAMMON_DICE_H
