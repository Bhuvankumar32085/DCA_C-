#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int pair_sum(int arr[],int target){
    unordered_map<int ,int>m;

    for(int i=0;i<7;i++){
        int find=target-arr[i];
      if(m.count(find)==1){
        cout<<"idx="<<i<<"+"<<m[find];
      }else{
        m[arr[i]]=i;
      }
    }
}

int main(){
    int arr[]={1,2,7,11,15,5,9};
    int target=13;
    pair_sum(arr,target);
}
