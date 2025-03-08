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

    // ~node(){
    //     if(next!=NULL){
    //       cout<<"node destructor for data;";
    //        delete next;
    //        next=NULL;
    //     }
    // }
};

class list{
    node *head;
    node *tail;

  public:

    list(){
        head=NULL;
        tail=NULL;
    }

    // ~list(){
    //     if(head!=NULL){
    //        delete head;
    //        head=NULL;
    //     }
    // }

  void push_front(int val){
    node *newNode=new node(val);//daynamic
    if(head==NULL){
       head=tail=newNode;
    }else{
       newNode->next=head;
       head=newNode;
    }
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

  void printlist(){
    node *temp=head;//static me creat hoya
    while (temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
    }
  }

  void pop_front(){
    node* temp=head; //static me creat hoya
    head=head->next;
    temp->next=NULL;
    delete temp;
  }

  void pop_back(){
    node* temp=head; //static me creat hoya
    while (temp->next != tail){
      temp=temp->next;
    }
     temp->next=NULL;
     delete tail;
     tail=temp;
  }

  void insert(int val,int position){
    node *newNode=new node(val);//daynamic
    node *temp=head;
    for(int i=0 ; i<position-1 ; i++){
      temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
  }

  int searchitr(int key){
    node *temp=head;
    int i=0;
    while (temp!=NULL){
      if(temp->data!=key){
        temp=temp->next;
        i++;
      }else{
        return i;
      }
      return -1;
    }
  }

  int helper(node* temp,int key){
    if(temp==NULL){//bc
      return  -1;
    }

    if(temp->data == key){//i=0
      return 0;
    }

    int idx=helper(temp->next,key);
    if(idx==-1){
      return -1;
    }
    
    return idx+1;
  }
  
  int searchRec(int key){
    return helper(head,key);
  }
  
  void reversell(){
    node *prev=NULL;
    node *curr=head;
    tail=head;
    while(curr!=NULL){
      node *Next=curr->next;
      curr->next=prev;
      //updation for next itr
      prev=curr;
      curr=Next;
    }

    head=prev;
  }
  
  int sizell(){
    node *temp=head;
    int i=1;
    while (temp->next!=NULL){
      temp=temp->next;
      i++;
    } 
    return i; 
  }

  void remove_Nth_Node(int n){
    node *prev=head;
    node*curr;
    int size=sizell();
    for(int i=1 ; i<size-n ; i++){
      prev=prev->next;
    }
    curr=prev->next;
    prev->next=curr->next;
    delete curr;
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
  
}