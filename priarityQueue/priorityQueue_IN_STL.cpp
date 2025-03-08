#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    priority_queue<int> a;
    pq.push(5);
    pq.push(10);
    pq.push(6);
    pq.push(9);
    
    a.push(5); 
    a.push(10);
    a.push(6);
    a.push(9);
    
    cout<<"min heap se=";
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout<<"\nmax heap se=";
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
}
