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

NodePtr searchBST (NodePtr t, int key){
    if(t == NULL){
        return NULL;
    }
    if (key < t -> info){
        return searchBST(t -> left, key);
    }
    else if(key > t -> info){
        return searchBST(t -> right, key);
    }
    else return t;
}

void findSmallest(){
    if(root != NULL){
        NodePtr tmp;
        for(tmp = root; tmp -> left != NULL; tmp = tmp -> left);
        cout << "the smallest value is " << tmp -> info << endl;
    }
}

void findLargest(){
    if(root != NULL){
        NodePtr tmp;
        for(tmp=root; tmp-> right!= NULL; tmp = tmp-> right);
        cout << "the largest value is " << tmp-> info << endl;
    }
}

void insertBST(NodePtr &t, int input){
    if(t == NULL){
        t = new node;
        t -> info = input;
        t -> left = NULL;
        t -> right = NULL;
    }
    else{
        if(input < t -> info){
            insertBST(t->left, input);
        }
        else{
            insertBST(t->right, input);
        }
    }
}

int main(){
    makeTree(1);
    makeTree(5);
    makeTree(2);
    makeTree(3);
    findLargest();
    return 0;
}