#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int>s;
    
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(400);
    s.insert(500);


    s.erase(11);
   
    // if(s.find(100)!=s.end()){
    //     cout<<"key is exists";
    // }

    for(auto el:s){
        cout<<el<<" ";
    }
    
}