//
// Created by Rikki on 11/9/2017.
//

#ifndef BACKGAMMON_TEXTCONTROLLER_H
#define BACKGAMMON_TEXTCONTROLLER_H

#include "IController.h"
#include "../model/BackgammonModel.h"
#include "../view/TextView.h"

/**
 * Represents a controller for a text Backgammon game.
 */
class TextController : public IController {
    
public:
    // Constructor for a TextController
    TextController(TextView view, IBackgammonModel *model) : m_view(view), m_model(model) {}
    // Called and starts the game of backgammon with the given
    void go();
    void runGame();


private:
    IBackgammonModel * m_model;
    TextView m_view;
    Player current_player = m_model->getPlayer1();
    // Deals with input if the user wants to enter a piece.
    bool anyValidEnterMoves(Color current);
    void changeTurns();
    void help();
    void restart();


};
#endif //BACKGAMMON_TEXTCONTROLLER_H
