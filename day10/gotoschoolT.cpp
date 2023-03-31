#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> doglocat;
int row, column, dog;
pair<int, int> toi;
void avoiddog(pair<int, int> toi, int *count){
    if (toi.first + 1 == column && toi.second + 1 == row) {
        *count += 1;
        return;
    }
    for (int i = 0; i < dog; i++)
        if (toi.first == doglocat[i].first && toi.second == doglocat[i].second)
            return;
    if (toi.first + 1 < column) avoiddog({toi.first + 1, toi.second}, count);
    if (toi.second + 1 < row) avoiddog({toi.first, toi.second + 1}, count);
}

int main(){
    int count = 0, tmp1, tmp2;
    cin >> column >> row >> dog;
    for(int i=0; i<dog; i++){
        cin >> tmp1 >> tmp2;
        doglocat.push_back({tmp1, tmp2});
    } toi = make_pair(0, 0);
    avoiddog(toi, &count);
    cout << count << endl;

}

/*
5 4
3
2 2
2 3
4 2

6 5
3
5 4
2 2
1 4
*/