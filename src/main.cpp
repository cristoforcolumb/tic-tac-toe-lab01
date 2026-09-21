#include "GameEngine.hpp"
#include "Renderer.hpp"
#include "Listener.hpp"
#include <iostream>

using namespace std;

int main() {
    GameEngine game;
    Renderer renderer;
    Listener listener;

    cout << "=== X si O ===\n";
    cout << "X incepe. Alegeti pe rand cate o casuta libera.\n";
    cout << "Castiga cel care aliniaza trei simboluri.\n";
    renderer.draw(game);

    while (!game.isFinished()) {
        int position;
        if (!listener.readMove(position)) {
            cout << "Joc inchis.\n";
            return 0;
        }
        if (!game.makeMove(position)) {
            cout << "Casuta este ocupata. Alege alta casuta.\n";
        }
        renderer.draw(game);
    }
    return 0;
}
