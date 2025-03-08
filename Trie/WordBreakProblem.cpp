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

    bool search(string key){
      Node* temp=root;

      for (int i = 0; i < key.size(); i++){
         if(temp->children.count(key[i])){
            temp=temp->children[key[i]];
         }else{
            return false;
         }
      }
      return temp->endOfWord;
    }

    
};

 bool helper(trie &t,string key ){
    if(key.size()==0){
        return true;
    }

   for (int i = 0; i < key.size(); i++){
    string first=key.substr(0,i+1); //substr string ka method h
    string second=key.substr(i+1);
     
     if(t.search(first)  && helper(t,second)){
        return true;
     }
   }
   return false;
 }

 int wordBreak(vector<string>dict,string key){
    trie t;
    for (int i = 0; i < dict.size(); i++){
        t.insert(dict[i]);
    }
    return helper(t,key);
 }
int main(){
    vector<string>dict={"i","like","sam","samsung","mobile","ice"};
    cout<<wordBreak(dict,"ilikesamsung");
    return 0;
}