
//
// Created by Leslie on 11/6/2017.
//

#include "Piece.hpp"

using namespace std;

Color Piece::getColor() {
    return this->m_color;
}

Piece::Piece(const Piece & piece) {
    this->m_color = piece.m_color;
}

void Piece::setColor(Color color) {
    this->m_color = color;
}

// Returns the m_color as a string
std::string Piece::toString() {
    if (getColor() == BLACK) {
        return "Black";
    }
    else {
        return "White";
    }
}