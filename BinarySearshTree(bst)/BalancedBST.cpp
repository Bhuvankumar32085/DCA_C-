#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node* Insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    
    if (val < root->data) {
        root->left = Insert(root->left, val);
    } else {
        root->right = Insert(root->right, val);
    }
    
    return root;
}

Node* Build_BST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = Insert(root, arr[i]);
    }
    return root;
}


int main() {
    int arr[] = {};
    int sizeOfArr = 7;
    Node* root = Build_BST(arr, sizeOfArr);
    
    return 0;
}
