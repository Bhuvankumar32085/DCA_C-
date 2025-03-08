#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int largestSumArrayWith0(vector<int>arr){
  unordered_map<int,int>m;
   
   int sum=0;
   int ans=0;
   for (int j = 0; j < arr.size(); j++){
      sum+=arr[j];
      if(m.count(sum)){
         int currlen=j-m[sum];
         ans=max(ans,currlen);
      }else{
        m[sum]=j;
      }
   }
   return ans;
}

int main(){
    vector<int>arr={15,-2,2,-8,1,7,10};
     cout<<largestSumArrayWith0(arr);
    return 0;
}