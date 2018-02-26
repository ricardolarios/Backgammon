#include <iostream>
#include "../model/BackgammonModel.h"
#include "../controller/TextController.h"
#include <ctime>
#include <memory>

using namespace std;

int main() {
    srand(time(NULL));
    BackgammonModel * model = new BackgammonModel();
    model->startGame();
    Player p1 = model->getPlayer1();
    Player p2 = model->getPlayer2();


    // outputting player names, colors and scores
    p1.output();
    cout << endl;
    p2.output();
    cout << endl;

    TextView view = TextView();
    shared_ptr<IController> controller(new TextController(view, model));

    controller->go();

    delete model;

    return 0;
}
