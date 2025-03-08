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



void TopView(Node* root){
 queue<pair<Node*,int>> q;
 map<int,int>m;

 q.push(make_pair(root,0));
 while(!q.empty()){
    pair<Node*,int>curr=q.front();
    q.pop();

    Node* currNode=curr.first;
    int currHD=curr.second;

    if(m.count(currHD) == 0){
        m[currHD]=currNode->data;
    }else{
        m[currHD]=currNode->data;
    }

    if(currNode->left != NULL){
      pair<Node*,int>left=make_pair(currNode->left,currHD-1);
      q.push(left);
    }
    if(currNode->right != NULL){
      pair<Node*,int>right=make_pair(currNode->right,currHD+1);
      q.push(right);
    }
 }

 for(auto it : m){
    cout<<it.second<<" ";
 }
}

void TopView(Node* root){
 queue<pair<Node*,int>> q;
 map<int,int>m;

 q.push(make_pair(root,0));
 while(!q.empty()){
    pair<Node*,int>curr=q.front();
    q.pop();

    Node* currNode=curr.first;
    int currHD=curr.second;

    if(m.count(currHD) == 0){
        m[currHD]=currNode->data;
    }else{
        m[currHD]=currNode->data;
    }

    if(currNode->left != NULL){
      pair<Node*,int>left=make_pair(currNode->left,currHD-1);
      q.push(left);
    }
    if(currNode->right != NULL){
      pair<Node*,int>right=make_pair(currNode->right,currHD+1);
      q.push(right);
    }
 }

 for(auto it : m){
    cout<<it.second<<" ";
 }
}

void TopView(Node* root){
 queue<pair<Node*,int>> q;
 map<int,int>m;

 q.push(make_pair(root,0));
 while(!q.empty()){
    pair<Node*,int>curr=q.front();
    q.pop();

    Node* currNode=curr.first;
    int currHD=curr.second;

    if(m.count(currHD) == 0){
        m[currHD]=currNode->data;
    }

    if(currNode->left != NULL){
      pair<Node*,int>left=make_pair(currNode->left,currHD-1);
      q.push(left);
    }
    if(currNode->right != NULL){
      pair<Node*,int>right=make_pair(currNode->right,currHD+1);
      q.push(right);
    }
 }

 for(auto it : m){
    cout<<it.second<<" ";
 }
}

void DownView(Node* root){
 queue<pair<Node*,int>> q;
 map<int,int>m;

 q.push(make_pair(root,0));
 while(!q.empty()){
    pair<Node*,int>curr=q.front();
    q.pop();

    Node* currNode=curr.first;
    int currHD=curr.second;

    if(m.count(currHD) == 0){
        m[currHD]=currNode->data;
    }else{
        m[currHD]=currNode->data;
    }

    if(currNode->left != NULL){
      pair<Node*,int>left=make_pair(currNode->left,currHD-1);
      q.push(left);
    }
    if(currNode->right != NULL){
      pair<Node*,int>right=make_pair(currNode->right,currHD+1);
      q.push(right);
    }
 }

 for(auto it : m){
    cout<<it.second<<" ";
 }
}


int main(){
    vector<int> node={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> node2={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};
    Node*root=buildTree(node2);
    TopView(root);
    return 0;
}