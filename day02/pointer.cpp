#include <bits/stdc++.h>
using namespace std;
#define STACKSIZE 100
struct sta{
    int top;
    int items[STACKSIZE];
};

int isEmpty(struct sta *ps){
    if(ps->top == -1) return(1);
    else return(0);
}
void push(struct sta *ps, int x){
    if(ps->top == STACKSIZE -1){
        cout << "stack overflow";
        exit(1);
    }
    else ps->items[++(ps->top)] = x;
}
int pop(struct sta *ps){
    if(isEmpty(ps)){
        cout << "stack underflow";
        exit(1);
    }
    return (ps->items[ps->top--]);
}
void empty(struct sta *ps){

}
void printstack(struct sta *ps){
    
}
int main(){
    struct sta *s1 = new struct sta;
    isEmpty(s1);
    push(s1, 1);
    
    cout << s1 << endl;
    struct sta *s2;

}