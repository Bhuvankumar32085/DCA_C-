#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,string>m;
    m[1]="bhuvan";
    m[2]="chotu";
    m[3]="krishna";
for(auto ti:m){
 cout<<"key no="<<ti.first<<"  value is="<<ti.second<<endl;
}
}

