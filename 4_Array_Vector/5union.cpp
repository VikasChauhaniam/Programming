#include <iostream>
#include <vector>

using namespace std;

void printfxn(vector<int> a){

    for(int i : a){
        cout << i << "  ";
    }
    cout << endl << endl;

}

vector<int> unionVector(vector<int> arr1, vector<int> arr2){
    

    for(int element1 : arr1){

        int count = 0;
        bool found = false;
        for(int element2 : arr2){
            count++;
            
            if(element2 == element1){
                found = true;
            }

            if(!found && (count == arr2.size())){
                //cout << "count: "<<count<<" arr2.size: "<<arr2.size()<<endl;
                arr2.push_back(element1);
                //printfxn(arr2);
            }
        }
    }
    return arr2;
}

int main(){

vector<int> arr1{1, 2, 3, 4, 5, 6};
vector<int> arr2{2, 4, 1, 8};

vector<int> arr3 = unionVector(arr1, arr2);

printfxn(arr3);

    return 0; 

}