#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

class GameEngine {
private:
    char board[3][3];
    char currentPlayer;
    char winner;
    int moveCount;

    bool hasLine(char symbol) const;

public:
    GameEngine();
    void reset();
    bool makeMove(int position);  // Casutele sunt numerotate de la 1 la 9.
    char getCell(int row, int column) const;
    char getCurrentPlayer() const;
    char getWinner() const;
    bool isFinished() const;
};

#endif
