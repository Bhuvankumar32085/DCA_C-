#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class car{
 public:
  int idx;
  int distSq;

  car(int Idx,int distsq){
    this->idx=Idx;
    this->distSq=distsq;
  }

  bool operator<(const car &obj)const{
    return this->distSq > obj.distSq;
  }
};

void nearbyCae(vector<pair<int,int>>pos,int k){
  vector<car>cars;

  for (int i = 0; i < pos.size(); i++){
    int distSq= (pos[i].first*pos[i].first)
              +(pos[i].second*pos[i].second);

    cars.push_back(car(i,distSq));     
  }

  priority_queue<car>pq(cars.begin(),cars.end());//0(n)
  
//   for (int i = 0; i < cars.size(); i++){
//     pq.push(cars[i]);
//   }
//es se 0(nlogn) time lage ga es liye ye 
// ye hum nahi kar te
     for (int i = 0; i < k; i++){
       cout<<"car "<<pq.top().idx<<endl;
       pq.pop();
    }
}

int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int k=2; 
    //k=2 matlab nearest 2 car
    nearbyCae(pos,k);
    return 0;
}