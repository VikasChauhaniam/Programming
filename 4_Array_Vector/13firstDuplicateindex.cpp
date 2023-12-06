#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void firstDuplicateindex( vector<int>nums){

    unordered_map<int, int> hash;

    for(int i=0; i<nums.size(); i++){
        hash[nums[i]]++;
    }

    for(int i=0; i<nums.size(); i++){

        if(hash[nums[i]] > 1){

            cout << "duplicate element is : " << nums[i];
            cout << endl << "index : " << i;
            break;
            
        }
    }
}

int main(){

    vector<int>nums{1, 42, 3, 3, 4};

    firstDuplicateindex(nums); 
    return 0;
}