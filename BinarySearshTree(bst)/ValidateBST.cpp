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

bool validateHelper(Node* root, Node* min, Node* max) {
    if (root == NULL) {
        return true;
    }
    
    if (min != NULL && root->data < min->data) {
        return false;
    }
    
    if (max != NULL && root->data > max->data) {
        return false;
    }
    
    return validateHelper(root->left,min, root) 
    &&     validateHelper(root->right,root,max);
}

bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

int main() {
    int arr[] = {5, 1, 3, 4, 2, 7};
    int arr2[] = {8,5,3,1,4,6,10,11,14};
    int sizeOfArr = 6;
    Node* root = Build_BST(arr, sizeOfArr);
    cout << validateBST(root);
    return 0;
}
