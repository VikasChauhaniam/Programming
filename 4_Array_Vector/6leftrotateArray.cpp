#include <iostream>
#include <vector>

using namespace std;

void printfxn(vector<int> a){

    for(int i : a){
        cout << i << "  ";
    }
    cout << endl << endl;

}

vector<int> leftrotate(vector<int> arr1, int ibit){
    vector<int> arr2;


    for(int i=ibit; i<arr1.size(); i++){
        arr2.push_back(arr1[i]);
    }

    for(int i=0; i<ibit; i++){
        arr2.push_back(arr1[i]);
    }
    
    return arr2;
}

int main(){

vector<int> arr1{1, 2, 3, 4, 5, 6};

int ibit;

cout << "rotate by : ";
cin >> ibit;

vector<int> arr2 = leftrotate(arr1, ibit);

printfxn(arr2);

    return 0; 

}