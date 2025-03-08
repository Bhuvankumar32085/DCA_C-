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

bool RootToNodePath(Node* root ,int n,vector<int>&path){
  if(root==NULL){
    return false;
  }
  path.push_back(root->data);
  if(root->data==n){
    return true;
  }
  int IsLeft=RootToNodePath(root->left,n,path);
  int IsRight=RootToNodePath(root->right,n,path);

  if(IsLeft || IsRight){
    return true;
  }

  path.pop_back();
  return false;
}

int LCA(Node* root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;

    RootToNodePath(root,n1,path1);
    RootToNodePath(root,n2,path2);
    
    int lca=-1;
    for(int i= 0,j=0; i<path1.size()&&j<path2.size(); i++,j++){
       if(path1[i]!=path2[j]){
        return lca;
       }
       lca=path1[i];
    }
}

int main(){
    vector<int> node={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> node2={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};
    Node*root=buildTree(node);

    int n1=4,n2=6;//n1=node 4 and n2=node 5 
    //jine bichme hame ancestor dekh na
    cout<<LCA(root,n1,n2);
    return 0;
}