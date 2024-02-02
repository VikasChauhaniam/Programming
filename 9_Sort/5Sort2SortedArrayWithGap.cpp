#include<iostream>
#include<vector>

using namespace std;


void gapSort(vector<int> & arr1,vector<int> &  arr2){
    int n = arr1.size();
    int m = arr2.size();

    int total_lengtth =  n + m;
    int gap = (total_lengtth)/2 + (total_lengtth)%2;
    

    while(gap > 0){
        int i = 0;
        int j = gap;
        while(j<total_lengtth){

        if( (j < n) && (arr1[i] > arr1[j])){
            swap(arr1[i], arr1[j]);
        }
        else if( (i < n) && (j >=n) && (arr1[i] > arr2[j-n])){
            swap(arr1[i], arr2[j-n]);
        }
        else if( (i >= n) && (j >=n) && (arr1[i-n] > arr2[j-n])){
            swap(arr1[i-n], arr2[j-n]);
        }
        i++;
        j++;
        }
        gap = gap==1 ? 0 : (gap/2) + (gap%2);
    }
}

int main(){

    vector<int> arr1{1, 3, 5, 7};
    vector<int> arr2{4};

    gapSort(arr1, arr2);

    for(int i = 0; i<arr1.size(); i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;
    for(int i = 0; i<arr2.size(); i++){
        cout<<arr2[i]<<" ";
    }

    return 0;
}