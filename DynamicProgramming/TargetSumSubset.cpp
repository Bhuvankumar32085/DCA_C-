#include<iostream>
#include<vector>
using namespace std;

int TargetSum(vector<int>num,int tar,int n){
  vector<vector<int>>dp(n+1,vector<int>(tar+1,0));

 for (int i = 1; i <=n; i++){
    for (int j = 1; j <=tar; j++){
        if(num[i-1]<=j){
            dp[i][j]=max(num[i-1]+dp[i-1][j-num[i-1]],dp[i-1][j]);
        }else{
            dp[i][j]=dp[i-1][j];
        }
    }
 }
   return dp[n][tar]==tar;
}

int main(){
    vector<int>nums={4,2,7,1,3};
    int target=25;
    cout<<TargetSum(nums,target,5);
}