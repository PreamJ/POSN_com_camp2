#include<bits/stdc++.h>
using namespace std;

// int checking(int i, vector<char> card, int score){
//     card.erase(card.begin()+i);
//     for(int a=0; a<card.size()-1; a++){
//         if(card[a] == card[a+1]){
//             card.erase(card.begin()+a);
//             card.erase(card.begin()+a+1);
//             score++;
//         }
//     }
// }

void play(int score, vector<char> card, int num, int i){
    num = card.size();
    // if(num <=1){
    //     return score;
    // }
    // else{
    //     card.erase(card.begin()+i);
    //     for(int a=0; a<card.size()-1; a++){
    //         if(card[a] == card[a+1]){
    //             card.erase(card.begin()+a);
    //             card.erase(card.begin()+a+1);
    //             score++;
    //         }
    //     }
        
    // }
    do{
        card.erase(card.begin()+i);
        num--;
        for(int a=0; a<card.size()-1; a++){
            if(card[a] == card[a+1]){
                card.erase(card.begin()+a);
                card.erase(card.begin()+a+1);
                score++;
                num -= 2;
            }
        }
    }while(num>=1);
    i++;
    cout << score;
}

int main(){
    int k, score=0;
    cin >> k;
    vector<char> card(k);
    for(int i=0; i<k; i++){
        cin >> card[i];
    }
    play(score, card, k, 0);
}
/*
13
N U B O B U O N B O N U O
*/