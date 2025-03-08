#include<iostream>
#include<list>
#include<vector>
using namespace std;
// uni diraction un weighted
class Graph{
    int V;
    list<int>*l;
public:
    Graph(int val){
        this->V=val;
        l=new list<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    void print(){
        for (int u=0; u<V; u++){
            list<int>neighbors=l[u];
            cout<<u<<" : ";
            for(int V : neighbors){
               cout<<V<<" ";
            }
            cout<<endl;
        } 
    }


};

int main(){
   Graph graph(4); 
    graph.addEdge(0,1);
    graph.addEdge(1,0);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.print();
  return 0;
}