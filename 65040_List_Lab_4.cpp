#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};
typedef struct node *NodePtr;
NodePtr head = NULL;

void displayList(){
    NodePtr p = head;
    cout << "Data entered in the list : " << endl;
    while(p != NULL){
        cout << "Data = " << p-> info << endl;
        p = p -> next;
    }
}

void addnew(int n){
    NodePtr a, b;
    b = new node;
    b -> info = n;
    b -> next = NULL;
    if(head == NULL) head = b;
    else{
        for (a=head; a->next != NULL; a=a->next);
            a->next = b;
    }
}

void createList(int n){
    int x;
    for(int i=0; i<n; i++){
        cout << "Input data for node " << i+1 << " : ";
        cin >> x;
        addnew(x);
    }
}

void insertLast(){
    int n;
    cout << "Input data to insert at the end of the list :";
    cin >> n;
    NodePtr a, b;
    b = new node;
    b -> info = n;
    b -> next = NULL;
    if(head == NULL) head = b;
    else{
        for (a=head; a->next != NULL; a=a->next);
        a->next = b;
    }
}

void insertFront(){
    int n;
    cout << "Input data to insert at the beginning of the list :";
    cin >> n;
    NodePtr q;
    q = new node;
    q -> info = n;
    q -> next = head;
    head = q;
}

void insertMiddle(){
    int n, place;
    cout << "Input data to insert at the middle of the list :";
    cin >> n;
    cout << "Input the position to insert new code : ";
    cin >> place;
    NodePtr q, find;
    q = new node;
    q -> info = n;
    find = head;
    for(int i=0; i<place-2; i++){
        find = find -> next;
    }
    q -> next = find -> next;
    find -> next = q;

}

void deleteFront(){
    if(head==NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else{
        NodePtr first;
        first = head;
        cout << "Data of fist node which is being delete is : " << first -> info << endl;
        first = first -> next;
        delete head;
        head = first;
        displayList();
        cout << "Deletion complete" << endl;
    }
}

void deleteLast(){
    if(head==NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else{
        NodePtr last, current;
        current = head;
        while(current -> next -> next != NULL){
            current = current -> next;
        }
        last = current -> next;
        cout << "Data of last node which is being delete is : " << last -> info << endl;
        current -> next = NULL;
        delete last;
        displayList();
        cout << "Deletion complete" << endl;
    }
}
void deleteMiddle(){
    int x;
    cout << "Input the postition of node to delete : ";
    cin >> x;
    NodePtr p, q;
    p = head;
    for(q=NULL; p != NULL && p-> info != x; p = p -> next) q = p;
    if (p == NULL){
        cout << "delete value is not on the list" << endl;
        return;
    }
    if (q == NULL){
        head = p -> next;
    }
    else q -> next = p -> next;
    delete p;
    displayList();
    cout << "Deletion complete" << endl;
}

void searchList(){
    int key, count=0;
    cout << "Input the element to be search : ";
    cin >> key;
    NodePtr current;
    current = head;
    while(current != NULL){
        count++;
        if(current->info == key){
            cout << "Data found at node " << count << endl;
        }
        current = current -> next;
        
    }
}
int main(){
    int x, n, count=0;
    cout << "Input the number of node : ";
    cin >> n;
    createList(n);
    searchList();
    return 0;
}