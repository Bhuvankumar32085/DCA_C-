#include<iostream>
#include<vector>
using namespace std;

int ClimbingStairs_Recursion(int n){
    if(n==1 || n==2 || n==3){
        return n;
    }
    //ye BC bhi thik h
    // if(n==0 || n==1){
    //     return 1;
    // }

   return ClimbingStairs_Recursion(n-1)+ClimbingStairs_Recursion(n-2);
}

int ClimbingStairs_memoization(int n,vector<int>dp){
    if(n==1 || n==0){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

   dp[n]=ClimbingStairs_memoization(n-1,dp)+ClimbingStairs_memoization(n-2,dp);
   return dp[n];
}

int tabulation(int n){
  vector<int>dp(n-1,0);
  dp[0]=1;
  dp[1]=1;

  for (int i = 2; i <=n; i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  return dp[n];
}

int main(){
    int n=6;
    vector<int>dp(n+1,-1);
    // cout<<ClimbingStairs_Recursion(n);
    // cout<<ClimbingStairs_memoization(n,dp);

    cout<<tabulation(n);
}