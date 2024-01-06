#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int  sol(vector<int>& arr,int targetSum, int output){

    if(targetSum==output){
      return 0;
    }
    if(targetSum < output){
        return INT_MAX;
    }
    int mini = INT_MAX;
    

    for(int i=0; i<arr.size(); i++){
        
     int ans = sol(arr,targetSum - arr[i], output+arr[i]);

     if(ans!= INT_MAX)
       output += arr[i];
       mini = min(ans+1, mini);
    }

    return mini;         

}

int main(){

    vector<int> arr{1,2,3};

    int target = 7;
    int output = 0;

   int count = sol(arr, target, output);

   cout<<"ans is :"<<count;

    return 0;
}