#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node* next;
};
typedef struct node *NodePtr;
NodePtr top = NULL;

bool isEmpty() {
    return (top == NULL);
}

void push(string s) {
    NodePtr temp;
    temp = new node;
    temp->data = s;
    temp->next = top;
    top = temp;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        NodePtr temp;
        temp = top;
        top = top->next;
        delete temp;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        NodePtr current;
        current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

bool isValid(string str) {
    bool valid = true;
    stack<char> s;
    for (char symb : str) {
        if (symb == '(' || symb == '[' || symb == '{') {
            s.push(symb);
        }
        else if (symb == ')' || symb == ']' || symb == '}') {
            if (s.empty()) {
                valid = false;
                break;
            }
            char opener = s.top();
            s.pop();
            if ((symb == ')' && opener != '(') || 
                (symb == ']' && opener != '[') || 
                (symb == '}' && opener != '{')) {
                valid = false;
                break;
            }
        }
    }
    if (!s.empty()) {
        valid = false;
    }
    return valid;
}

int main() {
    string str;
    cout << "Enter an expression : ";
    cin >> str;
    if (isValid(str)) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
    return 0;
}