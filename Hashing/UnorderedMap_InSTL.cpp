#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,string>m;
    
    m[100]="bhuvam";
    m[120]="aryan";
    m[130]="mohit";
    m[140]="rohit";
    m[150]="sohit";
    m[160]="chotu";


    m.erase(150);
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    
    
}