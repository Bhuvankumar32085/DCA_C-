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

Node* getInordersuccessor(Node* root){
    while (root->left != NULL){
        root=root->left;
    }
    return root;
}

Node* Delete(Node* root,int val){
  if(root==NULL){
   return NULL;
  }

  if(root->data > val){
     root->left= Delete(root->left,val);
  }else if(val>root->data){
     root->right=Delete(root->right,val);
  }else{

    if(root->left==NULL && root->right==NULL){
      delete root;
      return NULL;
      }

   //case 2
     if(root->left==NULL || root->right==NULL){
       return root->left==NULL ? root->right:root->left;
     }

    //case 3
    Node* IS= getInordersuccessor(root->right);
    root->data=IS->data;
    root->right=Delete(root->right,IS->data);
    return root;
  }
 return root;
}


int main(){
    int arr[]={5,1,3,4,2,7};
    int sizeOfArr=6;
    Node* root=Build_BST(arr,sizeOfArr);
  
   Delete(root,3);
   inoder(root);
    return 0;
}