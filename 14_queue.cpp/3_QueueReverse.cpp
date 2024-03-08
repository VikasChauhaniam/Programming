#include<iostream>
#include<queue>
using namespace std;

void  printQueue(queue<int> q){

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }cout<<endl;
}

void reverseQueue(queue<int> &q){
    //solve base
    if(q.empty()){
        return;
    }

    int temp = q.front();
    q.pop();

    //recursion
    reverseQueue(q);

    //trackback;
    q.push(temp);
}

int main(){

    queue<int> q;

    q.push(2);
    q.push(5);
    q.push(4);
    q.push(9);
    q.push(7);


    printQueue(q);

    reverseQueue(q);

    printQueue(q);
    
   

    return 0;
}