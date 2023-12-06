//method1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return 0;
    }
};

//method2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(int i=0; i<nums.size(); i++){
            if(nums[nums[i]] == -1){
                return nums[i];
            }
           nums[nums[i]] = -1;
        }
        return -1;
    }
};


//method3
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        

        for(int i=0; i<nums.size(); i++){
            int indx = abs(nums[i]);

            if(nums[indx] < 0){
                return indx;
            }
            nums[indx] = -nums[indx];
        }
        return -1;
    }
};


//method4
while(true){
            if(nums[0] == nums[nums[0]]){
                return nums[0];
            }
            swap(nums[0],nums[nums[0]]);
        }
