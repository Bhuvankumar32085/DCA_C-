#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int connectNRopes(vector<int>ropes){
  priority_queue<int,vector<int>,greater<int>>pq(ropes.begin(),ropes.end());
  //hum sari values ko for loop laga ke dale ya
  //(ropes.begin(),ropes.end()) yase dale es me
  //time kam lagta h

  int cost=0;
  while (pq.size()>1){
   int min1=pq.top();
   pq.pop();
   int min2=pq.top();
   pq.pop();
  
   cost+=min1+min2;
   pq.push(min1+min2);
  }
  cout<<cost;
}

int main(){
    vector<int>ropes={4,3,2,6};
    connectNRopes(ropes);
}
