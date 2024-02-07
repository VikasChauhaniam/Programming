#include<iostream>
#include<vector>

using namespace std;

void solution(vector<int>& arr,int& target,vector<string>& ans,string output, int sum, int indx){

    //baseCase
    if(sum == target){
        ans.push_back(output);
    }

    //SolveOneCase
    for(int i = indx; i<arr.size(); i++){

        if(sum+arr[i] <= target){
            solution(arr, target, ans, output+to_string(arr[i]), sum+arr[i], i);
        }
        
    }
}

int main(){

    vector<int> arr{2,3,4,7};
    int target = 7;
    vector<string> ans;
    string output = "";
    int sum = 0;
    solution(arr, target, ans, output, sum, 0);
    
    for(auto s : ans){
        cout << s << " ";
    }cout<< endl;

    return 0;
}