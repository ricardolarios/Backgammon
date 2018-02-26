//
// Created by Daniel Nachum on 12/3/17.
//

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <memory>
#include <cstddef>
#include "Board/Board.cpp"
#include "controller/TextController.cpp"
#include "Dice/Dice.cpp"
#include "DoublingCube/DoublingCube.cpp"
#include "model/BackgammonModel.cpp"
#include "Piece/Piece.cpp"
#include "Player/Player.cpp"
#include "Points/Points.cpp"
#include "Space/Space.cpp"
#include "view/TextView.cpp"

using namespace std;

class BackgammonTestSuite : public CxxTest::TestSuite {
public:
    void testStartOfGameBoard() {
        Board *b1 = new Board();
        string boardStart = "S1: Black, Black\n"
                "S2:\n"
                "S3:\n"
                "S4:\n"
                "S5:\n"
                "S6: White, White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n\n";
        TS_ASSERT_EQUALS(b1->toString(), boardStart);
        TS_ASSERT_EQUALS(b1->getSpace()[0].getSpaceType(), BLACK);
        TS_ASSERT_EQUALS(b1->getSpace()[1].getSpaceType(), EMPTY);
        TS_ASSERT_EQUALS(b1->getSpace()[5].getSpaceType(), WHITE);
        delete b1;
    }

    void testMovePieceBlack() {
        Board *b1 = new Board();
        string currentBoard = "S1: Black\n"
                "S2:\n"
                "S3: Black\n"
                "S4:\n"
                "S5:\n"
                "S6: White, White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n\n";
        TS_ASSERT_EQUALS(b1->getSpace()[2].getSpaceType(), EMPTY);
        b1->movePiece(0, 2);
        TS_ASSERT_DIFFERS(b1->getSpace()[2].getSpaceType(), EMPTY);
        TS_ASSERT_EQUALS(b1->getSpace()[2].getSpaceType(), BLACK);
        TS_ASSERT_EQUALS(b1->toString(), currentBoard);
        delete b1;
    }

    void testMovePieceWhite() {
        Board *b1 = new Board();
        string currentBoard = "S1: Black, Black\n"
                "S2:\n"
                "S3:\n"
                "S4: White\n"
                "S5:\n"
                "S6: White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n\n";
        TS_ASSERT_EQUALS(b1->getSpace()[3].getSpaceType(), EMPTY);
        b1->movePiece(5, 3);
        TS_ASSERT_DIFFERS(b1->getSpace()[3].getSpaceType(), EMPTY);
        TS_ASSERT_EQUALS(b1->getSpace()[3].getSpaceType(), WHITE);
        TS_ASSERT_EQUALS(b1->toString(), currentBoard);
        delete b1;
    }

    void testCaptureBlackPiece() {
        Board *b1 = new Board();
        string currentBoard = "S1: Black\n"
                "S2:\n"
                "S3:\n"
                "S4: White\n"
                "S5:\n"
                "S6: White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n\n";
        TS_ASSERT_EQUALS(b1->getSpace()[3].getSpaceType(), EMPTY);
        b1->movePiece(0, 3);
        TS_ASSERT_DIFFERS(b1->getSpace()[3].getSpaceType(), EMPTY);
        TS_ASSERT_EQUALS(b1->getSpace()[3].getSpaceType(), BLACK);
        b1->capturePiece(5, 3);
        TS_ASSERT_EQUALS(b1->toString(), currentBoard);
        TS_ASSERT(b1->isBlackCaptured());
        TS_ASSERT(!b1->getBlackCaptured().empty());
        delete b1;
    }

    void testCaptureWhitePiece() {
        Board *b1 = new Board();
        string currentBoard = "S1: Black\n"
                "S2:\n"
                "S3:\n"
                "S4: Black\n"
                "S5:\n"
                "S6: White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n\n";
        TS_ASSERT_EQUALS(b1->getSpace()[3].getSpaceType(), EMPTY);
        b1->movePiece(5, 3);
        TS_ASSERT_DIFFERS(b1->getSpace()[3].getSpaceType(), EMPTY);
        TS_ASSERT_EQUALS(b1->getSpace()[3].getSpaceType(), WHITE);
        b1->capturePiece(0, 3);
        TS_ASSERT_EQUALS(b1->toString(), currentBoard);
        TS_ASSERT(b1->isWhiteCaptured());
        TS_ASSERT(!b1->getWhiteCaptured().empty());
        delete b1;
    }

    void testCapturePieceThrows() {
        Board *b1 = new Board();
        TS_ASSERT_THROWS_ANYTHING(b1->capturePiece(4, 5));
        delete b1;
    }

    void testEnterBlackPiece() {
        Board *b1 = new Board();
        string currentBoard = "S1: Black\n"
                "S2: Black\n"
                "S3:\n"
                "S4: White\n"
                "S5:\n"
                "S6: White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n\n";
        b1->movePiece(0, 3);
        b1->capturePiece(5, 3);
        TS_ASSERT(!b1->getBlackCaptured().empty());
        TS_ASSERT_THROWS_ANYTHING(b1->enterPiece(BLACK, 3));
        b1->enterPiece(BLACK, 1);
        TS_ASSERT(b1->getBlackCaptured().empty());
        TS_ASSERT_EQUALS(b1->toString(), currentBoard);
        delete b1;
    }

    void testEnterWhitePiece() {
        Board *b1 = new Board();
        string currentBoard = "S1: Black\n"
                "S2:\n"
                "S3:\n"
                "S4: Black\n"
                "S5:\n"
                "S6: White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22: White\n"
                "S23:\n"
                "S24: White, White\n\n";
        b1->movePiece(5, 3);
        b1->capturePiece(0, 3);
        TS_ASSERT(!b1->getWhiteCaptured().empty());
        TS_ASSERT_THROWS_ANYTHING(b1->enterPiece(WHITE, 5));
        b1->enterPiece(WHITE, 2);
        TS_ASSERT(b1->getWhiteCaptured().empty());
        TS_ASSERT_EQUALS(b1->toString(), currentBoard);
        delete b1;
    }

    void testEnterPieceBoardThrows() {
        Board *b1 = new Board();
        TS_ASSERT_THROWS_ANYTHING(b1->enterPiece(BLACK, 5));
        delete b1;
    }

    void testRoll() {
        Dice *d1 = new Dice();
        d1->roll();
        TS_ASSERT_LESS_THAN_EQUALS(d1->getValue(), 6);
        TS_ASSERT_DIFFERS(d1->getValue(), 0);
        TS_ASSERT_DIFFERS(d1->getValue(), -1);
        delete d1;
    }

    void testCompareRoll() {
        Dice *d1 = new Dice();
        Dice *d2 = new Dice();
        TS_ASSERT(d1->compareDice(*d2));
        delete d1;
        delete d2;
    }

    void testReturnNewDice() {
        Dice *d1 = new Dice();
        TS_ASSERT_EQUALS(d1->returnNewDice().size(), 2);
        delete d1;
    }

    void testIsUsed() {
        Dice *d1 = new Dice();
        Dice *d2 = new Dice();
        d1->setUsed(true);
        TS_ASSERT(d1->isUsed());
        TS_ASSERT(!d2->isUsed());
        d2->setUsed(true);
        TS_ASSERT(d2->isUsed());
        delete d1;
        delete d2;
    }

    void testDoubleValue() {
        DoublingCube *d1 = new DoublingCube();
        TS_ASSERT_EQUALS(d1->getValue(), 1);
        d1->doubleValue();
        TS_ASSERT_EQUALS(d1->getValue(), 2);
        d1->doubleValue();
        TS_ASSERT_EQUALS(d1->getValue(), 4);
        d1->doubleValue();
        TS_ASSERT_EQUALS(d1->getValue(), 8);
        d1->doubleValue();
        TS_ASSERT_EQUALS(d1->getValue(), 16);
        d1->doubleValue();
        TS_ASSERT_EQUALS(d1->getValue(), 32);
        d1->doubleValue();
        TS_ASSERT_EQUALS(d1->getValue(), 64);
        d1->doubleValue();
        TS_ASSERT_DIFFERS(d1->getValue(), 132);
        TS_ASSERT_EQUALS(d1->getValue(), 64);
        delete d1;
    }

    void testPieceToString() {
        Piece *p1 = new Piece(BLACK);
        Piece *p2 = new Piece(WHITE);
        TS_ASSERT_EQUALS(p1->toString(), "Black");
        TS_ASSERT_EQUALS(p2->toString(), "White");
        delete p1;
        delete p2;
    }

    void testSamePlayer() {
        Player *p1 = new Player();
        Player *p2 = new Player();
        p1->setName("Mario");
        p1->setColor(BLACK);
        p2->setName("Mario");
        p2->setColor(BLACK);
        const Player &p3 = *p1;
        const Player &p4 = *p2;
        TS_ASSERT(p3 == p4);
        delete p1;
        delete p2;
    }

    void testDifferentPlayers1() {
        Player *p1 = new Player();
        Player *p2 = new Player();
        p1->setName("Mario");
        p1->setColor(BLACK);
        p2->setName("Wario");
        p2->setColor(BLACK);
        const Player &p3 = *p1;
        const Player &p4 = *p2;
        TS_ASSERT(p3 != p4);
        delete p1;
        delete p2;
    }

    void testDifferentPlayers2() {
        Player *p1 = new Player();
        Player *p2 = new Player();
        p1->setName("Mario");
        p1->setColor(BLACK);
        p2->setName("Mario");
        p2->setColor(WHITE);
        const Player &p3 = *p1;
        const Player &p4 = *p2;
        TS_ASSERT(p3 != p4);
        delete p1;
        delete p2;
    }

    void testAddPiece() {
        Space *s1 = new Space();
        Space *s2 = new Space();
        s1->setSpaceType(EMPTY);
        s2->setSpaceType(EMPTY);
        TS_ASSERT(s1->getPieces().empty());
        TS_ASSERT(s2->getPieces().empty());
        Piece *p1 = new Piece(BLACK);
        s1->addPiece(*p1);
        TS_ASSERT_EQUALS(s1->getPieces().size(), 1);
        TS_ASSERT_EQUALS(s1->getSpaceType(), BLACK);
        Piece *p2 = new Piece(WHITE);
        s2->addPiece(*p2);
        TS_ASSERT_EQUALS(s2->getPieces().size(), 1);
        TS_ASSERT_EQUALS(s2->getSpaceType(), WHITE);
        s1->addPiece(*p2);
        s2->addPiece(*p2);
        TS_ASSERT_EQUALS(s1->getPieces().size(), 1);
        TS_ASSERT_EQUALS(s2->getPieces().size(), 2);
        delete p1;
        delete p2;
        delete s1;
        delete s2;
    }

    void testRemovePiece() {
        Space *s1 = new Space();
        Space *s2 = new Space();
        s1->setSpaceType(EMPTY);
        s2->setSpaceType(EMPTY);
        Piece *p1 = new Piece(BLACK);
        s1->addPiece(*p1);
        Piece *p2 = new Piece(WHITE);
        s2->addPiece(*p2);
        TS_ASSERT_EQUALS(s1->getPieces().size(), 1);
        TS_ASSERT_EQUALS(s2->getPieces().size(), 1);
        TS_ASSERT_EQUALS(s1->getSpaceType(), BLACK);
        TS_ASSERT_EQUALS(s2->getSpaceType(), WHITE);
        s1->removePiece();
        s2->removePiece();
        TS_ASSERT(s1->getPieces().empty());
        TS_ASSERT(s2->getPieces().empty());
        TS_ASSERT_EQUALS(s1->getSpaceType(), EMPTY);
        TS_ASSERT_EQUALS(s2->getSpaceType(), EMPTY);
        delete p1;
        delete p2;
        delete s1;
        delete s2;
    }

    void testSpacePrint() {
        Space *s1 = new Space();
        Space *s2 = new Space();
        s1->setSpaceType(EMPTY);
        s2->setSpaceType(EMPTY);
        TS_ASSERT_EQUALS(s1->print(), "");
        TS_ASSERT_EQUALS(s2->print(), "");
        Piece *p1 = new Piece(BLACK);
        s1->addPiece(*p1);
        Piece *p2 = new Piece(WHITE);
        s2->addPiece(*p2);
        TS_ASSERT_EQUALS(s1->print(), "Black\n");
        TS_ASSERT_EQUALS(s2->print(), "White\n");
        s1->addPiece(*p1);
        s2->addPiece(*p2);
        TS_ASSERT_EQUALS(s1->print(), "Black, Black\n");
        TS_ASSERT_EQUALS(s2->print(), "White, White\n");
        delete p1;
        delete p2;
        delete s1;
        delete s2;
    }

    void testGetStartGameState() {
        BackgammonModel *b1 = new BackgammonModel();
        string startGameState = "S1: Black, Black\n"
                "S2:\n"
                "S3:\n"
                "S4:\n"
                "S5:\n"
                "S6: White, White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n"
                "\n"
                "White pieces to be entered: \n"
                "Black pieces to be entered: \n"
                "Moves left: 0\n"
                "Current Doubling Cube: 1\n"
                "Please roll dice or doubling cube.\n";
        TS_ASSERT_EQUALS(b1->getGameState(), startGameState);
        delete b1;
    }

    void testGetStartGameDoubleCubeState() {
        BackgammonModel *b1 = new BackgammonModel();
        string startGameState = "S1: Black, Black\n"
                "S2:\n"
                "S3:\n"
                "S4:\n"
                "S5:\n"
                "S6: White, White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n"
                "\n"
                "White pieces to be entered: \n"
                "Black pieces to be entered: \n"
                "Moves left: 0\n"
                "Current Doubling Cube: 2\n"
                "Please roll dice.\n";
        string startGameState2 = "S1: Black, Black\n"
                "S2:\n"
                "S3:\n"
                "S4:\n"
                "S5:\n"
                "S6: White, White, White, White, White\n"
                "S7:\n"
                "S8: White, White, White\n"
                "S9:\n"
                "S10:\n"
                "S11:\n"
                "S12: Black, Black, Black, Black, Black\n"
                "S13: White, White, White, White, White\n"
                "S14:\n"
                "S15:\n"
                "S16:\n"
                "S17: Black, Black, Black\n"
                "S18:\n"
                "S19: Black, Black, Black, Black, Black\n"
                "S20:\n"
                "S21:\n"
                "S22:\n"
                "S23:\n"
                "S24: White, White\n"
                "\n"
                "White pieces to be entered: \n"
                "Black pieces to be entered: \n"
                "Moves left: 0\n"
                "Current Doubling Cube: 4\n"
                "Please roll dice.\n";
        b1->rollDoublingCube();
        TS_ASSERT_EQUALS(b1->getGameState(), startGameState);
        b1->rollDoublingCube();
        TS_ASSERT_EQUALS(b1->getGameState(), startGameState2);
        delete b1;
    }

    void testDoubled() {
        BackgammonModel *b1 = new BackgammonModel();
        TS_ASSERT(!b1->doubled());
        b1->rollDoublingCube();
        TS_ASSERT(b1->doubled());
        delete b1;
    }

    void testRolled() {
        BackgammonModel *b1 = new BackgammonModel();
        TS_ASSERT(!b1->rolled());
        b1->rollDice();
        TS_ASSERT(b1->rolled());
        delete b1;
    }

    void testIsValidMoveInvalidMove() {
        BackgammonModel *b1 = new BackgammonModel();
        Player *p1 = new Player();
        Player *p2 = new Player();
        TS_ASSERT(b1->isValidMove(0, 1, *p1));
        TS_ASSERT(b1->isValidMove(0, 1, *p2));
        p1->setColor(BLACK);
        p2->setColor(WHITE);
        b1->setPlayers(*p1, *p2);
        b1->rollDice();
        TS_ASSERT(!b1->isValidMove(0, 5, *p1));
        TS_ASSERT(!b1->isValidMove(5, 0, *p1));
        TS_ASSERT(!b1->isValidMove(5, 1, *p1));
        TS_ASSERT(!b1->isValidMove(0, 5, *p2));
        TS_ASSERT(!b1->isValidMove(5, 0, *p2));
        TS_ASSERT(!b1->isValidMove(0, 4, *p2));
        TS_ASSERT(!b1->isValidMove(2, 3, *p2));
        TS_ASSERT(!b1->isValidMove(2, 3, *p2));
        delete p1;
        delete p2;
        delete b1;
    }

    void testEnterPieceModelThrows() {
        BackgammonModel *b1 = new BackgammonModel();
        TS_ASSERT_THROWS_ANYTHING(b1->enterPiece(BLACK, 7));
        delete b1;
    }

    void testSetUsed() {
        Dice *d1 = new Dice();
        TS_ASSERT(!d1->isUsed());
        d1->setUsed(true);
        TS_ASSERT(d1->isUsed());
        d1->setUsed(false);
        TS_ASSERT(!d1->isUsed());
        delete d1;
    }

    void testDiceToString() {
        Dice *d1 = new Dice();
        TS_ASSERT_EQUALS(d1->toString(), "1");
        d1->roll();
        TS_ASSERT_EQUALS(d1->toString(), TS_AS_STRING(d1->getValue()));
        d1->roll();
        TS_ASSERT_EQUALS(d1->toString(), TS_AS_STRING(d1->getValue()));
        delete d1;
    }

    void testCompareDice() {
        Dice *d1 = new Dice();
        Dice *d2 = new Dice();
        d1->roll();
        d2->roll();
        if (d1->getValue() == d2->getValue()) {
            TS_ASSERT(d1->compareDice(*d2));
            TS_ASSERT(d2->compareDice(*d1));
        } else {
            TS_ASSERT(!d1->compareDice(*d2));
            TS_ASSERT(!d2->compareDice(*d1));
        }
        delete d1;
        delete d2;
    }

    void testDiceConstructor() {
        Dice *d1 = new Dice();
        TS_ASSERT_EQUALS(d1->getValue(), 1);
        d1 = new Dice(1);
        TS_ASSERT_EQUALS(d1->getValue(), 1);
        d1 = new Dice(2);
        TS_ASSERT_EQUALS(d1->getValue(), 2);
        d1 = new Dice(3);
        TS_ASSERT_EQUALS(d1->getValue(), 3);
        d1 = new Dice(4);
        TS_ASSERT_EQUALS(d1->getValue(), 4);
        d1 = new Dice(5);
        TS_ASSERT_EQUALS(d1->getValue(), 5);
        d1 = new Dice(6);
        TS_ASSERT_EQUALS(d1->getValue(), 6);
        delete d1;
    }

    void testGetSpace() {
        Board *b1 = new Board();
        TS_ASSERT_EQUALS(b1->getSpace().size(), 24);
        delete b1;
    }

    void testIsCapturedBlack() {
        Board *b1 = new Board();
        TS_ASSERT(b1->getBlackCaptured().empty());
        b1->movePiece(0, 3);
        b1->capturePiece(5, 3);
        TS_ASSERT(b1->isBlackCaptured());
        TS_ASSERT_EQUALS(b1->getBlackCaptured().size(), 1);
        b1->capturePiece(3, 0);
        TS_ASSERT_EQUALS(b1->getBlackCaptured().size(), 2);
        delete b1;
    }

    void testIsCapturedWhite() {
        Board *b1 = new Board();
        TS_ASSERT(b1->getWhiteCaptured().empty());
        b1->movePiece(5, 3);
        b1->capturePiece(0, 3);
        TS_ASSERT(b1->isWhiteCaptured());
        TS_ASSERT_EQUALS(b1->getWhiteCaptured().size(), 1);
        b1->movePiece(23, 22);
        b1->capturePiece(3, 22);
        TS_ASSERT_EQUALS(b1->getWhiteCaptured().size(), 2);
        delete b1;
    }


};
