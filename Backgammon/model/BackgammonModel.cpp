//
// Created by Rikki on 11/8/2017.
//


#include "BackgammonModel.h"
#include "../view/TextView.h"
#include "../controller/IController.h"
#include "../controller/TextController.h"
#include <iostream>
#include <memory>

using namespace std;

/**
 * Gets the current state of the game as a String. Maybe change idk.
 * @return          the current state of the game.
 */
string BackgammonModel::getGameState() {
    string result = "";
    result.append(this->m_board.toString());

    result.append("White pieces to be entered: ");
    for (Piece p : this->m_captured_white) {
        result.append(p.toString());
    }

    result.append("\nBlack pieces to be entered: ");
    for (Piece p : this->m_captured_black) {
        result.append(p.toString());
    }

    result.append("\n");

    result.append("Moves left: " + std::to_string(this->m_num_of_moves) + "\n");
    result.append("Current Doubling Cube: ");
    result.append(this->m_doublingCube.toString()).append("\n");

    if (!this->m_hasRolled) {
        if (!this->m_hasDoubled) {
            result.append("Please roll dice or doubling cube.\n");
        } else {
            result.append("Please roll dice.\n");
        }

    } else {
        result.append("Die 1: ");
        result.append(this->m_die1.toString());
        result.append(" Die 2: ");
        result.append(this->m_die2.toString());
        result.append("\n");
    }

    return result;
}

void BackgammonModel::startGame() {
    string player1_name;
    string player2_name;
    cout << "Welcome to Backgammon! Player 1, input your name: " << endl;
    getline(cin, player1_name);
    m_player1.setName(player1_name);
    cout << "Player 2, input your name: " << endl;
    getline(cin, player2_name);
    m_player2.setName(player2_name);
    string player1_color;
    cout << player1_name << ", choose a color. Type either \"black\" or \"white.\"" << endl;
    getline(cin, player1_color);

    while (true) {
        if (player1_color == "black") {
            m_player1.setColor(BLACK);
            m_player2.setColor(WHITE);
            break;
        } else if (player1_color == "white") {
            m_player1.setColor(WHITE);
            m_player2.setColor(BLACK);
            break;
        } else {
            cout << "Please enter a valid color, either \"black\" or \"white\"." << endl;
            getline(cin, player1_color);
        }
    }
}

void BackgammonModel::rollDice() {
    this->m_die1.roll();
    this->m_die2.roll();

    if (this->m_die2.getValue() == this->m_die1.getValue()) {
        this->m_num_of_moves = 4;
    } else {
        this->m_num_of_moves = 2;
    }
    this->m_hasRolled = true;
}

/**
 * Doubles the value of the doubling cube.
 */
void BackgammonModel::rollDoublingCube() {
    this->m_doublingCube.doubleValue();
    this->m_hasDoubled = true;
}

Player BackgammonModel::getPlayer1() {
    return this->m_player1;
}

Player BackgammonModel::getPlayer2() {
    return this->m_player2;
}

Points BackgammonModel::getPoints() {
    return this->m_points;
}

/**
 * Incomplete.
 */
string BackgammonModel::getPointsString() {

    return "";
}

void BackgammonModel::move(int from, int to) {

    Space from_space = this->m_board.getSpace()[from];
    Space to_space = this->m_board.getSpace()[to];


    if (to_space.getPieces().size() == 1 && to_space.getSpaceType() != from_space.getSpaceType()) {
        std::cout << "Space before capture: " << this->m_board.getSpace()[to].print() << std::endl;

        this->m_board.capturePiece(from, to);

        this->m_captured_black = this->m_board.getBlackCaptured();
        this->m_captured_white = this->m_board.getWhiteCaptured();
    } else {

        this->m_board.movePiece(from, to);
    }

    if (abs(from - to) == this->m_die1.getValue() && !this->m_die1.isUsed()) {
        this->m_die1.setUsed(true);
        this->m_num_of_moves--;
        if (this->m_die1.getValue() == this->m_die2.getValue()) {
            this->m_die1.setUsed(false);
        }
    } else if (abs(from - to) == this->m_die2.getValue() && !this->m_die2.isUsed()) {
        this->m_die2.setUsed(true);
        this->m_num_of_moves--;
        if (this->m_die1.getValue() == this->m_die2.getValue()) {
            this->m_die2.setUsed(false);
        }
    } else if (abs(from - to) == (this->m_die2.getValue() + this->m_die1.getValue())
               && !this->m_die1.isUsed() && !this->m_die2.isUsed()) {
        this->m_die1.setUsed(true);
        this->m_die2.setUsed(true);
        this->m_num_of_moves--;
        this->m_num_of_moves--;
        if (this->m_die1.getValue() == this->m_die2.getValue()) {
            this->m_die1.setUsed(false);
            this->m_die2.setUsed(false);
        }

    }
}

void BackgammonModel::bear(int from, Color endZone) {
    shared_ptr<Piece> newPiece(new Piece(this->m_board.getSpace()[from].getLastPiece()));
    this->m_board.getSpace()[from].getPieces().pop_back();
    if (endZone == BLACK) {
        this->m_board.getBlackEntered().push_back(*newPiece);
    } else if (endZone == WHITE) {
        this->m_board.getWhiteEntered().push_back(*newPiece);
    }
}

bool BackgammonModel::rolled() {
    return this->m_hasRolled;
}

bool BackgammonModel::doubled() {
    return this->m_hasDoubled;
}

bool BackgammonModel::isValidMove(int from, int to, Player current) {

    Space to_space = this->m_board.getSpace()[to];
    Space from_space = this->m_board.getSpace()[from];


    bool player_move_right_direction = ((current.getColor() == "Black") && (to > from))
                                       || ((current.getColor() == "White") && (to < from));

    bool die2_check = (this->m_die2.getValue() == abs(to - from)) && (!this->m_die2.isUsed());


    bool die1_check = (this->m_die1.getValue() == abs(to - from)) && (!this->m_die1.isUsed());


    bool both_check = (to - from == (this->m_die1.getValue() + this->m_die2.getValue())) && (!this->m_die1.isUsed())
                      && (!this->m_die2.isUsed());


    bool correct_black = (current.getColor() == "Black"
                          && (from_space.getSpaceType() == BLACK)
                          && (to_space.getSpaceType() == BLACK
                              || (to_space.getSpaceType() == WHITE && to_space.getPieces().size() == 1)
                              || (to_space.getPieces().empty())));

    bool correct_white = (current.getColor() == "White"
                          && (from_space.getSpaceType() == WHITE)
                          && (to_space.getSpaceType() == WHITE
                              || (to_space.getSpaceType() == BLACK && to_space.getPieces().size() == 1)
                              || (to_space.getPieces().empty())));

    bool actual_pieces_on_spot = (!from_space.getPieces().empty());

    return player_move_right_direction && (die1_check || die2_check || both_check) && (correct_black || correct_white)
           && actual_pieces_on_spot;
}

bool BackgammonModel::isValidBear(int from, int moveAmt, Player current) {
    if (!this->m_board.getSpace()[from].getPieces().empty()) {
        Piece piece = this->m_board.getSpace()[from].getPieces()[this->m_board.getSpace()[from].getPieces().size() - 1];
        if ((current.getColor() == "Black" && piece.getColor() == BLACK)
            || (current.getColor() == "White" && piece.getColor() == WHITE)) {
            if ((from + moveAmt) == 25 && piece.getColor() == BLACK) {
                return true;
            } else if ((from - moveAmt) == -1 && piece.getColor() == WHITE) {
                return true;
            }
        }
    }
    return false;
}

bool BackgammonModel::isWhiteCaptured() {
    return this->m_board.isWhiteCaptured();
}

bool BackgammonModel::isBlackCaptured() {
    return this->m_board.isBlackCaptured();
}

int BackgammonModel::getNumberOfMoves() {
    return this->m_num_of_moves;
}

// Throws errors if there are no pieces to enter, if the place to be entered is invalid or if the spot
// is not open.
void BackgammonModel::enterPiece(Color playerColor, int enter) {
    if (((playerColor == WHITE) && this->m_captured_white.empty())
        || ((playerColor == BLACK) && this->m_captured_black.empty())) {
        throw "You have no pieces to enter.";
    } else {
        if (enter + 1 == this->m_die1.getValue()) {
            this->m_board.enterPiece(playerColor, enter);
            if (this->m_num_of_moves <= 2) {
                this->m_die1.setUsed(true);
                this->m_num_of_moves = this->m_num_of_moves - 1;
            }
        } else if (enter + 1 == this->m_die2.getValue()) {
            this->m_board.enterPiece(playerColor, enter);
            if (this->m_num_of_moves <= 2) {
                this->m_die2.setUsed(true);
                this->m_num_of_moves = this->m_num_of_moves - 1;
            }
        } else {
            throw "You can only use one of the rolled values.";
        }
    }


    this->m_captured_white = this->m_board.getWhiteCaptured();
    this->m_captured_black = this->m_board.getBlackCaptured();
}

bool BackgammonModel::checkForVictory() {
    if (this->m_board.getWhiteEntered().size() == 15) {
        this->m_victor = WHITE;
        return true;
    } else if (this->m_board.getBlackEntered().size() == 15) {
        this->m_victor = BLACK;
        return true;
    } else {
        return false;
    }
}

Color BackgammonModel::getVictor() {
    return this->m_victor;
}

void BackgammonModel::restart() {
    IBackgammonModel *newGame = new BackgammonModel;
    newGame->setPoints(this->m_points);
    newGame->setPlayers(this->m_player1, this->m_player2);
    TextView view = TextView();

    shared_ptr<IController> controller(new TextController(view,newGame));
    controller->go();
}

void BackgammonModel::setPoints(Points points) {
    this->m_points = points;
}

void BackgammonModel::setPlayers(Player one, Player two) {
    this->m_player1 = one;
    this->m_player2 = two;
}

bool BackgammonModel::anyValidEnterMoves(Color current) {

    if (this->rolled()) {

        int possible_open_1 = this->m_die1.getValue() - 1;
        int possible_open_2 = this->m_die2.getValue() - 1;

        if (current == WHITE) {
            possible_open_1 =  23 - possible_open_1;
            possible_open_2 = 23 - possible_open_2;
        }

        return ((this->m_board.getSpace()[possible_open_1].getPieces().empty()
                 || this->m_board.getSpace()[possible_open_1].getSpaceType() == current)
                || (this->m_board.getSpace()[possible_open_2].getPieces().empty()
                    || this->m_board.getSpace()[possible_open_2].getSpaceType() == current));

    } else {
        return true;
    }
}

void BackgammonModel::resetForTurn() {
    this->m_hasRolled = false;
    this->m_num_of_moves = 0;
    this->m_hasDoubled = false;
}
