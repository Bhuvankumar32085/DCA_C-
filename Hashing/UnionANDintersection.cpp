#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void Intersection(int arr1[],int a1,int arr2[],int a2){
  unordered_set<int>s;
    for (int i = 0; i < a1; i++){
       s.insert(arr1[i]);
    }
    for (int i = 0; i < a2; i++){
      if(s.find(arr2[i])!=s.end()){
         cout<<arr2[i];
         s.erase(arr2[i]);
      }
    }
}

void Union(int arr1[],int a1,int arr2[],int a2){
  unordered_set<int>s;
  int k=0;
  for (int i = 0; i < a1+a2; i++){
    if(i<a1){
        s.insert(arr1[i]);
    }else{
        s.insert(arr2[k++]);
    }
  }

  for(auto it:s){
    cout<<it;
  }
  
}

int main(){
    int arr1[]={6,3,9,2,9,4};
    int arr2[]={7,3,9};
    Intersection(arr1,6,arr2,3);
}