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


void KthLevel(Node* root,int key){//without recursion
if(root==NULL){
  return;
}
  
  queue<Node*> q;
  int i=1;
  q.push(root);
  q.push(NULL);
 
  while(!q.empty()){
    Node* curr=q.front();
    q.pop();
    if(curr==NULL){
        i++;
      q.push(NULL);
    }else{
     if(curr->left != NULL){
       q.push(curr->left);
     }
    
     if(curr->right != NULL){
       q.push(curr->right);
     }
     if(key==i){
        cout<<curr->data;
     }
    }
  }
}

void KthHelper(Node* root,int key,int currLevel){
 if(root==NULL){
  return;
 }

 if(currLevel==key){
   cout<<root->data<<" ";
   return;
 }
 KthHelper(root->left,key,currLevel+1);
 KthHelper(root->right,key,currLevel+1);
}

void KthLevel_2(Node* root,int key){
//with recursion
 KthHelper(root,key,1);
}

int main(){
    vector<int> node={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> node2={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};
    Node*root=buildTree(node);
    KthLevel_2(root,3);
    return 0;
}