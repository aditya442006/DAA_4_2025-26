#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char ch , int freq){
        this->ch = ch;
        this->freq = freq;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b){
        return (a->freq > b->freq); 
    }
};


void print(Node* root, string st, unordered_map<char,string> &codes) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        codes[root->ch] = st;   
        cout << root->ch << " : " << st << endl;
    }
    print(root->left, st + "0", codes);
    print(root->right, st + "1", codes);
}

int main() {
    
    vector<pair<char,int>> arr = {
        {'A',3},
        {'B',2},
        {'C',1}
    };

    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for(auto &p : arr) {
        minHeap.push(new Node(p.first, p.second));
    }
    while(minHeap.size() > 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        Node *merge = new Node('#', left->freq + right->freq);
        merge->left = left;
        merge->right = right;
        minHeap.push(merge);
    }

    Node* root = minHeap.top();
    cout << "Total frequency: " << root->freq << endl;


    unordered_map<char,string> codes;
    print(root, "", codes);

    string input = "AABBCD";
    string encoded = "";
    for(char c : input) {
        encoded += codes[c];
    }

    cout << "\nOriginal string: " << input << endl;
    cout << "Encoded string : " << encoded << endl;

    return 0;
}
