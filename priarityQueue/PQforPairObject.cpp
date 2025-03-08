#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class student{
 public:
  string name;
  int marks;

 student(string namee,int mar){
    name=namee;
    marks=mar;
 }

 bool operator < (const student &obj) const{
   return this->marks < obj.marks;
 }
};

int main(){
    priority_queue<student>pq;
    pq.push(student("bhuvan",500));
    pq.push(student("vinayak",480));
    pq.push(student("nanu",380));
    pq.push(student("arpit",200));
    pq.push(student("krishna",490));

    while (!pq.empty()){
        cout<<pq.top().name<<"="<<pq.top().marks<<"\n";
       pq.pop();
    }
    
}