#include "GameEngine.hpp"

GameEngine::GameEngine() {
    reset();
}

void GameEngine::reset() {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            board[row][column] = ' ';
        }
    }
    currentPlayer = 'X';
    winner = ' ';
    moveCount = 0;
}

bool GameEngine::makeMove(int position) {
    if (position < 1 || position > 9 || isFinished()) {
        return false;
    }

    int row = (position - 1) / 3;
    int column = (position - 1) % 3;
    if (board[row][column] != ' ') {
        return false;
    }

    board[row][column] = currentPlayer;
    moveCount++;

    if (hasLine(currentPlayer)) {
        winner = currentPlayer;
    }

    if (!isFinished()) {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
    return true;
}

bool GameEngine::hasLine(char symbol) const {
    for (int i = 0; i < 3; i++) {
        // Un rand complet.
        if (board[i][0] == symbol && board[i][1] == symbol &&
            board[i][2] == symbol) {
            return true;
        }
        // O coloana completa.
        if (board[0][i] == symbol && board[1][i] == symbol &&
            board[2][i] == symbol) {
            return true;
        }
    }

    if (board[0][0] == symbol && board[1][1] == symbol &&
        board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol &&
        board[2][0] == symbol) {
        return true;
    }
    return false;
}

char GameEngine::getCell(int row, int column) const {
    if (row < 0 || row > 2 || column < 0 || column > 2) {
        return '?';
    }
    return board[row][column];
}

char GameEngine::getCurrentPlayer() const {
    return currentPlayer;
}

char GameEngine::getWinner() const {
    return winner;
}

bool GameEngine::isFinished() const {
    return winner != ' ' || moveCount == 9;
}
