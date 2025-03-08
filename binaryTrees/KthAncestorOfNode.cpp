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

int KthAns(Node* root ,int node,int k){
    if(root==NULL){
        return -1;
    }
     if(root->data==node){
        return 0;
    }

    int leftdist=KthAns(root->left,node,k);
    int rightdist=KthAns(root->right,node,k);

    if(leftdist== -1 && rightdist==-1){
        return -1;
    }

    int validval=leftdist==-1 ? rightdist:leftdist;
    if(validval + 1 == k){
        cout<<"kth ancestor "<<root->data;
    }
    return validval+1;
}

int main(){
    vector<int> node={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> node2={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};
    Node*root=buildTree(node);

    int nodee=6,k=1;
    KthAns(root,nodee,k);
    return 0;
    
}