#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // check if there is any queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // check if there is any queen in the upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // check if there is any queen in the lower diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// function to solve the N-Queens problem using exhaustive search
bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    // base case: all queens are placed
    if (col >= n) {
        // print the solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }

    bool res = false;

    // try placing queen in each row of current column
    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            // recursively solve for the next column
            res = solveNQueens(board, col+1, n) || res;

            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    // create an empty chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));

    // solve the N-Queens problem using exhaustive search
    if (!solveNQueens(board, 0, n)) {
        cout << "No solution found" << endl;
    }

    return 0;
}