#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int main()
{
    int row, column;
    cin >> row >> column;
    int puzzle[row][column+1], table[row][column+1];
    memset(table, 0, sizeof(table));
    memset(puzzle, 0, sizeof(puzzle));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> puzzle[i][j];
            if (i == 0)
            {
                table[i][j] = puzzle[i][j];
            }
            else
            {
                table[i][j] = max((puzzle[i][j] + table[i - 1][j - 1]), (puzzle[i][j] + table[i - 1][j]), (puzzle[i][j] + table[i - 1][j + 1]));
            }
            // cout << table[i][j] << " ";
        }
        // cout << endl;
    }
    int ans = table[row-1][column-1];
    for (int j = 0; j < column; j++)
    {
        if (table[row-1][j] > ans)
            ans = table[row][j];
    }
    cout << ans;
}

/*
5 4
34 21 22 34
45 70 43 65
25 62 15 26
15 19 32 24
30 60 50 80

215 258 284 278
*/