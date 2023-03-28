#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *left;
    struct node *right;
    struct node *parent;
};
typedef struct node *NodePtr;

NodePtr maketree(int x){
    NodePtr p;
    p = new node;
    p -> info = x;
    p -> left = NULL;
    p -> right = NULL;
    p -> parent = NULL;
    return p;
}

void setleft(NodePtr p, int x){
    if(p == NULL)
        cout << "can not set left child to p" << endl;
    else if(p -> left != NULL)
        cout << "p alerady has left child" << endl;
    else   
        p -> left = maketree(x);
}

void setright(NodePtr p, int x){
    if(p == NULL)
        cout << "can not set right child to p" << endl;
    else if(p -> right != NULL)
        cout << "p alerady has right child" << endl;
    else   
        p -> right = maketree(x);
}

void preorder(NodePtr tree){
    if (tree != NULL){
        cout << tree -> info << " ";
        preorder(tree -> left);
        preorder(tree -> right);
    }
}

void inorder(NodePtr tree){
    if (tree != NULL){
        preorder(tree -> left);
        cout << tree -> info << " ";
        preorder(tree -> right);
    }
}

void postorder(NodePtr tree){
    if (tree != NULL){
        postorder(tree -> left);
        postorder(tree -> right);
        cout << tree -> info << " ";
    }
}

void insertHeap(NodePtr p, int newValue){

}

void deleteHeap(NodePtr p){

}

int main(){
}