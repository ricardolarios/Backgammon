//
// Created by Rikki on 11/9/2017.
//

#include "TextView.h"

using namespace std;

/**
 * Outputs the current state of the Backgammon game to standard out.
 */
void TextView::refresh() {
    cout << this->m_currentState << endl;
}

/**
 * Updates the current state of the View.
 * @param state
 */
void TextView::updateState(string state) {
    this->m_currentState = state;
}