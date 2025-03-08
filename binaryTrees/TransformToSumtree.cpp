#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
 public:
  int data;
  Node* left;
  Node* right;

   Node(int val){
    data=val;
    left=NULL;
    right=NULL;
  }
};


static int idx=-1;//static es liye pure program me inx
 //ki value change na ho


Node* buildTree(vector<int> nod){
  idx++;
  if(nod[idx]==-1){
    return NULL;
  }

  Node* currNode=new Node(nod[idx]);
  currNode->left=buildTree(nod);
  currNode->right=buildTree(nod);
  
  return currNode;
}

void printTree(Node* root){
 if(root==NULL){
    return;
 }

 cout<<root->data<<" ";
 printTree(root->left);
 printTree(root->right);
}

int transform(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftold=transform(root->left);
    int rightold=transform(root->right);
    int currold=root->data;

    root->data=leftold + rightold;
    if(root->left!=NULL){
       root->data+=root->left->data;
    }
     if(root->right!=NULL){
       root->data += root->right->data;
    }
    
    return currold;
}

int main(){
    vector<int> node={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> node2={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};
    Node*root=buildTree(node);
    transform(root);
    printTree(root);
    return 0;
    
}
