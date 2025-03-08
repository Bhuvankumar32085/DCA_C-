#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;


int EditDistence(string t,string p){
   int n=t.size();
   int m=p.size();
   vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
   dp[0][0]=true;
    for (int i = 0; i < m+1; i++){
      if(p[i-1]=='*'){
         dp[0][i]=dp[0][i-1];
      }else{//?
         dp[0][i]=false;
      }
    }

    for (int i = 1; i <n+1; i++){
      for (int j = 1; j < m+1; j++){
       
      }
    }
    
    return dp[n][m];
}

int main(){
  string str1="abc";
  string str2="ac";
  cout<<EditDistence(str1, str2);

  return 0;
}