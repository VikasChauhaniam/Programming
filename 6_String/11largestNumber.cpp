#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compp(string a, string b){
    
    string str1 = a+b;
    string str2 = b+a;

    return str1>str2;
}

int main(){

    vector<int> nums{0, 0};

    vector<string> stringNumbers;
    string ans;

       for(auto n : nums){
           stringNumbers.push_back(to_string(n));
       }

       sort(stringNumbers.begin(), stringNumbers.end(), compp);

       for(int i=0; i<nums.size(); i++){
           ans += stringNumbers[i];
       }
       cout << ans;

    return 0;
}