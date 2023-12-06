#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void printfxn(vector<int> a){

    for(int i : a){
        cout << i << "  ";
    }
    cout << endl << endl;

}

void  majorityelement(vector<int> arr1){
    vector<int> arr2;

    for(int i=0; i<arr1.size(); i++){
        arr2[arr1[i]]++;
    }

    int max = INT_MIN;
    int element;
    for(int i=0; i<arr2.size(); i++){
        if(arr2[i] > INT_MIN){
            max = arr2[i];
            element = i;
        }
    }

    cout << "element: "<< element << " : " << max << " times";

}

int main(){

vector<int> arr1{1, 2, 3, 4, 5, 6, 5, 3, 2, 1, 2};

//int majority = 
majorityelement(arr1);

//cout << "majority element is: "<< majority ;



    return 0; 

}