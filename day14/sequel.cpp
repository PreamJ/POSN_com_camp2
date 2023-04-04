#include<bits/stdc++.h>
using namespace std;

int main(){
    int numbrick, numcheck ,sum;
    cin >> numbrick >> numcheck;
    int brick[numbrick];
    for(int i=0; i<numbrick; i++){
        cin >> brick[i];
    }
    int query[numcheck][3];
    for(int i=0; i<numcheck; i++){
        for(int j=0; j<3; j++){
            cin >> query[i][j];
        }
    }
    for(int i=0; i<numcheck; i++){

        sum = 0;
        for(int j = query[i][0]-1; j<query[i][2]; j+=query[i][1]){
            sum += brick[j];
        }
        cout << sum << " ";
    }
}
/*
11‌ ‌2‌
1‌‌ 5‌‌ 2‌‌ 4‌‌ 7‌‌ 3‌‌ 9‌‌ 2‌‌ 2‌‌ 1‌‌ 5‌
3‌‌ 2‌‌ 8‌
2 ‌‌5‌‌ 8‌
output 18 14

5‌ ‌7‌
4923 4743‌‌ -3836‌‌ -484‌‌ -1009‌
1‌‌ 1‌‌ 2‌
1‌‌ 4‌‌ 3‌
1‌‌ 3‌‌ 4‌
2‌‌ 4‌‌ 3‌
1‌‌ 5‌‌ 2‌
4‌‌ 5‌‌ 5‌
2‌‌ 5‌‌ 4‌
output 9666‌‌ 4923‌‌ 4439‌‌ 4743‌‌ 4923‌‌ -484‌‌ 4743‌ ‌
*/