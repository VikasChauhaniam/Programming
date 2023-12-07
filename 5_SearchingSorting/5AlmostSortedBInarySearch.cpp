#include <iostream>
using namespace std;
#include <vector>

int main(){

    vector<int> arr{1,7,4,12, 19,16,26, 21,31,29,34,37,45,40,49,50,58,51,62};
    int start = 0;
    int end = arr.size()-1;
    int mid = (start+end)/2;
    int found = 0;
    int find = 30;

    int count = 0;

    while(start <= end){
        count++;
        //cout << "Start:"<<start<<" mid:"<<mid<<" End:"<<end<<endl;
        if(arr[mid] == find || (arr[mid+1]<= arr.size() && arr[mid+1] == find) || (arr[mid-1]>=0 && arr[mid-1] == find)){
            found = 1;
            break;
        }
        else if(arr[mid] > find){
            end = mid-2;
           // cout << "else if"<<endl;
        }
        else{
            start = mid + 2;
           // cout << "else"<<endl;
        }
        mid = (start+end)/2;
        
        
    }

    if(found){
        cout << "Element found : ";
    }
    else{
        cout << "Element not found : ";
    }


    return 0;
}