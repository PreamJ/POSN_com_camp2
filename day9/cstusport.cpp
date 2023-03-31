#include<bits/stdc++.h>
using namespace std;

int compatible(vector<vector<int>> score, int i, int j, int Nquestion){
    int Cscore = 0;
    for(int k=0; k<Nquestion; k++){
        Cscore += pow((score[i][k] - score[j][k]), 2);
    }
    return Cscore;
}

int checking(vector<vector<int>> score, int Nstudent, int Nquestion){
    int minscore = INT_MAX;
    int temp;
    for(int i=0; i<Nstudent-1; i++){
        for(int j=i+1; j<Nstudent; j++){
            temp = compatible(score, i, j, Nquestion);
            if(temp < minscore){
                minscore = temp;
            }
        }
    }
    return minscore;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> score(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> score[i][j];
        }
    }
    cout << checking(score, n, m);
}
