#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

void fxn(vector<int>& nums,int i,int amount, int& maxi){

        if(i>=nums.size()){
           maxi = max(amount, maxi);
            return;
        }

        //exclude
        fxn(nums,i+1,amount, maxi);

        //include
       amount += nums[i];
        fxn(nums,i+2,amount, maxi);

        
    }

int main(){

    vector<int> nums{1, 2, 3, 5, 4};

    int amount = 0;
        int maxi = INT_MIN;
        fxn(nums,0,amount, maxi);
        //return maxi;
    cout<< maxi<<endl;

    return 0;
}