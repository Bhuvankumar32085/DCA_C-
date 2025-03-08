#include<iostream>
#include<vector>
using namespace std;

int recursion(int n){
  if(n==1 || n==2 ){
    return n;
  }
  if(n==0){
    return 1;
  }

  return recursion(n-1)+recursion(n-2)+recursion(n-3);
}

int tabulation(int n){
  vector<int>dp(n+1,0);
   dp[0]=1;
   dp[1]=1;
   dp[2]=2;

   for (int  i = 3; i <=n; i++){
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
   }
   return dp[n];
}

int main(){
    int n=5;
    cout<<tabulation(n);
}