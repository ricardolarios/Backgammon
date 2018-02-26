//
// Created by Leslie on 11/6/2017.
//

#include <memory>
#include "Board.hpp"
#include <memory>

using namespace std;

Board::Board() {
    vector<Space> game_board;
    this->m_board = game_board;

    shared_ptr<Space> s1(new Space());
    shared_ptr<Space> s2(new Space());
    shared_ptr<Space> s3(new Space());
    shared_ptr<Space> s4(new Space());
    shared_ptr<Space> s5(new Space());
    shared_ptr<Space> s6(new Space());
    shared_ptr<Space> s7(new Space());
    shared_ptr<Space> s8(new Space());
    shared_ptr<Space> s9(new Space());
    shared_ptr<Space> s10(new Space());
    shared_ptr<Space> s11(new Space());
    shared_ptr<Space> s12(new Space());
    shared_ptr<Space> s13(new Space());
    shared_ptr<Space> s14(new Space());
    shared_ptr<Space> s15(new Space());
    shared_ptr<Space> s16(new Space());
    shared_ptr<Space> s17(new Space());
    shared_ptr<Space> s18(new Space());
    shared_ptr<Space> s19(new Space());
    shared_ptr<Space> s20(new Space());
    shared_ptr<Space> s21(new Space());
    shared_ptr<Space> s22(new Space());
    shared_ptr<Space> s23(new Space());
    shared_ptr<Space> s24(new Space());

    this->m_board.push_back(*s1);
    this->m_board.push_back(*s2);
    this->m_board.push_back(*s3);
    this->m_board.push_back(*s4);
    this->m_board.push_back(*s5);
    this->m_board.push_back(*s6);
    this->m_board.push_back(*s7);
    this->m_board.push_back(*s8);
    this->m_board.push_back(*s9);
    this->m_board.push_back(*s10);
    this->m_board.push_back(*s11);
    this->m_board.push_back(*s12);
    this->m_board.push_back(*s13);
    this->m_board.push_back(*s14);
    this->m_board.push_back(*s15);
    this->m_board.push_back(*s16);
    this->m_board.push_back(*s17);
    this->m_board.push_back(*s18);
    this->m_board.push_back(*s19);
    this->m_board.push_back(*s20);
    this->m_board.push_back(*s21);
    this->m_board.push_back(*s22);
    this->m_board.push_back(*s23);
    this->m_board.push_back(*s24);

    shared_ptr<Piece> b1(new Piece(BLACK));
    shared_ptr<Piece> b2(new Piece(BLACK));
    shared_ptr<Piece> b3(new Piece(BLACK));
    shared_ptr<Piece> b4(new Piece(BLACK));
    shared_ptr<Piece> b5(new Piece(BLACK));
    shared_ptr<Piece> b6(new Piece(BLACK));
    shared_ptr<Piece> b7(new Piece(BLACK));
    shared_ptr<Piece> b8(new Piece(BLACK));
    shared_ptr<Piece> b9(new Piece(BLACK));
    shared_ptr<Piece> b10(new Piece(BLACK));
    shared_ptr<Piece> b11(new Piece(BLACK));
    shared_ptr<Piece> b12(new Piece(BLACK));
    shared_ptr<Piece> b13(new Piece(BLACK));
    shared_ptr<Piece> b14(new Piece(BLACK));
    shared_ptr<Piece> b15(new Piece(BLACK));
    shared_ptr<Piece> w1(new Piece(WHITE));
    shared_ptr<Piece> w2(new Piece(WHITE));
    shared_ptr<Piece> w3(new Piece(WHITE));
    shared_ptr<Piece> w4(new Piece(WHITE));
    shared_ptr<Piece> w5(new Piece(WHITE));
    shared_ptr<Piece> w6(new Piece(WHITE));
    shared_ptr<Piece> w7(new Piece(WHITE));
    shared_ptr<Piece> w8(new Piece(WHITE));
    shared_ptr<Piece> w9(new Piece(WHITE));
    shared_ptr<Piece> w10(new Piece(WHITE));
    shared_ptr<Piece> w11(new Piece(WHITE));
    shared_ptr<Piece> w12(new Piece(WHITE));
    shared_ptr<Piece> w13(new Piece(WHITE));
    shared_ptr<Piece> w14(new Piece(WHITE));
    shared_ptr<Piece> w15(new Piece(WHITE));

    this->m_board[0].setSpaceType(BLACK);
    this->m_board[1].setSpaceType(EMPTY);
    this->m_board[2].setSpaceType(EMPTY);
    this->m_board[3].setSpaceType(EMPTY);
    this->m_board[4].setSpaceType(EMPTY);
    this->m_board[5].setSpaceType(WHITE);
    this->m_board[6].setSpaceType(EMPTY);
    this->m_board[7].setSpaceType(WHITE);
    this->m_board[8].setSpaceType(EMPTY);
    this->m_board[9].setSpaceType(EMPTY);
    this->m_board[10].setSpaceType(EMPTY);
    this->m_board[11].setSpaceType(BLACK);
    this->m_board[12].setSpaceType(WHITE);
    this->m_board[13].setSpaceType(EMPTY);
    this->m_board[14].setSpaceType(EMPTY);
    this->m_board[15].setSpaceType(EMPTY);
    this->m_board[16].setSpaceType(BLACK);
    this->m_board[17].setSpaceType(EMPTY);
    this->m_board[18].setSpaceType(BLACK);
    this->m_board[19].setSpaceType(EMPTY);
    this->m_board[20].setSpaceType(EMPTY);
    this->m_board[21].setSpaceType(EMPTY);
    this->m_board[22].setSpaceType(EMPTY);
    this->m_board[23].setSpaceType(WHITE);

    this->m_board[0].addPiece(*b1);
    this->m_board[0].addPiece(*b2);
    this->m_board[5].addPiece(*w1);
    this->m_board[5].addPiece(*w2);
    this->m_board[5].addPiece(*w3);
    this->m_board[5].addPiece(*w4);
    this->m_board[5].addPiece(*w5);
    this->m_board[7].addPiece(*w6);
    this->m_board[7].addPiece(*w7);
    this->m_board[7].addPiece(*w8);
    this->m_board[11].addPiece(*b3);
    this->m_board[11].addPiece(*b4);
    this->m_board[11].addPiece(*b5);
    this->m_board[11].addPiece(*b6);
    this->m_board[11].addPiece(*b7);
    this->m_board[12].addPiece(*w9);
    this->m_board[12].addPiece(*w10);
    this->m_board[12].addPiece(*w11);
    this->m_board[12].addPiece(*w12);
    this->m_board[12].addPiece(*w13);
    this->m_board[16].addPiece(*b8);
    this->m_board[16].addPiece(*b9);
    this->m_board[16].addPiece(*b10);
    this->m_board[18].addPiece(*b11);
    this->m_board[18].addPiece(*b12);
    this->m_board[18].addPiece(*b13);
    this->m_board[18].addPiece(*b14);
    this->m_board[18].addPiece(*b15);
    this->m_board[23].addPiece(*w14);
    this->m_board[23].addPiece(*w15);

    vector<Piece> whiteCaps;
    vector<Piece> blackCaps;
    this->m_white_captured = whiteCaps;
    this->m_black_captured = blackCaps;

}

void Board::movePiece(int start, int dest) {

    shared_ptr<Piece> newPiece(new Piece(this->m_board[start].getLastPiece()));
    this->m_board[dest].getPieces().push_back(*newPiece);
    this->m_board[start].getPieces().pop_back();

    this->m_board[dest].setSpaceType(this->m_board[start].getSpaceType());
    if (this->m_board[start].getPieces().empty()) {
        this->m_board[start].setSpaceType(EMPTY);
    }

}

/**
 * Generates a string output for the current state of this Board.
 * @return      string of the game state
 */
string Board::toString() {
    string result = "";
    int j = 1;
    for (int i = 0; i < 24; i ++) {
        if (this->m_board[i].getPieces().size() == 0) {
            result += "S" + to_string(j) + ":\n";
        } else {
            result += "S" + to_string(j) + ": " + this->m_board[i].print();
        }
        j++;
    }
    result += "\n";
    return result;
}

std::vector<Space> Board::getSpace() {
    return this->m_board;
}

void Board::capturePiece(int from, int to) {

    Space to_space = this->m_board[to];

    if (to > 23 || to_space.getPieces().size() != 1) {
        throw "Cannot hit this piece.";
    }

    Color to_color = to_space.getSpaceType();

    this->m_board[to].removePiece();

    Piece capturedPiece = Piece(to_color);


    if (to_space.getSpaceType() == BLACK) {
        this->m_black_captured.push_back(capturedPiece);
        to_space.setSpaceType(WHITE);
    }
    else {
        this->m_white_captured.push_back(capturedPiece);
        to_space.setSpaceType(BLACK);
    }

    this->m_board[to].addPiece(this->m_board[from].removePiece());
}

bool Board::isWhiteCaptured() {
    return !this->m_white_captured.empty();
}

bool Board::isBlackCaptured() {
    return !this->m_black_captured.empty();
}

void Board::enterPiece(Color to_add_color, int enter) {
    Space to_enter = this->m_board[enter];


    if (to_add_color == WHITE) {
        if (this->m_board[23 - enter].getSpaceType() == to_add_color
            || (this->m_board[23 - enter].getSpaceType() == EMPTY)) {
            this->m_board[23 - enter].addPiece(Piece(to_add_color));
            this->m_white_captured.pop_back();
        }
        else {
            throw "You cannot enter a piece there.";
        }
    }
    else {
        if (this->m_board[enter].getSpaceType() == to_add_color
                || this->m_board[enter].getSpaceType() == EMPTY) {
            this->m_board[enter].addPiece(Piece(to_add_color));
            this->m_black_captured.pop_back();
        }
        else {
            throw "You cannot enter a piece there.";
        }
    }
}

std::vector<Piece> Board::getBlackCaptured() {
    return std::vector<Piece>(this->m_black_captured);
}

std::vector<Piece> Board::getWhiteCaptured() {
    return std::vector<Piece>(this->m_white_captured);
}

std::vector<Piece> Board::getWhiteEntered() {
    return this->m_white_entered;
}

std::vector<Piece> Board::getBlackEntered() {
    return this->m_black_entered;
}