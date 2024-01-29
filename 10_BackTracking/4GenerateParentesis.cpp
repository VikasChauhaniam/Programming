#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>& output,string s,int leftP,int rightP){

    //base Case
    if(leftP ==0 && rightP ==0){
        output.push_back(s);
        
        //cout<< s<< endl;
    }

    //Solve one
    //add left bracket only
    if(leftP > 0){
        s.push_back('(');
        solve(output, s, leftP-1, rightP);
        //backtrack
        s.pop_back();
    }

    //add left and right both.
    if(leftP < rightP)
    {


        s.push_back(')');
        solve(output, s, leftP, rightP-1);

        //backtrack
        s.pop_back();
    }
}
int main(){

    int leftP = 3;
    int rightP = 3;
    string s = "";
    vector<string> output;
    solve(output, s, leftP, rightP);

    
    for(auto y : output){
            for(auto z : y){
                cout<<z<<"";
            }
            cout<<endl;
        }
    
    return 0;
}