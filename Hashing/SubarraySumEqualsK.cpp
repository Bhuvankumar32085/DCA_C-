#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int SubarraySUMequalK(vector<int>arr,int k){
  unordered_map<int,int>m;  //sum count
   m[0]=1;
   int sum=0;
   int ans=0;
   for (int j = 0; j < arr.size(); j++){
      sum+=arr[j];
      if(m.count(sum-k)){
         ans+=m[sum-k];
      }

      if(m.count(sum)){
        m[sum]++;
      }else{
        m[sum]=1;
      }
   }
   return ans;
}

int main(){
    vector<int>arr={10,2,-2,-20,10};
    int k=-10;
     cout<<SubarraySUMequalK(arr,k);
    return 0;
}