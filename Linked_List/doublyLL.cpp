#include<iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;
    node * prev;

    node(int val){
       data=val;
       next=NULL;
       prev=NULL;
    } 
};

class list{

    node *head;
    node *tail;
  public:
    list(){
        head=NULL;
        tail=NULL;
    }

  void push_front(int val){
    node *newNode=new node(val);//daynamic
    if(head==NULL){
       head=tail=newNode;
    }else{
       newNode->next=head;
       head->prev=newNode;
       head=newNode;
    }
  }

  void push_back(int val){
    node *newNode=new node(val);//daynamic
    if(head==NULL){
       head=tail=newNode;
    }else{
       newNode->prev=tail;
       tail->next=newNode;
       tail=newNode;
    }
  }
   
   
   void pop_front(){
      node *temp=head;
      head=head->next;
      head->prev=NULL;
      delete temp;
   }

   void printlist(){
    node *temp=head;//static me creat hoya
    while (temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
    }
    cout<<endl;
  }

  void revers(){
    node *temp=tail;//static me creat hoya
    while (temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->prev;
    }
    cout<<endl;
  }
};

int main(){
   list ll;

   ll.push_front(3);
   ll.push_front(2);
   ll.push_front(1);
   ll.push_back(4);
   ll.push_back(5);
   ll.push_back(6);
   // ll.pop_front();
   ll.printlist();
   // ll.revers();
}