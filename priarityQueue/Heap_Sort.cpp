#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

void heapify(int i,vector<int> &arr,int n){
  int l=2*i+1;
  int r=2*i+2;
  int maxidx=i;
  if(arr[l]>arr[maxidx] && l<n){
    maxidx=l;
  }
  if(arr[r]>arr[maxidx] && r<n){
    maxidx=r;
  } 
  swap(arr[i],arr[maxidx]);

  if(maxidx != i){
    heapify(maxidx,arr,n);
  }
}

void heapShot(vector<int> &arr){
   int  n=arr.size();

   for (int i = (n/2)-1; i >= 0; i--){
      heapify(i,arr,n);
   }
   int k=1;
   for(int i=n-1;i>=0;i--){
      swap(arr[0],arr[i]);
       heapify(0,arr,i);
   }
}

int main(){
    vector<int>arr={1,4,2,5,3};
    heapShot(arr);
    for(int i=0; i < arr.size();i++){
     cout<<arr[i]<<" ";
    }
}