//
// Created by Rikki on 11/8/2017.
//

#ifndef BACKGAMMON_BACKGAMMONMODEL_H
#define BACKGAMMON_BACKGAMMONMODEL_H

#include "IBackgammonModel.h"
#include "../DoublingCube/DoublingCube.h"
#include "../Points/Points.hpp"
#include "../Player/Player.h"
#include "../Player/Player.h"
#include "../Dice/Dice.h"
#include "../Board/Board.hpp"

// Represents an implementation of a Backgammon m_model.
class BackgammonModel : public IBackgammonModel
{
public:
    // Creates an initial Backgammon game with the two given players.
    BackgammonModel() : m_board(Board()), m_die1(Dice()), m_die2(Dice()), m_doublingCube(DoublingCube()),
                        m_points(Points()), m_player1(), m_player2(), m_hasRolled(false), m_hasDoubled(false),
                        m_num_of_moves(0), m_captured_white(vector<Piece>()), m_captured_black(vector<Piece>()){};

    // Restarts a Backgammon game with player names and points preserved.
    BackgammonModel(BackgammonModel *old) :
            m_board(Board()), m_die1(Dice()), m_die2(Dice()), m_doublingCube(DoublingCube()),
            m_points(Points()), m_player1(), m_player2(), m_hasRolled(false), m_hasDoubled(false),
            m_num_of_moves(0), m_captured_white(vector<Piece>()), m_captured_black(vector<Piece>()), m_victor(EMPTY) {
        this->m_points = old->m_points;
        this->m_player1 = old->m_player1;
        this->m_player2 = old->m_player2;
    };
    std::string getGameState();
    void startGame();
    void rollDoublingCube();
    Points getPoints();
    std::string getPointsString();
    void rollDice();
    // Moves a piece from the first space to the second space.
    void move(int, int);
    void bear(int, Color);
    bool rolled();
    bool doubled();
    Player getPlayer1();
    Player getPlayer2();
    bool isValidMove(int, int, Player);
    bool isValidBear(int, int, Player);
    bool isWhiteCaptured();
    bool isBlackCaptured();
    // Returns the number of moves left
    int getNumberOfMoves();
    //void capturePiece(Space a);
    void enterPiece(Color, int);
    bool checkForVictory();
    Color getVictor();
    bool anyValidEnterMoves(Color current);
    void resetForTurn();
    void restart();
    void setPoints(Points);
    void setPlayers(Player, Player);

private:
    Board m_board;
    Dice m_die1;
    Dice m_die2;
    DoublingCube m_doublingCube;
    Points m_points;
    Player m_player1;
    Player m_player2;
    bool m_hasRolled;
    bool m_hasDoubled;
    int m_num_of_moves;
    std::vector<Piece> m_captured_white;
    std::vector<Piece> m_captured_black;
    Color m_victor;
};

#endif //BACKGAMMON_BACKGAMMONMODEL_H
