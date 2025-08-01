#include<iostream>
#include<vector>
using namespace std;

int LCS(string str1,string str2){
  int n=str1.size();
  int m=str2.size();
  int ans=0;
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for (int i = 1; i < n+1; i++){
    for (int j = 1; j < m+1; j++){
        if(str1[i-1]==str2[j-1]){
          dp[i][j]=dp[i-1][j-1]+1;
        }else{
          dp[i][j]=0;
        }
        ans=max(ans,dp[i][j]);
    }
   }
   return ans;
}

int main(){
    string str1="abcde";
    string str2="abgce";
     
    cout<<LCS(str1,str2);
}