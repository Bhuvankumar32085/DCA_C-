#include<iostream>
using namespace std;

class Node{
 public:
  int data;
  Node* left;
  Node* right;

 Node(int val){
  this->data=val;
  left=NULL;
  right=NULL;
 }
};

void Inoder(Node* root){
    if(root==NULL){
        return;
    }
    Inoder(root->left);
    cout<<root->data<<" ";
    Inoder(root->right);
}

Node* Insert(Node* root,int val){
  if(root==NULL){
    root=new Node(val);
    return root;
  }

  if(val < root->data){
   root->left= Insert(root->left,val);
  }else{
    root->right=Insert(root->right,val);
  }

  return root;
}

Node* Build_BST(int arr[],int n){
  Node* root=NULL;

   for (int i = 0; i < n; i++){
    root=Insert(root,arr[i]);
   }
   
   return root;
}

void printInRande(Node* root,int st,int end){
  if(root==NULL){
    return;
  }

  if(st<=root->data && root->data<=end){
    printInRande(root->left,st,end);
    cout<<root->data<<" ";
    printInRande(root->right,st,end);
  }else if(root->data<st){
    printInRande(root->right,st,end);
  }else{
    printInRande(root->left,st,end);
  }
}

int main(){
    int arr[]={5,1,3,4,2,7};
    int arr2[9]={8,5,3,1,4,6,10,11,14};
    int sizeOfArr=9;
    Node* root=Build_BST(arr2,sizeOfArr);
    printInRande(root,5,12);
    return 0;
}