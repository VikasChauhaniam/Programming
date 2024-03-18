#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>

class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction){
            if(direction){
                //single direction
                adjList[u].push_back(v);
            }
            else{
                //bi direction
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void printAdjList(){
            cout<<"--------------print adj list-------------"<<endl;
            for(auto u : adjList){
                cout << u.first << ": {";
                for(auto v : u.second){
                    cout << v << ",";
                }
                cout<<"}"<<endl<<endl;
            }
        }
};        

int main(){

    Graph g;
    g.addEdge(0, 1, 1);
    g.printAdjList();
    cout<<endl;

    g.addEdge(1, 2, 1);
    g.printAdjList();
    cout<<endl;

    g.addEdge(1, 3, 0);
    g.printAdjList();
    cout<<endl;

    g.addEdge(2, 3, 0);
    g.printAdjList();
    cout<<endl;

    return 0;
}