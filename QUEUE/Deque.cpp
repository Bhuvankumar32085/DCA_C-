#include<iostream>
#include<deque>
using namespace std;

class stack{
  deque<int> de;
 public:
   void push(int data){
     de.push_front(data);
   }  

   void pop(){
    de.pop_front();
   }

   int top(){
    return de.front();
   }

   bool empty(){
    return de.empty();
   }
};

int main(){
   stack s;

   s.push(1);
   s.push(2);
   s.push(3);

   while (!s.empty()){
    cout<<s.top();
    s.pop();
   }
   
}