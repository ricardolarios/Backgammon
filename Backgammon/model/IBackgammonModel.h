//
// Created by Rikki on 11/8/2017.
//

#ifndef BACKGAMMON_IBACKGAMMONMODEL_H
#define BACKGAMMON_IBACKGAMMONMODEL_H

#include <iostream>
#include <string>
#include "../Space/Space.hpp"
#include "../Player/Player.h"
#include "../Points/Points.hpp"

class IBackgammonModel {
public:
    IBackgammonModel() {};

    IBackgammonModel(const IBackgammonModel&) {};

    ~IBackgammonModel() {};

    virtual std::string getGameState() =0;

    virtual void startGame() =0;

    virtual void rollDice() =0;

    virtual void rollDoublingCube() =0;

    virtual bool rolled() =0;

    virtual bool doubled() =0;

    virtual bool isValidMove(int, int, Player) =0;

    virtual bool isValidBear(int, int, Player) =0;

    virtual Points getPoints() =0;

    virtual std::string getPointsString() =0;

    virtual Player getPlayer1() =0;

    virtual Player getPlayer2() =0;

    virtual void move(int, int) =0;

    virtual void bear(int, Color) =0;

    virtual bool isWhiteCaptured() =0;

    virtual bool isBlackCaptured() =0;

    virtual int getNumberOfMoves() =0;

    virtual void enterPiece(Color, int) =0;

    //virtual void capturePiece(Space a) = 0;
    virtual bool checkForVictory() =0;

    virtual Color getVictor() =0;

    virtual void resetForTurn() =0;
    virtual bool anyValidEnterMoves(Color color) =0;
    virtual void setPoints(Points) =0;
    virtual void setPlayers(Player, Player) =0;
    virtual void restart() =0;
};

#endif //BACKGAMMON_IBACKGAMMONMODEL_H
