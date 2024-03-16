#include<iostream>
using namespace std;
#include<queue>
#include<math.h>

bool isHeap(int arr[], int size, int indx){
    if(indx >= ceil(size-1/2)){
        return true;
    }

    int leftindx = 2*indx + 1;
    int rightindx = 2*indx + 2;

    bool left = true;
    bool right = true;

    if(leftindx < size && arr[leftindx] > arr[indx]){
        left = false;
    }

    if(rightindx < size && arr[rightindx] > arr[indx]){
        right = false;
    }

    bool lefttree  = isHeap(arr, size, leftindx);
    bool righttree = isHeap(arr, size, rightindx);

    return left && right && lefttree && righttree;
}

int main(){

    int arr[] = {50, 40, 30, 11, 35, 9, 31};
    int size = 7;
    int indx = 0;

    bool is = isHeap(arr, size, indx);

    if(is){
        cout <<"is a heap"<<endl;
    }
    else{
        cout <<"is Not heap"<<endl;
    }

    return 0;
}