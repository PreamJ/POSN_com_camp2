#include<bits/stdc++.h>
using namespace std;

int checking(int i, vector<char> card, int score){  
    if(card.size() <=2){
        return score;
    }
    card.erase(card.begin()+i);
    for(int a=0; a<card.size()-1; a++){
        if(card[a] == card[a+1]){
            card.erase(card.begin()+a);
            card.erase(card.begin()+a+1);
            score++;
        }
    }
    return checking(i, card, score);
}

int play(int score, vector<char> card, int k){
    int maxscore = INT_MIN;
    int alcheck;
    for(int i=0; i<k; i++){
        alcheck = checking(i, card, score);
        if(alcheck > maxscore) maxscore = alcheck;
    }
    return maxscore;
}

int main(){
    int k, score=0;
    cin >> k;
    vector<char> card(k);
    for(int i=0; i<k; i++){
        cin >> card[i];
    }
    play(score, card, k);
}
/*
6
U B N B O U
output 2

13
N U B O B U O N B O N U O
output 3

13
N U B O B U O N B O N U O
output 4
*/