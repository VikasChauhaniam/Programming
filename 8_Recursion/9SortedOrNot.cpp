#include<iostream>

using namespace std;

bool sortedOrNot(int* arr, int size, int i){

    if(i>=size){
        return true;
    }

    if(arr[i+1] < arr[i]){
        return false;
    }

    return sortedOrNot(arr, size, ++i);
    

}

int main(){

    int arr[] = {5, 7, 9,23, 4, 46, 67, 99};
    int size = 8;
    int i= 0;
   bool x = sortedOrNot(arr,size, i);

   if(x){
    cout << "Sorted";
   }
   else{
    cout << "not sorted";
   }

    return 0;
}