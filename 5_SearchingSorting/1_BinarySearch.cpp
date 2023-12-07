#include <iostream>
using namespace std;
#include <vector>

int main(){

    vector<int> arr{1,4,7,12, 16,19,21, 26,29,31,34,37,40,45,49,50,51,58,62};
    int start = 0;
    int end = arr.size()-1;
    int mid = (start+end)/2;
    int found = 0;
    int find = 62;

    int count = 0;
    while(start <= end){
        count++;
        //cout << "Start:"<<start<<" mid:"<<mid<<" End:"<<end<<endl;
        if(arr[mid] == find){
            found = 1;
            break;
        }
        else if(arr[mid] > find){
            end = mid-1;
           // cout << "else if"<<endl;
        }
        else{
            start = mid + 1;
           // cout << "else"<<endl;
        }
        mid = (start+end)/2;
        
        
    }

    if(found){
        cout << "Element found at index : "<< mid;
    }
    else{
        cout << "Element not found : ";
    }


    return 0;
}