#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        void addEdge(int u, int v, int wt, bool direction){
            if(direction){
                //single direction
                adjList[u].push_back(make_pair(v, wt));
            }
            else{
                //bi direction
                adjList[u].push_back(make_pair(v, wt));
                adjList[v].push_back(make_pair(u, wt));
            }
        }

        void printAdjList(){
            cout<<"--------------print adj list-------------"<<endl;
            for(auto u : adjList){
                cout << u.first << ": {";
                for(auto v : u.second){
                    cout <<"("<< v.first << "," <<v.second<< "), ";
                }
                cout<<"}"<<endl<<endl;
            }
        }
};        

int main(){

    Graph g;
    g.addEdge(0, 1, 5,  0);
    g.printAdjList();
    cout<<endl;

    g.addEdge(1, 2, 10, 0);
    g.printAdjList();
    cout<<endl;

    g.addEdge(1, 3, 15, 0);
    g.printAdjList();
    cout<<endl;

    g.addEdge(2, 3, 16, 0);
    g.printAdjList();
    cout<<endl;

    return 0;


}