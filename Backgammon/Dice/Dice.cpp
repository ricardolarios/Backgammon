//
// Created by Rikki on 11/8/2017.
//

#include <cstdlib>
#include <vector>
#include "Dice.h"
#include <ctime>

// Constructer for a die when returnNewDice is run and two extra dice are added for the player
// with the same value.
Dice::Dice(int doubleValue) {
    this->m_current_value = doubleValue;
}

/**
 * Randomly generates a number that corresponds to the pips of a die.
 * @return              a number corresponding to that of rolling a die.
 */
void Dice::roll() {
    int dice = (rand() % 6) + 1;
    this->m_current_value = dice;

    this->m_used = false;

}

/**
 * Gets the current value of the dice.
 * @return              the current value.
 */
int Dice::getValue()
{
    return this->m_current_value;

}

// Takes in the other dice and checks if their values are the same
bool Dice::compareDice(Dice second) {
    return this->m_current_value == second.m_current_value;
}

// Returns another two dice if compareDice returned true
std::vector<Dice> Dice::returnNewDice() {
    // Doubled dice instantiated with the current value
    Dice double1(m_current_value);
    Dice double2(m_current_value);
    // vector to hold the two doubled dice
    std::vector<Dice> doubleContainer;

    // adds the dice into the vector
    doubleContainer.push_back (double1);
    doubleContainer.push_back (double2);
    return doubleContainer;
}

std::string Dice::toString() {
    return std::to_string(this->m_current_value);
}

void Dice::setUsed(bool used) {
    this->m_used = used;
}

bool Dice::isUsed() {
    return this->m_used;
}