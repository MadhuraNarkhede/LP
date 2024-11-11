#include <iostream>
using namespace std;

#define MAX 20 // Maximum size of the chessboard

int board[MAX][MAX];

// Function to print the chessboard
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, int n) {
    // Check the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int row, int n) {
    // Base case: All queens are placed
    if (row >= n) {
        printBoard(n);
        return true;
    }

    bool foundSolution = false;

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // Check if it's safe to place the queen
        if (isSafe(row, col, n)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place queens in the next row
            foundSolution = solveNQueens(row + 1, n) || foundSolution;

            // Backtrack: Remove the queen
            board[row][col] = 0;
        }
    }

    return foundSolution;
}

int main() {
    int n;

    // Input the size of the chessboard
    cout << "Enter the size of the chessboard (n): ";
    while (true) {
        cin >> n;

        // Validate the input size
        if (n > 0 && n <= MAX) {
            break;
        } else {
            cout << "Invalid size! Please enter a number between 1 and " << MAX << ": ";
        }
    }

    // Initialize the board to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the N-Queens problem
    if (!solveNQueens(0, n)) {
        cout << "No solution exists for " << n << " queens." << endl;
    }

    return 0;
}
