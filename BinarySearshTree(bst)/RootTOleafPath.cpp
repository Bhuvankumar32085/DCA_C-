#include<iostream>
#include<vector>
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

void printpath(vector<int>path){
  for (int i = 0; i < path.size(); i++){
  cout<<path[i]<<" ";
  }
  cout<<endl;
}

void pathHelper(Node* root,vector<int>path){
 if(root==NULL){
  return;
 }

 path.push_back(root->data);
 if(root->left==NULL && root->right==NULL){
    printpath(path);
    path.pop_back();
    return;
 }
 pathHelper(root->left,path);
 pathHelper(root->right,path);
}

void rootTOleafPath(Node* root){
    vector<int> path;
    pathHelper(root,path);
}

int main(){
    int arr[]={5,1,3,4,2,7};
    int arr2[9]={8,5,3,1,4,6,10,11,14};
    int sizeOfArr=9;
    Node* root=Build_BST(arr2,sizeOfArr);
    rootTOleafPath(root);
    return 0;
}