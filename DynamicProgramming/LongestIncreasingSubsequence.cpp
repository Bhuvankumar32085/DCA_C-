#include<iostream>
#include<vector>
#include <bits/stdc++.h>//sort method ke liye
#include<string>
#include<unordered_set>
using namespace std;

int LIS(vector<int>arr){
   unordered_set<int>s(arr.begin(),arr.end());
   vector<int> arr2(s.begin(),s.end());
   stable_sort(arr2.begin(),arr2.end());//ascending sorting order
    
    int n=arr.size();
    int m=arr2.size();
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for (int i = 1; i < n+1; i++){
    for (int j = 1; j < m+1; j++){
        if(arr[i-1]==arr2[j-1]){
          dp[i][j]=dp[i-1][j-1]+1;
        }else{
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
   }
   return dp[n][m];
}

int main(){
   vector<int>arr={50,3,10,7,40,80};
  cout<<LIS(arr);

  return 0;
}