#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int ValidAnagram(string s,string t){
  unordered_map<char,int>m;
 
   if(s.size() != t.size()){
      return false;
   }
   
  for (int i = 0; i < s.size(); i++){
    if(m.count(s[i])){
        m[s[i]]++;
    }else{
        m[s[i]]=1;
    }
  }

  for (int i = 0; i < t.size(); i++){
    if(m.count(t[i])){
        m[t[i]]--;
        if(m[t[i]]==0){
            m.erase(t[i]);
        }
    }else{
        return false;
    }
  }
  if(m.size()==0){
    return true;
  }
}

int main(){
    string s="race";
    string t="care";
    cout<< ValidAnagram(s,t);
}