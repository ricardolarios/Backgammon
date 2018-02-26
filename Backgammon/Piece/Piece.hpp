//
// Created by Leslie on 11/6/2017.
//

#ifndef BACKGAMMON_PIECE_HPP
#define BACKGAMMON_PIECE_HPP

#include <string>
#include <iostream>
#include "../Color/Color.hpp"

class Piece {

public:

    Piece(Color pieceColor) : m_color(pieceColor) {};

    // Copy Constructor
    Piece(const Piece&);

    Color getColor();

    void setColor(Color color);

    // Returns the m_color as a string
    std::string toString();

private:
    Color m_color;

};


#endif //BACKGAMMON_PIECE_HPP
