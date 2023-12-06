#include <iostream>
#include <vector>

using namespace std;

vector<int> intersectionVector(vector<int> arr1, vector<int> arr2){
    vector<int> arr3;

    for(int element1 : arr1){
        for(int element2 : arr2){

            if(element2 == element1){
                arr3.push_back(element2);
            }
        }
        
    }
    return arr3;
}

int main(){

vector<int> arr1{1, 2, 3, 4, 5, 6};
vector<int> arr2{2, 4, 1, 8};

vector<int> arr3 = intersectionVector(arr1, arr2);

for(int i : arr3){
    cout << i << "  ";
}
    return 0; 

}