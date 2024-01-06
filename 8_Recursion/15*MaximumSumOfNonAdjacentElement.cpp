#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

void solve( vector<int>& arr,int indx,int sum,int& maxi){

    if(indx >= arr.size()){

       maxi = max(sum, maxi);
       return;
    }      

    //include
    solve(arr, indx+2, sum+arr[indx], maxi);
    //exclude
    solve(arr, indx+1, sum, maxi);
}

int main(){

    vector<int> arr{1, 2, 3, 5, 4};

    int sum =0;
    int maxi = INT_MIN;
    int indx = 0;

    solve(arr, indx, sum, maxi);
    cout<< maxi<<endl;

    return 0;
}