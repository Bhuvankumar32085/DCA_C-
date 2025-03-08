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

void inoder(Node* root){
    if(root==NULL){
        return;
    }
    inoder(root->left);
    cout<<root->data<<" ";
    inoder(root->right);
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

bool Seaech(Node* root,int key){
  if(root==NULL){
   return false;
  }

  if(root->data==key){
    return true;
  }

  if(root->data > key){
   return Seaech(root->left,key);
  }else{
   return Seaech(root->right,key);
  }

  return false;
}

int main(){
    int arr[]={5,1,3,4,2,7};
    int sizeOfArr=6;
    Node* root=Build_BST(arr,sizeOfArr);
  
   cout<<Seaech(root,7);
    
    return 0;
}