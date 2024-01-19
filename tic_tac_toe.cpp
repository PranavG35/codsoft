#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X';

    while (true) {
        // Display the current board
        displayBoard(board);

        // Get player move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the chosen cell is empty
        if (board[row][col] == ' ') {
            // Place the player's symbol in the chosen cell
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check if the board is full (draw)
            if (isBoardFull(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "The chosen cell is already occupied. Try again." << endl;
        }
    }

    return 0;
}
