#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
    public:
      unordered_map<char,Node*>children;
      bool endOfWord;
      int freq;

      Node(){
        endOfWord=false;
      }
};

class trie{
   Node* root;
   public:
    trie(){
        root=new Node();
        root->freq=-1;
    }

    void insert(string key){
        Node *temp=root;
        for(int i=0;i<key.size();i++){
          if(temp->children.count( key[i])==0){
            temp->children[key[i]]=new Node();
            temp->children[key[i]]->freq=1;
          }else{
            temp->children[key[i]]->freq++;
          }
          temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }    

    string getprefix(string key){
        Node * temp=root;
        string prefix="";

        for (int i = 0; i < key.size(); i++) {
          prefix+=key[i];
          if(temp->children[key[i]]->freq==1){
            break;
          }
          temp=temp->children[key[i]];
        }
        return prefix;
    }
};

 void prefixProblem(vector<string>dict){
  trie t;
   for (int i = 0; i < dict.size(); i++){
     t.insert(dict[i]);
   }
   
   for (int i = 0; i < dict.size(); i++){
     cout<<t.getprefix(dict[i])<<endl;
   }
   
 }

int main(){
    vector<string>dict={"zebra","dog","duck","dove"};
    prefixProblem(dict);
    return 0;
}