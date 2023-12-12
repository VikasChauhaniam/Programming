#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bs(vector<int> arr, int i, int j,int find){
    
    

    while(i<=j){
        int mid = (i+j)/2;

        if(arr[mid] == find){
            return mid;
        }
        else if( arr[mid] > find){
            j = mid-1;
        }
        else{
            i = mid +1;
        }
    }
    return -1;
}

int exponentialSearch(vector<int> nums, int find){
    
    if(nums[0] == find){ return 0;}

    int i=1;
    int j=1;
    while(i<nums.size() && nums[i]<find){
        j=i+1;
        i = 2*i;
        
    }

    return bs(nums, j, min(i,(int)nums.size()), find);
}

int main(){

    vector<int> nums{1,4,7,10,14,18,20,22,27,30,33,38,39,40,42,46,47,49};

    int find;
    cout << "search element: ";
    cin >> find;
    cout << endl;
    int indx = exponentialSearch(nums , find);

    if(indx == -1){
        cout << "Element not found";
    }
    else{
        cout << "Elemement found at index : "<<indx;
    }

    return 0;
}