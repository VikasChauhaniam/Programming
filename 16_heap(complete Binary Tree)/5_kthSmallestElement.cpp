#include<iostream>
using namespace std;
#include<queue>

void Kth_smalllestELement(priority_queue<int> pq, int arr[], int &indx, int &size){

    for(int i = indx; i<size; i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout << "kth smallest element is: "<<pq.top()<<endl;
}

int main(){

    int arr[] = {2, 5, 6, 7, 3, 8, 12, 9};
    int size = 8;

    int smallestElement = 8; 
    int indx = smallestElement+1;

    priority_queue<int> pq;

    for(int i = 0; i<smallestElement; i++){
        pq.push(arr[i]);
    }

    Kth_smalllestELement(pq, arr, indx, size);


    return 0;
}