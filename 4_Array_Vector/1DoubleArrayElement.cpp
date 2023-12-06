#include <iostream>
using namespace std;

int main(){

    int index = 5;
    int arr[index];

    cout << "Entered data is "<< endl;
    for(int i=0; i< index; i++){
        cin >> arr[i];
    }

    cout << "array data is "<< endl;
    for(int i=0; i< index; i++){
        cout << arr[i]*2 << " ";
    }

}