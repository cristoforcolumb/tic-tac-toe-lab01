#include "GameEngine.hpp"
#include <iostream>

int checks = 0;
int failures = 0;

void check(bool condition, const char* description) {
    checks++;
    if (!condition) {
        failures++;
        std::cout << "Eroare: " << description << '\n';
    }
}

void play(GameEngine& game, const int moves[], int count) {
    for (int i = 0; i < count; i++) {
        check(!game.isFinished(), "partida s-a terminat prea devreme");
        check(game.makeMove(moves[i]), "mutare valida respinsa");
    }
}

void checkEmptyGame(const GameEngine& game) {
    check(!game.isFinished(), "partida noua trebuie sa fie activa");
    check(game.getCurrentPlayer() == 'X', "X trebuie sa inceapa");
    check(game.getWinner() == ' ', "partida noua nu are castigator");
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            check(game.getCell(row, column) == ' ', "tabla trebuie sa fie goala");
        }
    }
}

int main() {
    GameEngine game;
    checkEmptyGame(game);

    check(!game.makeMove(-1), "pozitie negativa");
    check(!game.makeMove(0), "pozitia zero");
    check(!game.makeMove(10), "pozitie peste limita");
    checkEmptyGame(game);
    check(game.makeMove(5), "mutare in centru");
    check(game.getCell(1, 1) == 'X', "casuta 5 trebuie sa fie centrul");
    check(game.getCurrentPlayer() == 'O', "alternarea jucatorilor");
    check(!game.makeMove(5), "casuta ocupata");
    check(game.getCell(1, 1) == 'X', "mutarea invalida nu schimba simbolul");
    check(game.getCurrentPlayer() == 'O', "mutarea invalida nu schimba tura");
    check(game.getWinner() == ' ' && !game.isFinished(), "jocul continua");
    check(game.getCell(-1, 0) == '?', "citire in afara tablei");
    check(game.getCell(0, 3) == '?', "citire in afara tablei");

    // Cate o partida pentru fiecare rand, coloana si diagonala.
    const int xGames[8][5] = {
        {1, 4, 2, 5, 3}, {4, 1, 5, 2, 6}, {7, 1, 8, 2, 9},
        {1, 2, 4, 3, 7}, {2, 1, 5, 3, 8}, {3, 1, 6, 2, 9},
        {1, 2, 5, 3, 9}, {3, 1, 5, 2, 7}
    };
    const int oGames[8][6] = {
        {4, 1, 5, 2, 7, 3}, {1, 4, 2, 5, 7, 6}, {1, 7, 2, 8, 4, 9},
        {2, 1, 3, 4, 5, 7}, {1, 2, 3, 5, 4, 8}, {1, 3, 2, 6, 4, 9},
        {2, 1, 3, 5, 4, 9}, {1, 3, 2, 5, 4, 7}
    };
    for (int i = 0; i < 8; i++) {
        game.reset();
        play(game, xGames[i], 5);
        check(game.getWinner() == 'X' && game.isFinished(), "victorie X");
        for (int position = 1; position <= 9; position++) {
            check(!game.makeMove(position), "mutare dupa victoria X");
        }

        game.reset();
        play(game, oGames[i], 6);
        check(game.getWinner() == 'O' && game.isFinished(), "victorie O");
        for (int position = 1; position <= 9; position++) {
            check(!game.makeMove(position), "mutare dupa victoria O");
        }
    }

    game.reset();
    const int draw[] = {1, 2, 3, 5, 4, 6, 8, 7, 9};
    play(game, draw, 9);
    check(game.isFinished() && game.getWinner() == ' ', "remiza");
    check(!game.makeMove(1), "mutare dupa remiza");

    game.reset();
    checkEmptyGame(game);
    const int lastMoveWin[] = {1, 2, 5, 3, 6, 4, 7, 8, 9};
    play(game, lastMoveWin, 9);
    check(game.isFinished() && game.getWinner() == 'X', "victorie la mutarea noua");

    game.reset();
    checkEmptyGame(game);

    if (failures == 0) {
        std::cout << "OK: " << checks << " verificari au trecut.\n";
        return 0;
    }
    std::cout << failures << " verificari au esuat.\n";
    return 1;
}
