//
// Created by Leslie on 11/6/2017.
//

#ifndef BACKGAMMON_SPACE_HPP
#define BACKGAMMON_SPACE_HPP

#include "../Piece/Piece.hpp"
#include <vector>
#include <string>
#include <iostream>

class Space {

public:

    Space() : m_space() {};

    //Puts piece at the end of the vector if this space's m_color matches the piece m_color
    void addPiece(Piece piece);

    //Removes the last piece in the space, and returns it.
    Piece removePiece();

    std::vector<Piece> &getPieces();

    Piece &getLastPiece();

    Color getSpaceType();

    void setSpaceType(Color color);

    //Prints each piece in this space in the form of [Number]: [Color]
    std::string print();

private:
    //2d vector
    std::vector<Piece> m_space;
    Color m_spaceType;

};


#endif //BACKGAMMON_SPACE_HPP