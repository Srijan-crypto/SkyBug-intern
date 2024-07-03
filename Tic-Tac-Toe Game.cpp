#include <iostream>
using namespace std;

// Function to initialize the board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

// Function to draw the Tic-Tac-Toe board
void drawBoard(const char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check for a win
bool checkWin(const char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

// Function to get a valid move from the current player
void getPlayerMove(char board[3][3], char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;
        if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == ' ')
            break;
        else
            cout << "Invalid move. Try again.\n";
    }
    board[row][col] = player;
}

// Function to check for a draw
bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Main function to run the game
void playGame() {
    char board[3][3];
    char currentPlayer = 'X';
    initializeBoard(board);

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (true) {
        drawBoard(board);
        getPlayerMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        
        if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    playGame();
    return 0;
}
