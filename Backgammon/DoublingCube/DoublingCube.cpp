//
// Created by Daniel Nachum on 11/8/17.
//

#include "DoublingCube.h"

using namespace std;

// Returns the current value of this doubling cube.
int DoublingCube::getValue() {
    return this->m_currentValue;
}

// Doubles the current value, up to 64.
void DoublingCube::doubleValue() {
    if (this->m_currentValue < 64) {
        this->m_currentValue *= 2;
    }
}

string DoublingCube::toString() {
    return to_string(this->m_currentValue);
}
