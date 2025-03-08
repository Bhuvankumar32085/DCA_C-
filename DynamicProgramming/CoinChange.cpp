#include<iostream>
#include<vector>
using namespace std;

int CoinChange(int am,vector<int>co){
    int n=co.size();
   vector<vector<int>> dp(n+1,vector<int>(am+1,0));
   
    for (int i = 0; i < n+1; i++){
       dp[i][0]=1;
    }

    for (int i = 1; i < n+1; i++){
      for (int j = 1; j < am+1; j++){
        if(co[i-1] <= j){
            dp[i][j]=dp[i][j-co[i-1]]+dp[i-1][j];
        }else{
          dp[i][j]=dp[i-1][j];
        }
      }
    }
   return dp[n][am];

}

int main(){
    vector<int> coins={1,2,5};
    int amount=5;
    cout<<CoinChange(amount,coins);
    return 0;
}