#include<iostream>
#include<vector>
using namespace std;

int Rodcutting(vector<int>price,vector<int>length,int rodlength){
    int n=length.size();
   vector<vector<int>> dp(n+1,vector<int>(rodlength+1,0));
   
    for (int i = 1; i < n+1; i++){
      for (int j = 1; j < rodlength+1; j++){
        if(length[i-1] <= j){
            dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
        }else{
          dp[i][j]=dp[i-1][j];
        }
      }
    }
   return dp[n][rodlength];

}

int main(){
    vector<int> price={1,5,8,9,10,17,17,20};
    vector<int> length={1,2,3,4,5,6,7,8};
    int rodlength=8;
    cout<<Rodcutting(price,length,rodlength);
    return 0;
}