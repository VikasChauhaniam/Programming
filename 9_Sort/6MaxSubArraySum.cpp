#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int maxSubArray(vector<int>& arr, int s, int e){

    if(s==e) return arr[s];

    int mid = s + ((e-s)>>1);

    int leftSum = maxSubArray(arr, s, mid);
    int rightSum = maxSubArray(arr, mid+1, e);

    int maxLeftArraySum = INT_MIN;
    int maxRightArraySum = INT_MIN;

    int leftborderSum = 0;
    int rightboarderSum = 0;

    for(int i = mid; i>=s; i--){
        leftborderSum += arr[i];

        if(leftborderSum > maxLeftArraySum) maxLeftArraySum = leftborderSum;
    }
    for(int i = mid+1; i<= e; i++){
        rightboarderSum += arr[i];

        if(rightboarderSum > maxRightArraySum) maxRightArraySum = rightboarderSum;
    }

    int crossBorderSum = maxLeftArraySum + maxRightArraySum;
    return max(crossBorderSum, max(leftSum, rightSum));

}

int main(){

    vector<int> arr{5,4,-1,7,8};

    int sum = maxSubArray(arr, 0, arr.size()-1);
    return sum;
    cout << "sum is: "<<sum << endl;

    return 0;
}