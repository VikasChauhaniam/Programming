#include<iostream>
#include<vector>

using namespace std;

void merge( vector<int>&arr, int s,int mid,int e){

    
   int totalLength = e-s+1;
   int gap = (totalLength/2) + (totalLength%2);  //ceil
    
    

    while(gap>0){
        int i = s;
        int j = i + gap;

        while(j<=e){
             if(arr[j] < arr[i]){
                  swap(arr[i], arr[j]);
             }
             i++;
             j++;
        }
       //cout<<gap<<" - "<<gap/2<<" - "<<gap%2<<endl;
        gap = gap ==1 ? 0: (gap/2) + (gap%2);
        // cout<<gap<<" - "<<gap/2<<" - "<<gap%2<<endl<<endl;
    }
}

void mergeSort( vector<int>& arr, int s, int e){

if(s>=e) return;

int mid = (s+e)/2;

mergeSort(arr,  s, mid);
mergeSort(arr, mid+1, e);

merge(arr,  s, mid, e);

}

int main(){

    vector<int> arr{3, 4, 1, 2, 6, 8};
    
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
    mergeSort(arr, 0, arr.size()-1);

    for(auto i : arr){
        cout<<i<<" ";
    }


    return 0;
}