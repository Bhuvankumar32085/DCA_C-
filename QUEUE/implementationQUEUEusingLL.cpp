#include<iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;

    node(int dat){
        data=dat;
        next=NULL;
    }
};

class queue{
  node *head;
  node *tail;

  public:
   queue(){
     head=tail=NULL;
   }

   void push(int val){
     node* newnode=new node(val);
     if(head==NULL){
        tail=head=newnode;
     }else{
       tail->next=newnode;
       tail=newnode;
     }
   }

   void pop(){
     if(empty()){
        cout<<"queue is empty\n";
        return;
     }
    node *temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
   }


   int  front(){
    if(empty()){
        cout<<"queue is empty\n";
        return -1;
     }
       return head->data;
   }

   bool empty(){
    return head==NULL;
   }
};


int main(){
  queue qq;
  
  qq.push(1);
  qq.push(2);
  qq.push(3);
  qq.push(41);

  while(!qq.empty()){
    cout<<qq.front()<<" ";
    qq.pop();
  }
}