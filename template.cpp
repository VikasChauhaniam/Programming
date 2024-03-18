#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>

template<typename T>

class Graph{
    public:
        unordered_map<T, list<pair<T, int>>> adjList;

        void addEdge(T u, T v, int wt, bool direction){
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

    Graph<char> g;                       // it means T is integer
    g.addEdge('a', 'b', 5,  0);
    g.printAdjList();
    cout<<endl;

    g.addEdge('c', 'd', 10, 0);
    g.printAdjList();
    cout<<endl;

    g.addEdge('c', 'e', 15, 0);
    g.printAdjList();
    cout<<endl;

    g.addEdge('a', 'e', 16, 0);
    g.printAdjList();
    cout<<endl;

    return 0;


}