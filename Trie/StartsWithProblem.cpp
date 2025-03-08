#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
    public:
      unordered_map<char,Node*>children;
      bool endOfWord;

      Node(){
        endOfWord=false;
      }
};

class trie{
   Node* root;
   public:
    trie(){
        root=new Node();
    }

    void insert(string key){
        Node *temp=root;
        for(int i=0;i<key.size();i++){
          if(temp->children.count( key[i])==0){
            temp->children[key[i]]=new Node();
          }
          temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }   

    bool StrarsWithProblem(string key){
      Node* temp=root;

      for (int i = 0; i < key.size(); i++){
         if(temp->children.count(key[i])){
            temp=temp->children[key[i]];
         }else{
            return false;
         }
      }
      return true;
    } 
};

 
int main(){
    vector<string>dict={"apple","app","mango","man","woman"};
    trie t;
    for (int i = 0; i < dict.size(); i++){
        t.insert(dict[i]);
    }

    cout<<t.StrarsWithProblem("app")<<"\n";
    cout<<t.StrarsWithProblem("moon");
    return 0;
}