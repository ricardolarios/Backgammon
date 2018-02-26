//
// Created by Rikki on 11/9/2017.
//

#ifndef BACKGAMMON_TEXTVIEW_H
#define BACKGAMMON_TEXTVIEW_H

#include "IView.h"
#include <iostream>

/**
 * Represents a text based view of a backgammon game.
 */
class TextView : public IView
{
public:
    // Outputs the given string as text to standard out.
    void refresh();
    void updateState(std::string);

private:
    std::string m_currentState;
};

#endif //BACKGAMMON_TEXTVIEW_H
