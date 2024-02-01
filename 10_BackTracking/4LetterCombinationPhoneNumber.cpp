#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


void solve(unordered_map<int, string>& values,vector<string>& ans,string output,int indx,string& digits){

    //baseCase ---> if whole digit traversed

    if(indx >= digits.length()){
        //cout<< output<<endl;
        ans.push_back(output);
        return;
    }

    //solve 1case

    int digit = digits[indx] - '0';

    for(int i = 0; i<values[digit].length(); i++){
        solve(values, ans, output+values[digit][i], indx+1, digits);
    }

}




int main(){

    
    string digits = "234";

    int indx = 0;

    vector<string> ans;
    string output = "";

    unordered_map<int, string> values;
    values[2] = "abc";
    values[3] = "def";
    values[4] = "ghi";
    values[5] = "jkl";
    values[6] = "mno";
    values[7] = "pqrs";
    values[8] = "tuv";
    values[9] = "wxyz";

    solve(values, ans, output, indx, digits);



    
    return 0;
}