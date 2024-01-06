#include<iostream>
#include<limits.h>

using namespace std;


void findMax(int* arr,int size,int indx,int& max){

    if(indx>=size){
        return;
    }
    if(arr[indx] > max){
        max = arr[indx];
    }

    findMax(arr, size, indx+1, max);
}

void findMin(int* arr,int size,int indx,int& min){

    if(indx>=size){
        return;
    }
    if(arr[indx] < min){
        min = arr[indx];
    }

    findMin(arr, size, indx+1, min);
}

int main(){

    int min = INT_MAX;
    int max = INT_MIN;

    int arr[] = {3, 55, 2, 34, 35, 74, 43, 98,75, 86};

    int size = 10;

    int indx = 0;

    findMax(arr, size, indx, max);

    cout <<"max value in array is : "<<max<<endl;

    findMin(arr, size, indx, min);

    cout <<"min value in array is : "<<min<<endl;

    return 0;
}