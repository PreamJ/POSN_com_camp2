#include<bits/stdc++.h>
using namespace std;

/*
#define N 5
void printBoard(int board[N][N]) {
    int count =0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
            if(board[i][j] == 1){
                count ++;
            }
        }
        cout << endl;
    }
    cout << count << endl;
}
bool isValid(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) //check whether there is queen in the left or not
        if (board[row][i])
            return false;
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j]) //check whether there is queen in the left upper diagonal or not
            return false;
    for (int i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j]) //check whether there is queen in the left lower diagonal or not
            return false;
    return true;
}
bool solveNQueen(int board[N][N], int col) {
    if (col >= N) //when N queens are placed successfully
        return true;
    for (int i = 0; i < N; i++) { //for each row, check placing of queen is possible or not
        if (isValid(board, i, col) ) {
            board[i][col] = 1; //if validate, place the queen at place (i, col)
            if ( solveNQueen(board, col + 1)) //Go for the other columns recursively
                return true;
            board[i][col] = 0; //When no place is vacant remove that queen
        }
    }
    return false; //when no possible order is found
}
bool checkSolution() {
    int board[N][N];
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
        board[i][j] = 0; //set all elements to 0
    if ( solveNQueen(board, 0) == false ) { //starting from 0th column
        cout << "Solution does not exist";
        return false;
    }
    printBoard(board);
    return true;
}
int main() {
    checkSolution();
}
*/



// #define N 4
// void printSolution(int board[N][N])
// {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++)
//            if(board[i][j])
//             cout << "Q ";
//            else cout<<". ";
//         printf("\n");
//     }
// }
 
// /* A utility function to check if a queen can
//    be placed on board[row][col]. Note that this
//    function is called when "col" queens are
//    already placed in columns from 0 to col -1.
//    So we need to check only left side for
//    attacking queens */
// bool isSafe(int board[N][N], int row, int col)
// {
//     int i, j;
 
//     /* Check this row on left side */
//     for (i = 0; i < col; i++)
//         if (board[row][i])
//             return false;
 
//     /* Check upper diagonal on left side */
//     for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
//         if (board[i][j])
//             return false;
 
//     /* Check lower diagonal on left side */
//     for (i = row, j = col; j >= 0 && i < N; i++, j--)
//         if (board[i][j])
//             return false;
 
//     return true;
// }
 
// /* A recursive utility function to solve N
//    Queen problem */
// bool solveNQUtil(int board[N][N], int col)
// {
//     /* base case: If all queens are placed
//       then return true */
//     if (col >= N)
//         return true;
 
//     /* Consider this column and try placing
//        this queen in all rows one by one */
//     for (int i = 0; i < N; i++) {
//         /* Check if the queen can be placed on
//           board[i][col] */
//         if (isSafe(board, i, col)) {
//             /* Place this queen in board[i][col] */
//             board[i][col] = 1;
 
//             /* recur to place rest of the queens */
//             if (solveNQUtil(board, col + 1))
//                 return true;
 
//             /* If placing queen in board[i][col]
//                doesn't lead to a solution, then
//                remove queen from board[i][col] */
//             board[i][col] = 0; // BACKTRACK
//         }
//     }
 
//     /* If the queen cannot be placed in any row in
//         this column col  then return false */
//     return false;
// }

// bool solveNQ(int n)
// {
//     int board[n][n];
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cin >> board[i][j];
//         }
//     }
 
//     if (solveNQUtil(board, 0) == false) {
//         cout << "Solution does not exist";
//         return false;
//     }
 
//     printSolution(board);
//     return true;
// }

// int main(){
//     int n;
//     cin >> n;
//     solveNQ(n);
//     return 0;
// }


/*

        Pass a pointer to a pointer

void processArr(int **a) {
   // Do Something
}
// When calling:
int **array;
array = new int *[10];
for(int i = 0; i <10; i++)
   array[i] = new int[10];
processArr(array);

        Pseudo-code implementation:

function solveNQueens(board, col, n):
  if col >= n:
    print board
    return true
  for row from 0 to n-1:
    if isSafe(board, row, col, n):
      board[row][col] = 1
      if solveNQueens(board, col+1, n):
        return true
      board[row][col] = 0
  return false

function isSafe(board, row, col, n):
    for i from 0 to col-1:
        if board[row][i] == 1:
        return false
    for i,j from row-1, col-1 to 0, 0 by -1:
        if board[i][j] == 1:
        return false
    for i,j from row+1, col-1 to n-1, 0 by 1, -1:
        if board[i][j] == 1:
        return false
    return true

board = empty NxN chessboard
solveNQueens(board, 0, N)
*/


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