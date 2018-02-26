//
// Created by Rikki on 11/9/2017.
//

#include "TextController.h"
#include <sstream>

/**
 * Starts the game.
 */
void TextController::go() {
    std::string modelState = this->m_model->getGameState();
    this->m_view.updateState(modelState);
    this->runGame();
}

/**
 * Runs the game of Backgammon.
 */
void TextController::runGame() {

    while (true) {
        std::string modelState = this->m_model->getGameState();
        this->m_view.updateState(modelState);
        this->m_view.refresh();

        // Current color of the current Player
        Color current;
        if (this->current_player.getColor() == "Black") {
            current = BLACK;
        }
        else {
            current = WHITE;
        }

        if (!this->anyValidEnterMoves(current)) {
            std::cout << "You do not have any valid moves. Changing turns." << std::endl;

            this->m_model->resetForTurn();
            this->changeTurns();

            continue;
        }

        std::cout << this->current_player.getName() << ", enter a command: " << std::endl;

        std::string input;
        getline(std::cin, input);

        unsigned int position = input.find(' ');
        std::string token = input.substr(0, position);
        input.erase(0, position + 1);

        //end the game
        if (this->m_model->checkForVictory()) {
            std::string winner;
            if (this->m_model->getVictor() == BLACK) {
                winner += "Black ";
            }
            else if (this->m_model->getVictor() == WHITE) {
                winner += "White ";
            }
            winner += " has won the game.";
            this->restart();
        }
        else {
            if (token == "roll") {
                if (this->m_model->rolled()) {
                    std::cout << "You already rolled." << std::endl;
                } else {
                    this->m_model->rollDice();
                }
            }
            else if (token == "move") {
                if (this->m_model->rolled()) {

                    if ((this->m_model->isWhiteCaptured() && current == WHITE)
                        || (this->m_model->isBlackCaptured() && current == BLACK)) {
                        std::cout << "You must enter your hit pieces first." << std::endl;
                        continue;
                    }

                    int from = 0;
                    int to = 0;

                    // Making sure that there is a correct number of inputs.
                    try {
                        position = input.find(' ');
                        std::string from_string = input.substr(0, position);
                        position = input.find(' ');
                        std::string dest_string = input.substr(position);

                        stringstream ss(from_string);

                        ss >> from;

                        stringstream ss2(dest_string);

                        ss2 >> to;
                    }
                    catch (const exception &e) {
                        std::cout << "Please input a valid command." << std::endl;
                        continue;
                    }

                    if (this->m_model->isValidMove(from - 1, to - 1, this->current_player)) {
                        try {
                            this->m_model->move(from - 1, to - 1);
                        }
                        catch (const std::string &error) {
                            std::cout << error << std::endl;
                        }
                    }
                }
            } else if (token == "bear") {
                if (this->m_model->rolled()) {
                    position = input.find(' ');
                    std::string from_string = input.substr(0, position);
                    position = input.find(' ');
                    std::string dest_string = input.substr(position);

                    stringstream ss(from_string);
                    int from = 0;
                    ss >> from;


                    if (current_player.getColor() == "Black") {
                        if (this->m_model->isValidBear(from - 1, 25 - (from - 1), current_player)) {
                            this->m_model->bear(from, BLACK);
                        }
                    }
                    else if (current_player.getColor() == "White") {
                        if (this->m_model->isValidBear(from - 1, from - 1, current_player)) {
                            this->m_model->bear(from, WHITE);
                        }
                    }
                }
            } else if (token == "double") {
                if (this->m_model->doubled()) {
                    std::cout << "You already rolled the doubling cube this turn." << std::endl;
                } else if (this->m_model->rolled()) {
                    std::cout << "You cannot roll the doubling cube once you've rolled the dice." << std::endl;
                }
                else {
                    if (this->m_model->getPlayer1() == current_player)  {
                        std::cout << this->m_model->getPlayer2().getName() << ", do you accept doubling the stakes?"
                                                                                        << std::endl;

                        getline(std::cin, token);

                        if (token != "yes") {
                            this->m_model->getPlayer2().addPoints(1);
                            this->m_model->restart();
                        }
                        else {
                            this->m_model->rollDoublingCube();
                        }
                    }
                    else if (this->m_model->getPlayer2() == current_player) {
                        std::cout << this->m_model->getPlayer1().getName() << ", do you accept doubling the stakes? (yes or no)"
                                                                                        << std::endl;

                        getline(std::cin, token);

                        if (token != "yes") {
                            this->m_model->getPlayer1().addPoints(1);
                            this->m_model->restart();
                        }
                        else {
                            this->m_model->rollDoublingCube();
                        }
                    }

                }
            } else if (token == "enter") {

                if ((this->m_model->isBlackCaptured() && current == BLACK)
                    || (this->m_model->isWhiteCaptured() && current == WHITE)) {

                    if (!this->m_model->rolled()) {
                        std::cout << "You must roll the dice first." << std::endl;
                        continue;
                    }
                    else {
                        int from = 0;
                        try {
                            position = input.find(' ');
                            std::string from_string = input.substr(0, position);

                            stringstream ss(from_string);
                            ss >> from;
                        }
                        catch (const exception & e) {
                            std::cout << "Please only input a valid enter command." << std::endl;
                        }

                        try {
                            this->m_model->enterPiece(current, from - 1);
                        }
                        catch (const char * & error) {
                            std::cout << error << std::endl;
                        }

                    }


                }
                else {
                    std::cout << "You do not have any pieces to enter." << std::endl;
                }
            } else if (token == "quit") {
                std::cout << "Goodbye." << std::endl;
                exit(1);
            }
        }

        // Changes turns if needed.
       this->changeTurns();
    }
}

void TextController::help() {

}

bool TextController::anyValidEnterMoves(Color current) {

    return this->m_model->anyValidEnterMoves(current);
}

void TextController::changeTurns() {

    if ((this->m_model->getNumberOfMoves() == 0) && this->m_model->rolled()) {
        if (this->current_player == this->m_model->getPlayer1()) {
            this->current_player = this->m_model->getPlayer2();
        } else {
            this->current_player = this->m_model->getPlayer1();
        }

        this->m_model->resetForTurn();
    }
}

void TextController::restart() {
    IBackgammonModel * newGame = new BackgammonModel();
    newGame->setPoints(this->m_model->getPoints());
    newGame->setPlayers(this->m_model->getPlayer1(), this->m_model->getPlayer2());
    TextView view = TextView();

    this->m_model = newGame;

    this->go();
}