#include<iostream>
#include<vector>
using namespace std;

int Unboundedknapsack(vector<int>val,vector<int>wt,int w,int n){
   vector<vector<int>> dp(n+1,vector<int>(w+1,0));
   
   for (int i = 1; i < n+1; i++){
     for (int j = 1; j < w+1; j++){
        int itemwt=wt[i-1];
        int itemval=val[i-1];

        if(itemwt<=j){
            dp[i][j]=max(itemval+dp[i][j-itemwt],dp[i-1][j]);
        }else{
          dp[i][j]=dp[i-1][j];
        }
     }
   }
   return dp[n][w];

}

int main(){
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    int w=7;
    int n=5;

    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    cout<<Unboundedknapsack(val,wt,w,n);
    return 0;
}