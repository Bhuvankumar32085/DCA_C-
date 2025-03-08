#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

void Countdistinct(int arr[],int n){
  set<int>s;
  for (int i = 0; i < n; i++){
    s.insert(arr[i]);
  }
  cout<<s.size();
}

int main(){
    int arr[]={4,3,2,5,6,7,3,4,2,1};
    Countdistinct(arr,10);
}