#include <iostream>
using namespace std;
#include <cstring>
int main(){


    int arr[5] = {0};

    

    // cout << "array data is "<< endl;
    // for(int i=0; i< 5; i++){
    //     cout << arr[i] << " ";
    // }

    memset(arr, 1, sizeof(arr));

    cout << "array data is "<< endl;
    for(int i=0; i< 5; i++){
        cout << arr[i]<< " ";
    }

}