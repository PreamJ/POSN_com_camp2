#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    struct node *left;
    struct node *right;
    struct node *father;
};
typedef struct node *NodePtr;
NodePtr root = NULL;

NodePtr makeTree (int x){
    NodePtr p;   
    p = new node;
    p -> info = x;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}



void setLeft (NodePtr p, int x){
    if(p==NULL){
        cout << "can't set left child to p" << endl;
    }
    else if (p->left != NULL){
        cout << "p already has left child" << endl;
    }
    else{
        p-> left = makeTree(x);
    }
}

void setRight (NodePtr p, int x){
    if(p==NULL){
        cout << "can't set right child to p" << endl;
    }
    else if (p->right != NULL){
        cout << "p already has right child" << endl;
    }
    else{
        p-> right = makeTree(x);
    }
}

void preOrder (NodePtr tree){
    if(tree != NULL){
        cout << tree -> info << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(NodePtr tree){
    if(tree != NULL){
        inOrder(tree->left);
        cout << tree -> info << " ";
        inOrder(tree -> right);
    }
}

void postOrder(NodePtr tree){
    if(tree != NULL){
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree-> info << " ";
    }
}



int main(){

    return 0;
}