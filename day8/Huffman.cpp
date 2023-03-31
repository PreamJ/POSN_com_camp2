#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node *left = nullptr, Node *right = nullptr) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }

    bool isLeaf() const {
        return (left == nullptr && right == nullptr);
    }
};

struct NodeCompare {
    bool operator() (Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

Node* huffmantree(const string& text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }
    priority_queue<Node*, vector<Node*>, NodeCompare> pq;
    for (auto& p : freq) {
        pq.push(new Node(p.first, p.second));
    }
    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }
    return pq.top();
}
void encode(Node* root, const string& text, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr) {
        return;
    }

    if (root->isLeaf()) {
        huffmanCode[root->ch] = "";
    }

    encode(root->left, text, huffmanCode);
    encode(root->right, text, huffmanCode);

    if (!root->isLeaf()) {
        huffmanCode[root->ch] = huffmanCode[root->left->ch] + huffmanCode[root->right->ch];
    }
}
int main() {
    string text;
    cout << "Enter the text to be encoded: ";
    getline(cin, text);
    Node* root = huffmantree(text);
    unordered_map<char, string> huffmanCode;
    encode(root, text, huffmanCode);
    cout << "Huffman codes:" << endl;
    for (auto& p : huffmanCode) {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}