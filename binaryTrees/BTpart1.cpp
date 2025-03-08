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


void preorderTraversal(Node* root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


void ineorderTraversal(Node* root){
  if(root==NULL){
    return;
  }
  ineorderTraversal(root->left);
  cout<<root->data<<" "; 
  ineorderTraversal(root->right);
}


void postorderTraversal(Node* root){
  if(root==NULL){
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout<<root->data<<" "; 
}


void levelOrder(Node* root){
if(root==NULL){
  return;
}
  
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
 
  while(!q.empty()){
    Node* curr=q.front();
    q.pop();

    if(curr==NULL){
      cout<<endl;
      if(q.empty()){
        break;
      }
      q.push(NULL);
    }else{
      
     cout<<curr->data<<" ";
    
     if(curr->left != NULL){
       q.push(curr->left);
     }
    
     if(curr->right != NULL){
       q.push(curr->right);
     }
    }
  }
}


int height(Node* root){
  if(root==NULL){
    return 0;
  }
  int lefthig=height(root->left);
  int righthig=height(root->right);
   
  int currht=max(lefthig,righthig)+1;

  return currht;
}


int CountNode(Node* root){
  if(root==NULL){
    return 0;
  }
  int leftnode=CountNode(root->left);
  int rightnode=CountNode(root->right);
   
  int currnode=leftnode+rightnode+1;

  return currnode;
}


int SumNode(Node* root){
  if(root==NULL){
    return 0;
  }
  
  int leftsum= SumNode(root->left);
  int rightsum=SumNode(root->right);
  
  int currsum=leftsum+rightsum+root->data;
  // cout<<"node is"<<root->data<<"="<<currsum<<"\n";
  return currsum;
}

int diam1(Node* root){//  0(n*n)
  if(root==NULL){
    return 0;
  }
  int currDiam=height(root->left)+height(root->right)+1;
  int leftDiam=diam1(root->left);
  int rightDiam=diam1(root->right);

  return max(currDiam,max(leftDiam,rightDiam));
}

bool IsIdentical(Node * root1,Node* root2){
  if(root1==NULL && root2==NULL){
    return true;
  }else if(root1==NULL || root2==NULL){
    return false;
  }
   
   if(root1->data!=root2->data){
    return false;
  }
  return IsIdentical(root1->left,root2->left)
        && IsIdentical(root1->right,root2->right);
}

bool IsSubroot(Node *root,Node *subroot){
  if(root==NULL && subroot==NULL){
    return true;
  }else if(root==NULL || subroot==NULL){
    return false;
  }


  //find the subroot in tree(root tree)
  if(root->data==subroot->data){
    //identical for subtree
    if(IsIdentical(root,subroot)){
      return true;
    }
  }
    
  int isLeftSubroot=IsSubroot(root->left,subroot);
  if(!isLeftSubroot){
    return IsSubroot(root->right,subroot);
  }

  return true;
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

 for(auto it:m){
    cout<<it.second<<" ";
 }
}

int main(){
    vector<int> node={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> node2={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node*root=buildTree(node);
    Node* subroot=new Node(2);
    subroot->left=new Node(4);
    subroot->right=new Node(5);

    TopView(root);
    return 0;
}