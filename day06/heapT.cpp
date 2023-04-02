#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

typedef struct Node * NodePtr;

NodePtr newNode(int key) {
    NodePtr node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(NodePtr* heap, int i, int heapSize) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heapSize && heap[left]->key > heap[largest]->key) {
        largest = left;
    }

    if (right < heapSize && heap[right]->key > heap[largest]->key) {
        largest = right;
    }

    if (largest != i) {
        swap(&heap[i]->key, &heap[largest]->key);
        heapify(heap, largest, heapSize);
    }
}

void insert(NodePtr* heap, int* heapSize, int key) {
    NodePtr node = newNode(key);
    heap[*heapSize] = node;
    (*heapSize)++;

    int i = *heapSize - 1;
    while (i > 0 && heap[(i - 1) / 2]->key < heap[i]->key) {
        swap(&heap[i]->key, &heap[(i - 1) / 2]->key);
        i = (i - 1) / 2;
    }
}

int extractRoot(NodePtr* heap, int* heapSize) {
    int root = heap[0]->key;

    NodePtr lastNode = heap[*heapSize - 1];
    heap[0] = lastNode;
    (*heapSize)--;

    heapify(heap, 0, *heapSize);

    return root;
}

void printHeap(NodePtr* heap, int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i]->key << " ";
    }
    cout << endl;
}

void deleteHeap(NodePtr* heap, int* heapSize, int key){
    int i;
    for(i = 0; i< *heapSize; i++){
        if(heap[i] -> key == key) break;
    }
    if(i == *heapSize){
        return;
    }
    heap[i] = heap[*heapSize -1];
    (*heapSize)--;
    heapify(heap, i, *heapSize);
    cout << "deletion successful!" << endl;
}


int main() {
    NodePtr heap[100];
    int heapSize = 0;

    insert(heap, &heapSize, 3);
    insert(heap, &heapSize, 2);
    insert(heap, &heapSize, 1);
    insert(heap, &heapSize, 5);
    insert(heap, &heapSize, 4);

    cout << "Heap: ";
    printHeap(heap, heapSize);

    deleteHeap(heap, &heapSize, 2);
    cout << "Heap: ";
    printHeap(heap, heapSize);

    return 0;
}