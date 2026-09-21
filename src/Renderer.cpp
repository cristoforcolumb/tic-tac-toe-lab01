#include "Renderer.hpp"
#include <iostream>

using namespace std;

void Renderer::draw(const GameEngine& game) const {
    cout << '\n';
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            char symbol = game.getCell(row, column);
            cout << ' ';
            if (symbol == ' ') {
                cout << row * 3 + column + 1;
            } else {
                cout << symbol;
            }
            cout << ' ';
            if (column < 2) {
                cout << '|';
            }
        }
        cout << '\n';
        if (row < 2) {
            cout << "---+---+---\n";
        }
    }
    cout << '\n';

    if (game.getWinner() != ' ') {
        cout << "Jucatorul " << game.getWinner() << " a castigat!\n";
    } else if (game.isFinished()) {
        cout << "Remiza!\n";
    } else {
        cout << "La mutare: " << game.getCurrentPlayer() << '\n';
    }
}
