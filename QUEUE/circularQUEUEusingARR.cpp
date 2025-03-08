#include<iostream>
using namespace std;


class queue{
  int *arr;

  int capacity;
  int currsize;
 
  int f,r;
  public:
    queue(int capcity){
        this->capacity=capcity;
        arr=new int[capacity];//capcity=arr ka size
        currsize=0;
        f=0;
        r=-1;
    }

    void push(int data){
        if(currsize==capacity){
            cout<<"queue is full\n";
            return;
        }
        r=(r+1)%capacity;
        arr[r]=data;
        currsize++;
    }

    void pop(){
        if(empty()){
          cout<<"queue is empty";
          return;
        }
        f=(f+1)%capacity;
        currsize--;
    }

    int front(){
        if(empty()){
          cout<<"queue is empty";
          return  -1;
        }
        return arr[f];
    }

    bool empty(){
      return currsize==0;
    }
};

int main(){
    queue q(4);//jis size ka arr chahiye
   
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    
    while (!q.empty()){
      cout<<q.front()<<" ";
      q.pop();
    }
    
}