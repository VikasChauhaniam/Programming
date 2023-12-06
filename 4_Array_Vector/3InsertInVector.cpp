#include <iostream>
#include <vector>

using namespace std;


void printfunx(vector<int> a){

    for(int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }
}

int main(){

    int n ;

    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr(n, 2);

    printfunx(arr);

    cout << endl << "Enter element in aray: " << endl;
    for(int i=0; i<arr.size(); i++){
        cin >> arr[i];
    }

    printfunx(arr);

    return 0;
}
