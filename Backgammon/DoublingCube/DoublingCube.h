//
// Created by Daniel Nachum on 11/8/17.
//

#ifndef BACKGAMMON_DOUBLINGCUBE_H
#define BACKGAMMON_DOUBLINGCUBE_H
#include "../Points/Points.hpp"


// A Class to represent a Doubling Cube

class DoublingCube
{
public:
    // Constructs a doubling cube, sets initial value to 1.
    DoublingCube() : m_currentValue(1) {};

    // Returns the current value of this doubling cube.
    int getValue();

    // Doubles the current value, up to 64.
    void doubleValue();

    // Friends the Points class so it can access the currentvalue
    friend void Points::doubleCubePoints();

    std::string toString();

private:
    int m_currentValue;
};

#endif //BACKGAMMON_PROJ_DOUBLINGCUBE_H
