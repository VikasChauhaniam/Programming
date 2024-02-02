#include<iostream>
#include<algorithm>
using namespace std;

//METHOD 1
// int partition(int* arr,int s,int e){

//     // Chose piviot starting element
//     int count = 0;
//     int piviot_indx = s;

//     //count number of element less then piviot
//     for(int i = s+1; i<=e; i++){
//         if(arr[i] < arr[piviot_indx]){
//             count++;
//         }
//     }

//     //swap piviot element with the element where piviot supoose to go
//     swap(arr[s], arr[s + count]);
//     piviot_indx = s + count;

//     //move less element towards left and bigger element towards right
//     while(s<=e){
//         while(arr[s] <= arr[piviot_indx]){
//             s++;
//         }
//         while(arr[e] > arr[piviot_indx]){
//             e--;
//         }

//         if(s<e){
//             swap(arr[s], arr[e]);
//         }
//     }

//     return piviot_indx;
// }


//METHOD 2
int partition(int*arr, int s, int e){

    int piviot =  e;
     int j = s;
     int i = s-1;

     while(j < piviot){
        if(arr[j] < arr[piviot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
     }
     i++;
     swap(arr[i], arr[piviot]);

     return i;

}

void  quick_Sort(int* arr,int s, int e){

    if(s>=e) return;

    int pivot_indx = partition(arr, s, e);


    quick_Sort(arr, s, pivot_indx - 1);

    quick_Sort(arr, pivot_indx + 1, e);

}

int main(){

    int arr[] = { 2,7,5,3,9,16,13,6};

    int n =  sizeof(arr)/sizeof(int);

    for(int i=0; i< n;i++){
        cout<< arr[i] << " ";
    }cout<<endl;

    quick_Sort(arr,0,n-1);

    for(int i=0; i< n;i++){
        cout<< arr[i] << " ";
    }
}