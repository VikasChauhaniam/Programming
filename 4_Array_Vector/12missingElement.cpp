#include <iostream>
#include <vector>

using namespace std;

//method1===========================================================
// void findmissing(vector<int>nums){

//     for(int i=0; i<nums.size(); i++){
//             int indx = abs(nums[i]);
//             if(nums[indx-1] > 0){
//                 nums[indx-1] = -nums[indx-1];
//             }
            
//         }
//     for(int i=0; i<nums.size(); i++){
//             if(nums[i] > 0){
//                 cout << "element not present : " <<i+1<<endl;
//             }
//             //cout << "element not present : " <<nums[i]<<endl;
//         }    
// }

//method2============================================================

int main(){

    vector<int>nums{1, 4, 3, 3, 4};

    findmissing(nums); 
    return 0;
}