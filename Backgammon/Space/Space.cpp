
//
// Created by Leslie on 11/6/2017.
//

#include "Space.hpp"

using namespace std;

//Puts piece at the end of the vector if this space's m_color matches the piece m_color
void Space::addPiece(Piece piece) {
    if (this->getSpaceType() == piece.getColor() || this->getSpaceType() == EMPTY) {
        this->m_space.push_back(piece);
    }

    if (this->m_spaceType == EMPTY) {
        this->m_spaceType = piece.getColor();
    }
}

//Removes the last piece in the space
Piece Space::removePiece() {
    Piece top = Piece(this->m_space.back());
    this->m_space.pop_back();

    if (this->m_space.empty()) {
        this->m_spaceType = EMPTY;
    }

    return top;
}

vector<Piece> &Space::getPieces() {
    return this->m_space;
}

Piece &Space::getLastPiece() {
    return this->m_space.back();
}

Color Space::getSpaceType() {
    return this->m_spaceType;
}

void Space::setSpaceType(Color color) {
    this->m_spaceType = color;
}

//Prints each piece in this space in the form of [Number]: [Color]
std::string Space::print() {
    string ret = "";
    if (this->m_space.empty()) {
        ret += "";
    }
    for (int i = 0; i < this->m_space.size() ; i++) {
        ret += this->getPieces()[i].toString();

        if (i == this->m_space.size() - 1) {
            ret += "\n";
        }
        else {
            ret += ", ";
        }
    }

    return ret;
}
