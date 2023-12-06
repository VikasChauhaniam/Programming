#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int> arr){
    
    int start = 0;
    int end = arr.size()-1;
    int superend = arr.size()-1;

    int i = 0;

    while(start<end){
        if(arr[i]==0){
            i++;
            start++;
        }
        else{
            swap(arr[i],arr[end]);
            end--;
        }
    }
    while(start<superend){
        if(arr[i]==1){
            i++;
            start++;
        }
        else{
            swap(arr[i],arr[superend]);
            superend--;
        }
    }

    return arr;
}

int main(){

    vector<int> arr{1, 0,0 ,2, 1, 2, 0, 2, 1, 0};

    vector<int> arr1 = sort(arr);

    for(auto element : arr1){
        cout << element << " "; 
    }

    return 0;
}