#include<bits/stdc++.h>
using namespace std;

int ranking(vector<int> &setscore, int num, int *nicha, int i){
    if(setscore[num] > nicha[i]){
        return num+2;
    }
    else if(setscore[num] == nicha[i]){
        return num+1;
    }
    else if(num == 0) 
        return 1;
    else{
        num -= 1;
        return ranking(setscore, num, nicha, i);
    }
}

void round(vector<int> &setscore, int num, int *nicha, int m){
    for(int i=0; i<m; i++){
        cout << ranking(setscore, num, nicha, i) << endl;
    }
}


int main(){
    int n;
    cin >> n;
    int score [n];
    vector<int> setscore;
    for(int i=0; i<n; i++){
        cin >> score[i];
        if(i!=0 && score[i]!=score[i-1]) setscore.push_back(score[i]);
        else if(i == 0) setscore.push_back(score[0]);
    }
    int m;
    int num = setscore.size() -1;
    // cout << "  "<< num << endl;
    cin >> m;
    int nicha[m];
    for(int i=0; i<m ;i++){
        cin >> nicha[i];
    }
    round(setscore, num, nicha, m);
}

/*
7
100 100 50 40 40 20 10
4
5 25 50 120
*/