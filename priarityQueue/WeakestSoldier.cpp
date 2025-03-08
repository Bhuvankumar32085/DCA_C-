#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

 class row{
  public:
   int soldcount;
   int idx;
   row(int s,int i){
    this->soldcount=s;
    this->idx=i;
   }

   bool operator <(const row &obj)const{
    if(this->soldcount==this->soldcount){
        return this->idx > obj.idx;
    }
    return this->soldcount > obj.soldcount;
   }
 };

void connectNRopes(vector<vector<int>>matrix,int k){
   vector<row>rows;
   for (int i=0; i<matrix.size(); i++){
       int count=0;
      for (int j = 0; j<matrix[i].size() && matrix[i][j]==1; j++){
          count++;
      }
      rows.push_back(row(count,i));
    }
   priority_queue<row>pq(rows.begin(),rows.end());

  for (int i = 0; i < k; i++){
    cout<<"row "<<pq.top().idx<<endl;
    pq.pop();
  }
}

int main(){
    vector<vector<int>>matrix={{1,0,0,0},
                              {1,1,1,1},
                              {1,0,0,0},
                              {1,0,0,0}};
   connectNRopes(matrix,2);
   return 0;
}
