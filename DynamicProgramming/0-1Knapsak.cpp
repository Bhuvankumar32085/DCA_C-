#include<iostream>
#include<vector>
using namespace std;

int KnapsackREc(vector<int>val,vector<int>wt,int w,int n){
     if(n==0 || w==0){
        return 0;
     }

    int itemwt=wt[n-1];
    int itemval=val[n-1];
     
    if(itemwt <=w){
      //include
       int ans1=KnapsackREc(val ,wt,w-itemwt,n-1)+itemval;
      //exclude
       int ans2=KnapsackREc(val,wt,w,n-1);
       return max(ans1,ans2);
    }else{
      //exclude
      return  KnapsackREc(val,wt,w,n-1);
    }
}

int KnapsackMEM(vector<int>val,vector<int>wt,int w,int n,vector<vector<int>> &dp){
     if(n==0 || w==0){
        return 0;
     }
    if(dp[n][w]!=-1){
      return dp[n][w];
    }

    int itemwt=wt[n-1];
    int itemval=val[n-1];
     
    if(itemwt <=w){
      //include
       int ans1=KnapsackMEM(val ,wt,w-itemwt,n-1,dp)+itemval;
      //exclude
       int ans2=KnapsackMEM(val,wt,w,n-1,dp);
       dp[n][w]= max(ans1,ans2);
    }else{
      //exclude
      dp[n][w]=  KnapsackMEM(val,wt,w,n-1,dp);
    }
    return dp[n][w];
}

int KnapsackTAB(vector<int>val,vector<int>wt,int w,int n){
   vector<vector<int>> dp(n+1,vector<int>(w+1,0));
   
   for (int i = 1; i < n+1; i++){
     for (int j = 1; j < w+1; j++){
        int itemwt=wt[i-1];
        int itemval=val[i-1];

        if(itemwt<=j){
            dp[i][j]=max(itemval+dp[i-1][j-itemwt],dp[i-1][j]);
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
    cout<<KnapsackTAB(val,wt,w,n);
    return 0;
}