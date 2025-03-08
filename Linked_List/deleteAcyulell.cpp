#include<iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;

    node(int val){
       data=val;
       next=NULL;
    } 
};

class list{
    public:
    node *head;
    node *tail;

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
       head=newNode;
    }
  }

   void printlist(){
    node *temp=head;//static me creat hoya
    while (temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
    }
    cout<<endl;
  }

   void pop_front(){
    node* temp=head; //static me creat hoya
    head=head->next;
    temp->next=NULL;
    delete temp;
  }
   void push_back(int val){
    node *newNode=new node(val);//daynamic
    if(head==NULL){
       head=tail=newNode;
    }else{
       tail->next=newNode;
       tail=newNode;
    }
  }
};

bool isCycle(node *head){
  node *slow=head;
  node* fast=head;
  while(fast!=NULL &&  fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow == fast){
        cout<<"cycle exists";
      return true;
    }
  }
  cout<<"cycle not exists=";
  return false;
}

void removing_cycle(node *head){
  node *slow=head;
  node* fast=head;
  bool iscycle=false;
  while(fast!=NULL &&  fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow == fast){
        cout<<"cycle exists=";
        iscycle=true;
        break;
    }
  }
  if(!iscycle){
    cout<<"cycle not exists=";
    return;
  }

  slow=head;
  if(slow==fast){//special case tail = head
    while (fast->next!=slow) {
      fast=fast->next;
    }
    fast->next=NULL;

  }else{// noraml case
    node* prev=fast;
    while(slow != fast){
       slow =slow->next;
       prev=fast;
       fast=fast->next;
    }
    prev->next=NULL;
  }
} 

int main(){
    list ll;
   ll.push_front(3);
   ll.push_front(2);
   ll.push_front(1);
   ll.push_back(4);
   ll.push_back(5);
   ll.push_back(6);
   ll.printlist();
   ll.tail->next=ll.head;
  //  cout<<isCycle(ll.head);
  removing_cycle(ll.head);
  ll.printlist();

}