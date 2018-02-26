/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_BackgammonTestSuite_init = false;
#include "BackgammonTestSuite.h"

static BackgammonTestSuite suite_BackgammonTestSuite;

static CxxTest::List Tests_BackgammonTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_BackgammonTestSuite( "BackgammonTestSuite.h", 22, "BackgammonTestSuite", suite_BackgammonTestSuite, Tests_BackgammonTestSuite );

static class TestDescription_suite_BackgammonTestSuite_testStartOfGameBoard : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testStartOfGameBoard() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 24, "testStartOfGameBoard" ) {}
 void runTest() { suite_BackgammonTestSuite.testStartOfGameBoard(); }
} testDescription_suite_BackgammonTestSuite_testStartOfGameBoard;

static class TestDescription_suite_BackgammonTestSuite_testMovePieceBlack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testMovePieceBlack() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 57, "testMovePieceBlack" ) {}
 void runTest() { suite_BackgammonTestSuite.testMovePieceBlack(); }
} testDescription_suite_BackgammonTestSuite_testMovePieceBlack;

static class TestDescription_suite_BackgammonTestSuite_testMovePieceWhite : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testMovePieceWhite() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 91, "testMovePieceWhite" ) {}
 void runTest() { suite_BackgammonTestSuite.testMovePieceWhite(); }
} testDescription_suite_BackgammonTestSuite_testMovePieceWhite;

static class TestDescription_suite_BackgammonTestSuite_testCaptureBlackPiece : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testCaptureBlackPiece() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 125, "testCaptureBlackPiece" ) {}
 void runTest() { suite_BackgammonTestSuite.testCaptureBlackPiece(); }
} testDescription_suite_BackgammonTestSuite_testCaptureBlackPiece;

static class TestDescription_suite_BackgammonTestSuite_testCaptureWhitePiece : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testCaptureWhitePiece() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 162, "testCaptureWhitePiece" ) {}
 void runTest() { suite_BackgammonTestSuite.testCaptureWhitePiece(); }
} testDescription_suite_BackgammonTestSuite_testCaptureWhitePiece;

static class TestDescription_suite_BackgammonTestSuite_testCapturePieceThrows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testCapturePieceThrows() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 199, "testCapturePieceThrows" ) {}
 void runTest() { suite_BackgammonTestSuite.testCapturePieceThrows(); }
} testDescription_suite_BackgammonTestSuite_testCapturePieceThrows;

static class TestDescription_suite_BackgammonTestSuite_testEnterBlackPiece : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testEnterBlackPiece() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 205, "testEnterBlackPiece" ) {}
 void runTest() { suite_BackgammonTestSuite.testEnterBlackPiece(); }
} testDescription_suite_BackgammonTestSuite_testEnterBlackPiece;

static class TestDescription_suite_BackgammonTestSuite_testEnterWhitePiece : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testEnterWhitePiece() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 241, "testEnterWhitePiece" ) {}
 void runTest() { suite_BackgammonTestSuite.testEnterWhitePiece(); }
} testDescription_suite_BackgammonTestSuite_testEnterWhitePiece;

static class TestDescription_suite_BackgammonTestSuite_testEnterPieceBoardThrows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testEnterPieceBoardThrows() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 277, "testEnterPieceBoardThrows" ) {}
 void runTest() { suite_BackgammonTestSuite.testEnterPieceBoardThrows(); }
} testDescription_suite_BackgammonTestSuite_testEnterPieceBoardThrows;

static class TestDescription_suite_BackgammonTestSuite_testRoll : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testRoll() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 283, "testRoll" ) {}
 void runTest() { suite_BackgammonTestSuite.testRoll(); }
} testDescription_suite_BackgammonTestSuite_testRoll;

static class TestDescription_suite_BackgammonTestSuite_testCompareRoll : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testCompareRoll() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 292, "testCompareRoll" ) {}
 void runTest() { suite_BackgammonTestSuite.testCompareRoll(); }
} testDescription_suite_BackgammonTestSuite_testCompareRoll;

static class TestDescription_suite_BackgammonTestSuite_testReturnNewDice : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testReturnNewDice() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 300, "testReturnNewDice" ) {}
 void runTest() { suite_BackgammonTestSuite.testReturnNewDice(); }
} testDescription_suite_BackgammonTestSuite_testReturnNewDice;

static class TestDescription_suite_BackgammonTestSuite_testIsUsed : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testIsUsed() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 306, "testIsUsed" ) {}
 void runTest() { suite_BackgammonTestSuite.testIsUsed(); }
} testDescription_suite_BackgammonTestSuite_testIsUsed;

static class TestDescription_suite_BackgammonTestSuite_testDoubleValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testDoubleValue() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 318, "testDoubleValue" ) {}
 void runTest() { suite_BackgammonTestSuite.testDoubleValue(); }
} testDescription_suite_BackgammonTestSuite_testDoubleValue;

static class TestDescription_suite_BackgammonTestSuite_testPieceToString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testPieceToString() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 339, "testPieceToString" ) {}
 void runTest() { suite_BackgammonTestSuite.testPieceToString(); }
} testDescription_suite_BackgammonTestSuite_testPieceToString;

static class TestDescription_suite_BackgammonTestSuite_testSamePlayer : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testSamePlayer() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 348, "testSamePlayer" ) {}
 void runTest() { suite_BackgammonTestSuite.testSamePlayer(); }
} testDescription_suite_BackgammonTestSuite_testSamePlayer;

static class TestDescription_suite_BackgammonTestSuite_testDifferentPlayers1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testDifferentPlayers1() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 362, "testDifferentPlayers1" ) {}
 void runTest() { suite_BackgammonTestSuite.testDifferentPlayers1(); }
} testDescription_suite_BackgammonTestSuite_testDifferentPlayers1;

static class TestDescription_suite_BackgammonTestSuite_testDifferentPlayers2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testDifferentPlayers2() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 376, "testDifferentPlayers2" ) {}
 void runTest() { suite_BackgammonTestSuite.testDifferentPlayers2(); }
} testDescription_suite_BackgammonTestSuite_testDifferentPlayers2;

static class TestDescription_suite_BackgammonTestSuite_testAddPiece : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testAddPiece() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 390, "testAddPiece" ) {}
 void runTest() { suite_BackgammonTestSuite.testAddPiece(); }
} testDescription_suite_BackgammonTestSuite_testAddPiece;

static class TestDescription_suite_BackgammonTestSuite_testRemovePiece : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testRemovePiece() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 415, "testRemovePiece" ) {}
 void runTest() { suite_BackgammonTestSuite.testRemovePiece(); }
} testDescription_suite_BackgammonTestSuite_testRemovePiece;

static class TestDescription_suite_BackgammonTestSuite_testSpacePrint : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testSpacePrint() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 440, "testSpacePrint" ) {}
 void runTest() { suite_BackgammonTestSuite.testSpacePrint(); }
} testDescription_suite_BackgammonTestSuite_testSpacePrint;

static class TestDescription_suite_BackgammonTestSuite_testGetStartGameState : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testGetStartGameState() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 463, "testGetStartGameState" ) {}
 void runTest() { suite_BackgammonTestSuite.testGetStartGameState(); }
} testDescription_suite_BackgammonTestSuite_testGetStartGameState;

static class TestDescription_suite_BackgammonTestSuite_testGetStartGameDoubleCubeState : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testGetStartGameDoubleCubeState() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 499, "testGetStartGameDoubleCubeState" ) {}
 void runTest() { suite_BackgammonTestSuite.testGetStartGameDoubleCubeState(); }
} testDescription_suite_BackgammonTestSuite_testGetStartGameDoubleCubeState;

static class TestDescription_suite_BackgammonTestSuite_testDoubled : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testDoubled() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 568, "testDoubled" ) {}
 void runTest() { suite_BackgammonTestSuite.testDoubled(); }
} testDescription_suite_BackgammonTestSuite_testDoubled;

static class TestDescription_suite_BackgammonTestSuite_testRolled : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testRolled() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 576, "testRolled" ) {}
 void runTest() { suite_BackgammonTestSuite.testRolled(); }
} testDescription_suite_BackgammonTestSuite_testRolled;

static class TestDescription_suite_BackgammonTestSuite_testIsValidMoveInvalidMove : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testIsValidMoveInvalidMove() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 584, "testIsValidMoveInvalidMove" ) {}
 void runTest() { suite_BackgammonTestSuite.testIsValidMoveInvalidMove(); }
} testDescription_suite_BackgammonTestSuite_testIsValidMoveInvalidMove;

static class TestDescription_suite_BackgammonTestSuite_testEnterPieceModelThrows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testEnterPieceModelThrows() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 607, "testEnterPieceModelThrows" ) {}
 void runTest() { suite_BackgammonTestSuite.testEnterPieceModelThrows(); }
} testDescription_suite_BackgammonTestSuite_testEnterPieceModelThrows;

static class TestDescription_suite_BackgammonTestSuite_testSetUsed : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testSetUsed() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 613, "testSetUsed" ) {}
 void runTest() { suite_BackgammonTestSuite.testSetUsed(); }
} testDescription_suite_BackgammonTestSuite_testSetUsed;

static class TestDescription_suite_BackgammonTestSuite_testDiceToString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testDiceToString() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 623, "testDiceToString" ) {}
 void runTest() { suite_BackgammonTestSuite.testDiceToString(); }
} testDescription_suite_BackgammonTestSuite_testDiceToString;

static class TestDescription_suite_BackgammonTestSuite_testCompareDice : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testCompareDice() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 633, "testCompareDice" ) {}
 void runTest() { suite_BackgammonTestSuite.testCompareDice(); }
} testDescription_suite_BackgammonTestSuite_testCompareDice;

static class TestDescription_suite_BackgammonTestSuite_testDiceConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testDiceConstructor() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 649, "testDiceConstructor" ) {}
 void runTest() { suite_BackgammonTestSuite.testDiceConstructor(); }
} testDescription_suite_BackgammonTestSuite_testDiceConstructor;

static class TestDescription_suite_BackgammonTestSuite_testGetSpace : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testGetSpace() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 667, "testGetSpace" ) {}
 void runTest() { suite_BackgammonTestSuite.testGetSpace(); }
} testDescription_suite_BackgammonTestSuite_testGetSpace;

static class TestDescription_suite_BackgammonTestSuite_testIsCapturedBlack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testIsCapturedBlack() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 673, "testIsCapturedBlack" ) {}
 void runTest() { suite_BackgammonTestSuite.testIsCapturedBlack(); }
} testDescription_suite_BackgammonTestSuite_testIsCapturedBlack;

static class TestDescription_suite_BackgammonTestSuite_testIsCapturedWhite : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BackgammonTestSuite_testIsCapturedWhite() : CxxTest::RealTestDescription( Tests_BackgammonTestSuite, suiteDescription_BackgammonTestSuite, 685, "testIsCapturedWhite" ) {}
 void runTest() { suite_BackgammonTestSuite.testIsCapturedWhite(); }
} testDescription_suite_BackgammonTestSuite_testIsCapturedWhite;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
