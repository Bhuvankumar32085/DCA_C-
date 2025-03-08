#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printItinerary(unordered_map<string,string>tickets){
   unordered_set<string>to;

   for(pair<string,string>ticket:tickets){
     to.insert(ticket.second);
   }

   string st="";

   for(pair<string,string>ticket:tickets){
     if(to.find(ticket.first)==to.end()){
        st=ticket.first;
     }
   }
    cout<<st<<"->";
   while (tickets.count(st)){
      cout<<tickets[st]<<"->";
      st=tickets[st];
   }
}

int main(){
    unordered_map<string,string>tickets;
    tickets["chennai"]="bengaluru";
    tickets["mumbai"]="delhi";
    tickets["goa"]="chennai";
    tickets["delhi"]="goa";
  printItinerary(tickets);
    return 0;
}