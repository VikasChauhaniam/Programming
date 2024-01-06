#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int  sol(vector<int>& arr,int targetSum){

    if(targetSum==0){
      return 0;
    }
    if(targetSum<0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    

    for(int i=0; i<arr.size(); i++){
     int ans = sol(arr,targetSum - arr[i]);

     if(ans!= INT_MAX)
       mini = min(ans+1, mini);
    }

    return mini;         

}

int main(){

    vector<int> arr{1,2,3};

    int targetSum = 3;

   int count = sol(arr, targetSum);

   cout<<"ans is :"<<count;

    return 0;
}