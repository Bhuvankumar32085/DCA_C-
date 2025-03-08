#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

void majorityelement(vector<int> num){
  unordered_map<int, int> m;

  for (int i = 0; i < num.size(); i++){
   if(m.count(num[i])){
      m[num[i]]++;
   }else{
      m[num[i]] = 1;
   }
  }
  
  for (pair<int, int> p : m){
    if(p.second > num.size()/3){
      cout<<p.first;
    }
  }
}

int main(){
  vector<int>nums={1,3,2,5,1,3,1,5,1};
  vector<int>nums2={1,2};
  majorityelement(nums);
  
  return 0;
}