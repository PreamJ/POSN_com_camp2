#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    int count;
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
    p ->count = 1;
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
        t = makeTree(input);
    }
    else{
        if(input < t->info){
            insertBST(t->left, input);
        }
        else if(input > t->info){
            insertBST(t->right, input);
        }
        else {
            t->count++;
            insertBST(t->right, input);
        }
    }
}

void countBST(NodePtr t){
    if(t != NULL){
        countBST(t->left);
        if(t->count > 1) cout << t->info << " appears " << t->count << " time(s)" << endl;
        countBST(t->right);
    }
}

int countLeaves(NodePtr tree) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return 1;
    }
    return countLeaves(tree->left) + countLeaves(tree->right);
}

int findHeight(NodePtr node) {
    if (node == NULL) {
        return -1;
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    int arr[] = {1, 5, 2, 3, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        insertBST(root, arr[i]);
    }
    // insertBST(root, 1);
    // insertBST(root, 5);
    // insertBST(root, 2);
    // insertBST(root, 3);
    // insertBST(root, 3);
    // insertBST(root, 1);
    // insertBST(root, 10);
    // insertBST(root, 2);
    countBST(root);
    findLargest();
    findSmallest();
    cout << "number of leaf nodes is " << countLeaves(root) << endl;
    cout << "hight of tree is " << findHeight(root) << endl;
    return 0;
}