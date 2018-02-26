//
// Created by Leslie on 11/6/2017.
//

#ifndef BACKGAMMON_BOARD_HPP
#define BACKGAMMON_BOARD_HPP

#include "../Space/Space.hpp"
#include "../Player/Player.h"

// Represents a board for a Backgammon game.
class Board {

public:
    Board();
    //Moves a piece from space a to space b, does nothing if not a valid move.
    void movePiece(int start, int dest); //not sure why this suggestion is thrown, also might have an error where a isn't changed.
    // Generates a string output for the current state of this Board.
    std::string toString();
    // Returns a reference to the spaces of this board.
    std::vector<Space> getSpace();
    void capturePiece(int, int);
    bool isWhiteCaptured();
    bool isBlackCaptured();
    void enterPiece(Color, int);
    std::vector<Piece> getWhiteCaptured();
    std::vector<Piece> getBlackCaptured();
    std::vector<Piece> getWhiteEntered();
    std::vector<Piece> getBlackEntered();


private:
    std::vector<Space> m_board;
    std::vector<Piece> m_white_captured;
    std::vector<Piece> m_black_captured;
    std::vector<Piece> m_white_entered;
    std::vector<Piece> m_black_entered;
};


#endif //BACKGAMMON_BOARD_HPP
