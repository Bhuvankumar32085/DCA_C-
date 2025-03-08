#include<iostream>
#include<vector>
using namespace std;

class Heap{
   vector<int> v;
public:
    void push(int val){
        //step 1
       v.push_back(val);

        //fix heap
       int x = v.size()-1;//child idx
       int paridx=(x-1)/2;

       while (paridx >=0 && v[x]>v[paridx]){
        swap(v[x],v[paridx]);
        x=paridx;
        paridx=(x-1)/2;
       } 
    }
    
    void heapify(int i){
        if(i>=v.size()){
          return;
        }
      int l=2*i+1;
      int r=2*i+2;

      int maxidx=i;
      if(l < v.size() && v[l]>v[maxidx]){
        maxidx=l;
      }
      if(r < v.size() && v[r]>v[maxidx]){
        maxidx=r;
      }

      swap(v[i],v[maxidx]);
      if(maxidx != i){
        heapify(maxidx);
      }
    }

    void pop(){
       //step 1
       swap(v[0],v[v.size()-1]);
       //step 2
       v.pop_back();
       //step 3
       heapify(0);
    }

    int top(){
        return v[0];
    }

    bool empty(){
        return v.size()==0;
    }
};

int main(){
    Heap h;
    h.push(9);
    h.push(4);
    h.push(8);
    h.push(1);
    h.push(2);
    h.push(5);
    h.push(51);
    h.push(57);
    h.push(590);
    h.push(1);

 while (!h.empty()){
  cout<<h.top()<<" ";
  h.pop();
 }
    return 0;
}
