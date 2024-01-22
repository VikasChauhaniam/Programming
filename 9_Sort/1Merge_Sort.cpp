#include<iostream>
using namespace std;

void merge(int* arr,int s ,int e){

    int mid = (s+e)/2;

    int left_length = mid - s + 1;
    int right_length = e - mid;

    int* leftArray = new int[left_length];
    int* rightArray = new int[right_length];

    //copy in left array
    for(int i = 0; i < left_length; i++){
        leftArray[i] = arr[s+i];
    }

    //copy in right array
    for(int i = 0; i < right_length; i++){
        rightArray[i] = arr[mid+i+1];
    }

    //Merging
    int leftIndex = 0;
    int rightIndex = 0;
    int arrayIndex = s;

    while(leftIndex < left_length && rightIndex < right_length){

        if(leftArray[leftIndex] < rightArray[rightIndex]){
            arr[arrayIndex++] = leftArray[leftIndex++];
        }
        else{
            arr[arrayIndex++] = rightArray[rightIndex++];
        }
    }
    while(leftIndex < left_length){
        arr[arrayIndex++] = leftArray[leftIndex++];
    }
    while(rightIndex < right_length){
        arr[arrayIndex++] = rightArray[rightIndex++];
    }

    //delete new arrays

}

void  merge_Sort(int* arr,int s, int e){

    if(s>=e) return;

    int mid = (s+e)/2;

    merge_Sort(arr, s, mid);
    merge_Sort(arr, mid+1, e);

    merge(arr, s , e);

}

int main(){

    int arr[] = { 2,7,5,3,9,16,13,6};

    int n =  sizeof(arr)/sizeof(int);

    for(int i=0; i< n;i++){
        cout<< arr[i] << " ";
    }cout<<endl;

    merge_Sort(arr,0,n-1);

    for(int i=0; i< n;i++){
        cout<< arr[i] << " ";
    }
}