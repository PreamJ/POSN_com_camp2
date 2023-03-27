NodePtr makeTree(int x){
    NodePtr p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    p->father = NULL;
    return p;
}

void insertBST(NodePtr &t, int input){
    if(t == NULL){
        t = makeTree(input);
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