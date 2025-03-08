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

Node * LCA2(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
  if(root->data==n1 || root->data==n2){
    return root;
  }

  Node* leftLCA=LCA2(root->left,n1,n2);
  Node* rightLCA=LCA2(root->right,n1,n2);

  if(leftLCA != NULL && rightLCA != NULL){
    return root;
  }

  return leftLCA==NULL ? rightLCA:leftLCA;
}

int main(){
    vector<int> node={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> node2={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};
    Node*root=buildTree(node);

    int n1=4,n2=6;//n1=node 4 and n2=node 5 
    //jine bichme hame ancestor dekh na
    cout<<LCA2(root,n1,n2)->data;
    return 0;
    
}