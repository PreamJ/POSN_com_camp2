#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n, runner=2, number=3;
//     bool checker = true;
//     cin >> n;
//     vector<int> prime;
//     prime.push_back(2);
//     prime.push_back(3);
//     if(n==1) cout << 2;
//     else if(n==2) cout << 3;
//     else{
//         while(checker){
//             bool is_prime = true;
//             for(int i=0; i<prime.size(); i++){
//                 if(number % prime[i] == 0){
//                     is_prime = false;
//                     break;
//                 }
//                 if(prime[i] > sqrt(number)){
//                     break;
//                 }
//             }
//             if(is_prime){
//                 runner++;
//                 prime.push_back(number);
//                 if(runner == n){
//                     cout << number;
//                     break;
//                 }
//             }
//             number += 2;
//         }
//     }
//     return 0;
// }

int main(){
    int n, runner=3, number=4;
    bool checker = true;
    cin >> n;
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    if(n==1) cout << 2;
    else if(n==2) cout << 3;
    else{
        while(checker==true){
            for(int i=0; i<=prime.size(); i++){
                if(runner == n){
                    cout << number;
                    checker = false;
                    break;
                }
                if(number%prime[i]==0){
                    break;
                }
                else if(i==prime.size()-1){
                    prime.push_back(number);
                    runner++;
                    break;
                }
                else if(prime[i]>sqrt(number)){
                    break;
                }
                else break;
            }
            number++;
        }
    }
}
