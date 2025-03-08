#include<iostream>
#include<string>
// #include<list>
using namespace std;

class Node{
  public:
    string key;
    int data;
    Node* next;

    Node(string k,int d){
        key=k;
        data=d;
        next=NULL;
    }

    ~Node(){
      if(next!=NULL){
        delete next;
      }
    }
};

class HashTable{

   int totalsize;
   int currsize;
   Node ** table;

  int Hashfunction(string key){
    int idx=0;
    for (int i=0; i<key.size(); i++){
      idx=idx+(key[i]*key[i])%totalsize;
    }  
    return idx%totalsize;
  }

  void rehash(){
    Node** oldtable=table;
    int oldsize=totalsize;

    totalsize=totalsize*2;
    currsize=0;
    table=new Node*[totalsize];

    for(int i=0; i<totalsize; i++){
        table[i]=NULL;
    } 
     
     //coopy old values
    for(int i=0 ;i<oldsize;i++){
     Node* temp=oldtable[i];
     while(temp!=NULL){
      insert(temp->key,temp->data);
      temp=temp->next;
     }

     if(oldtable[i] != NULL){
        delete oldtable[i];
     }
    }
    delete[] oldtable;
  }
  
public:
  HashTable(int size){
    totalsize=size;
    currsize=0;
    table=new Node*[totalsize];

    for(int i=0; i<totalsize; i++){
        table[i]=NULL;
    } 
  }

  void insert(string key,int value){
     int idx=Hashfunction(key);

    Node *newnode=new Node(key,value);

    newnode->next=table[idx];
    table[idx]=newnode;
 
    currsize++;
    //rehashing
    double lamdba=currsize/(double)totalsize;
    if(lamdba>1){
      rehash();
    }
  }

  bool exists(string key){
    int idx=Hashfunction(key);

    Node* temp=table[idx];
    while (temp != NULL){
      if(temp->key==key){
        return true;
      }
      temp=temp->next;
    }
    return false;
  }

  int search(string key){
     int idx=Hashfunction(key);

    Node* temp=table[idx];
    while (temp!=NULL){
      if(temp->key==key){
        return temp->data;
      }
      temp=temp->next;
    }
    return -1;
  }

  void remove(string key){
     int idx=Hashfunction(key);
     Node* temp=table[idx];
     Node* prev=temp;
     while(temp!=NULL){
      if(temp->key==key){
         if(prev==temp){
          table[idx]=temp->next;
         }else{
          prev->next=temp->next;
         }
      }
      prev=temp;
      temp=temp->next;
     }

  }

  void print(){
    for (int i = 0; i < totalsize; i++){
     cout<<"idx="<<i<<" ";
     Node * temp=table[i];
      while (temp!=NULL){
        cout<<temp->key<<" "<<temp->data<<" ";
        temp=temp->next;
      }
      cout<<endl;
    } 
  }
};

int main(){
    HashTable h(5);//table size diya 5
    
    h.insert("china",150);
    h.insert("us",50);
    h.insert("nepal",10);
    h.insert("uk",20);
    h.insert("india",150);
    // h.insert("paki",12);
    // h.insert("colimban",39);
    // h.insert("asia",59);
    // h.insert("usa",46);
    // h.insert("saudi",39);
    // h.insert("siau",28);
    // h.insert("chandpur",91);
    // h.insert("bijnor",94);

  //  if(h.exists("nepal")){
  //   cout<<"population is "<<h.search("nepal");
  //  }
  //  h.remove("nepal");
   h.print();

    return 0;
}