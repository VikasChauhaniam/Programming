#include <iostream>
using namespace std;
#include <vector>

int main(){

    vector<int> arr{1,4,6,9,12,15,20,7,5,2};
    int start = 0;
    int end = arr.size()-1;
    int mid = (start+end)/2;
    int found = 0;
    int count = 0;
    while(start <= end){
       // cout << "Start:"<<start<<" mid:"<<mid<<" End:"<<end<<endl;
       // cout << "(arr[mid] > arr[mid-1]  :  "<<(arr[mid] > arr[mid-1])<<endl;
       // cout << "arr[mid] > arr[mid+1]  :  "<<(arr[mid] > arr[mid+1])<<endl;

        if((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])){
            found = 1;
            break;
        } 
        else if(arr[mid] > arr[mid-1]){
            start = mid;
        }
        else{
            end = mid;
        }   
            
        mid = (start + end)/2;
        count++;
        if(count == 5){
            break;
        }
        
    }

    if(found){
        cout << "mountain peak at index : "<< mid;
    }
    else{
        cout << "peak not found : ";
    }


    return 0;
}