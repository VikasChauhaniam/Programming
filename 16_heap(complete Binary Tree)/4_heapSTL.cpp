#include<iostream>
using namespace std;
#include<queue>

int main(){

    // priority_queue<int> pq;          //maxheap

    // pq.push(10);
    // pq.push(20);
    // pq.push(50);
    // pq.push(5);
    // pq.push(40);

    // cout<<pq.top()<<endl;

    // pq.pop();
    // cout<<pq.top()<<endl;


    //min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(20);
    pq.push(50);
    pq.push(5);
    pq.push(40);

    cout<<pq.top()<<endl;

    pq.pop();
    cout<<pq.top()<<endl;

    

    return 0;
}
